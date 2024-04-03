#include <winbgim.h> 
#include <iostream>
#include <fstream>
using namespace std;
#include "define.h"
#include "xuli.h"
#include "deletememory.h"
#include "maybay.h"
#include "chuyenbay.h"



/////////////////////////////////////// MAIN /////////////////////////////



int main(int argc, char *argv[])
{
	atexit(DeleteMemory);
	
	
	
    unsigned short int **mapID = new unsigned short int *[WD_HEIGHT];
	for(int i=0;i<= WD_HEIGHT;i++)
	 	mapID[i]= new unsigned short int[WD_WIDTH];
	 	
	 	
	resetMapID(mapID);


	
	danhsachmaybay dsmb;

	Open_file_MB(dsmb);

	Save_file_MB(dsmb);
	
	PT_MapID = mapID; 
	PT_MB= dsmb.data;

	
	initwindow(WD_WIDTH,WD_HEIGHT);		
	setbkcolor(WHITE);					
   	cleardevice();
	setcolor(BLACK);
	setfillstyle(1,WHITE);	
	bar(0,0,WD_WIDTH,WD_HEIGHT);		
	setbkcolor(GRAY);
	settextstyle(0, 0, 2);
    	
    vemenu(mapID);
    
 	int x,y;
	int id=0;
	int idnext=0;
	while(true){
		
		id=0;
		cout<<"=========";
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			id = mapID[y][x];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		
		
		place:
		switch(id){
			case ID_MAYBAY:
				cout<< ID_MAYBAY;
				
				resetMH(mapID);
				taoButton(0,0,100,250,175,mapID,WHITE,BLACK,WHITE,"MAY BAY");
				manhinhmaybay(dsmb,mapID,idnext,false);
				
				veKhungDSMB(mapID);
				taoButton(ID_MAYBAY,0,100,250,175,mapID,LIGHTGREEN,BLACK,LIGHTGREEN,"MAY BAY");
			
			    id= idnext;
			    
			    goto place;
				break;
				
			case ID_CHUYENBAY:
				cout<< ID_CHUYENBAY;
				resetMH(mapID);
				taoButton(0,0,225,250,300,mapID,WHITE,BLACK,WHITE,"CHUYEN BAY");

				taoButton(ID_CHUYENBAY,0,225,250,300,mapID,LIGHTGREEN,BLACK,LIGHTGREEN,"CHUYEN BAY");
				id= idnext;
					
				break;
			case ID_VE:
				resetMH(mapID);
				taoButton(0,0,350,250,425,mapID,WHITE,BLACK,WHITE,"VE");
				taoButton(ID_VE,0,350,250,425,mapID,LIGHTGREEN,BLACK,LIGHTGREEN,"VE");
				id= idnext;
				goto place;
				break;
			 case ID_THONGKE:
				resetMH(mapID);
				taoButton(0,0,475,250,550,mapID,WHITE,BLACK,WHITE,"THONG KE");
				taoButton(ID_THONGKE,0,475,250,550,mapID,LIGHTGREEN,BLACK,LIGHTGREEN,"THONG KE");
				id= idnext;
			   	goto place;			
				break;
			case ID_EXIT:
				taoButton(0,0,600,250,675,mapID,WHITE,BLACK,RED,"THOAT");
				if( MessageBox(NULL,"\n   [ Xac Nhan Thoat Chuong Trinh]   \n","THONG BAO",MB_ICONWARNING|MB_OKCANCEL) == IDOK){
	        	//						 DeleteMemory();
					return 0;
					}	
				else{
					taoButton(ID_EXIT,0,600,250,675,mapID,LIGHTGREEN,BLACK,LIGHTGREEN,"THOAT");
					resetMH(mapID);
				}
				break;	 
			}
		delay(100);
		}
	
	while(!kbhit()) delay(1);		// pause screen	
	return 0;
}

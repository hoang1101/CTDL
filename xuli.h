#include "define.h"
#include <iostream>
#include <fstream>
#include "maybay.h"
#include "chuyenbay.h"
#include "chuanhoadulieu.h"
using namespace std;

#pragma once



void setID(int id,int x1,int y1, int x2,int y2,unsigned short int ** mapID){
	
	for(int i=y1 ; i<=y2 ; i++)
		for(int j=x1; j <= x2; j++)
			mapID[i][j] = id ;
		
}



void resetMH(unsigned short int **mapID){
	
		setID(0,250,0,WD_WIDTH,WD_HEIGHT,mapID);
		setfillstyle(1,WHITE);	
		bar(250,0,WD_WIDTH,WD_HEIGHT);
}

void resetmb(maybay &mb){
	
		mb.sohieumaybay[0]='\0';
		mb.loaimaybay[0]='\0';
		mb.soChuyenDaBay=0;
		mb.soday=0;
		mb.sodong=0;
}

void resetcb(chuyenbay &cb){
	
			cb.MaCB[0]='\0';
			cb.sanbayden[0]='\0';
			cb.sohieumaybay[0]='\0';
			cb.dsve=0;
			cb.sove=0;
//			cb.mytime = Time_now();
			
}

void resetthanhchucnang(unsigned short int **mapID){
	
		setID(0,350,500,1150,550,mapID);
		setfillstyle(1,WHITE);	
		bar(305,505,1145,545);
		
}

void resetkhungds(unsigned short int **mapID){
	
		setID(0,250,0,1350,500,mapID);
		setfillstyle(1,WHITE);	
		bar(251,0,1352,499);
			
}



void taoButton(int id, int x1, int y1, int x2, int y2, unsigned short int ** mapID, int mauVien, int mauText , int mauBG , char *text){
	
		setcolor(mauVien);
		setfillstyle(1, mauBG);
		bar(x1, y1, x2, y2);
		rectangle(x1, y1, x2, y2);
		
		setcolor(mauText);
		setbkcolor(mauBG);
		outtextxy(x1+(x2-x1-textwidth(text))/2,y1+(y2-y1-textheight(text))/2, text);
		
		setID(id,x1,y1,x2,y2,mapID);
	
}

void taoEditText(int id, int x1, int y1, int x2, int y2, unsigned short int **mapID, int mauVien, int mauBG){
	
		setcolor(mauVien);
		setfillstyle(1, mauBG);
		bar(x1, y1, x2, y2);
		rectangle(x1, y1, x2, y2);
		
		setID(id,x1,y1,x2,y2,mapID);
	
}

void taoLable(int x1, int y1, int x2, int y2, int mauVien,int mauText, int mauBG, char* text){
	
		setcolor(mauVien);
		setfillstyle(1, mauBG);
		bar(x1, y1, x2, y2);
		rectangle(x1, y1, x2, y2);
		
		setcolor(mauText);
		setbkcolor(mauBG);
		outtextxy(x1+(x2-x1-textwidth(text))/2,y1+(y2-y1-textheight(text))/2, text);	
}

void vemenu( unsigned short int **mapID){
		setfillstyle(1,GRAY);
		bar(0,0,250,770);
		settextstyle(10, 0, 4);
		outtextxy(125-textwidth("MENU")/2,25,"MENU");
		settextstyle(0, 0, 2);
		taoButton(ID_MAYBAY,0,100,250,175,mapID,LIGHTGREEN,BLACK,LIGHTGREEN,"MAY BAY");
		taoButton(ID_CHUYENBAY,0,225,250,300,mapID,LIGHTGREEN,BLACK,LIGHTGREEN,"CHUYEN BAY");
		taoButton(ID_VE,0,350,250,425,mapID,LIGHTGREEN,BLACK,LIGHTGREEN,"VE");
		taoButton(ID_THONGKE,0,475,250,550,mapID,LIGHTGREEN,BLACK,LIGHTGREEN,"THONG KE");
		taoButton(ID_EXIT,0,600,250,675,mapID,LIGHTGREEN,BLACK,LIGHTGREEN,"THOAT");

}







//////////////////////////////// MAY BAY //////////////////////////////////////////

bool checkmb(maybay &mb){
	
	if(strlen(mb.sohieumaybay) == 0)  {
	    MessageBox(NULL,"So Hieu May Bay Khong Duoc De Trong","THONG BAO",MB_ICONWARNING|MB_OK);
		 return false;
	}
	if(mb.soday*mb.sodong < 20 ) {
		
		 MessageBox(NULL,"So Cho May Bay Toi Thieu La 20 (>= 20))","THONG BAO",MB_ICONWARNING|MB_OK);
		 return false ;
	}
	if(strlen(mb.loaimaybay) == 0) {
		 MessageBox(NULL,"Loai May Bay Khong Duoc De Trong","THONG BAO",MB_ICONWARNING|MB_OK);
		 return false;
	}
	return true;
}

void veKhungDSMB(unsigned short int **mapID ){
		settextstyle(0, 0, 2);
		setcolor(BLACK);
		rectangle(350,100,1300,430);
		line(350,130,1300,130);
		line(350+4*16,100,350+4*16,130);
		line(350+20*16,100,350+20*16,130);
		line(350+40*16,100,350+40*16,130);
		line(350+50*16,100,350+50*16,130);
	
		setbkcolor(WHITE);
		settextstyle(8,0,0);
		setusercharsize(1,2,1,2);
		outtextxy(350+2*16-textwidth("STT")/2,110,"STT");
		outtextxy(350+12*16-textwidth("SoHieuMayBay")/2,110,"SoHieuMayBay");
		outtextxy(350+30*16-textwidth("Loai May Bay")/2,110,"Loai May Bay");
		outtextxy(350+45*16-textwidth("So Dong")/2,110,"So Dong");
		outtextxy(350+50*16+(1300-350-50*16)/2-textwidth("So Day")/2,110,"So Day");
	
}

void taodongdsmb(int stt, int x, int y,int x1,int y1,maybay &mb,bool isclick,unsigned short int **mapID){
    
		setcolor(BLACK);
		settextstyle(8, 0, 0);
		setusercharsize(1,2,1,2);
		line(x,y1,x1,y1);
		line(x+4*16,y,x+4*16,y1);
		line(x+20*16,y,x+20*16,y1);
		line(x+40*16,y,x+40*16,y1);
		line(x+50*16,y,x+50*16,y1);
		
		if(isclick)
			setbkcolor(RED);
		else 
			setbkcolor(WHITE);
		outtextxy(x+2*16-textwidth(toChars(stt))/2,y+10,toChars(stt));
		outtextxy(x+12*16-textwidth(mb.sohieumaybay)/2,y+10,mb.sohieumaybay);
		outtextxy(x+30*16-textwidth(mb.loaimaybay)/2,y+10,mb.loaimaybay);
		outtextxy(x+45*16-textwidth(toChars(mb.sodong))/2,y+10,toChars(mb.sodong));
		outtextxy(x+50*16+(1300-x-50*16)/2-textwidth(toChars(mb.soday))/2,y+10,toChars(mb.soday));
		settextstyle(0, 0, 2);	

}


void clickmb(maybay &mb,int vitri,unsigned short int **mapID){

		setfillstyle(1,RED);
        bar(350,130+(vitri-1)%10*30,1300,160+(vitri-1)%10*30);
        rectangle(350,130+(vitri-1)%10*30,1300,160+(vitri-1)%10*30);
        taodongdsmb(vitri,350,130+(vitri-1)%10*30,1300,160+(vitri-1)%10*30,mb,true,mapID);
        setfillstyle(1,DARKGRAY);
    	bar(501,576,900,625);
		bar(1151,576,1280,625);
		bar(571,676,900,725);
		bar(1151,676,1280,725);
		setbkcolor(DARKGRAY);
    	outtextxy(505,590,mb.sohieumaybay);
    	outtextxy(1155,590,toChars(mb.soday));
    	outtextxy(575,690,mb.loaimaybay);
    	outtextxy(1155,690,toChars(mb.sodong));
	        
}

void unclickmb(maybay &mb,int vitri,unsigned short int **mapID){

		setfillstyle(1,WHITE);
        bar(350,130+(vitri-1)%10*30,1300,160+(vitri-1)%10*30);
        rectangle(350,130+(vitri-1)%10*30,1300,160+(vitri-1)%10*30);
        taodongdsmb(vitri,350,130+(vitri-1)%10*30,1300,160+(vitri-1)%10*30,mb,false,mapID);
        setfillstyle(1,DARKGRAY);
    	bar(501,576,900,625);
		bar(1151,576,1280,625);
		bar(571,676,900,725);
		bar(1151,676,1280,725);
}


void veKhungCongCuMB(unsigned short int **mapID ){

		setcolor(BLACK);
		taoLable(650,20,1000,70,BLACK,BLACK,GRAY,"DANH SACH MAY BAY");
		rectangle(300,500,1350,750);
		line(300,550,1350,550);
		taoButton(ADD_MB,670,510,740,540,mapID,BLACK,BLACK,LIGHTGREEN,"THEM");
	    taoButton(DELETE_MB,790,510,860,540,mapID,BLACK,BLACK,LIGHTGREEN,"XOA");
	    taoButton(EDIT_MB,910,510,980,540,mapID,BLACK,BLACK,LIGHTGREEN,"SUA");
	    
	    taoLable(370,575,500,625,BLACK,BLACK,GRAY,"SHMB");
	    taoEditText(0,500,575,900,625,mapID,BLACK,DARKGRAY);
	    taoLable(1000,575,1150,625,BLACK,BLACK,GRAY,"So day");
	    taoEditText(0,1150,575,1280,625,mapID,BLACK,DARKGRAY);
	    

	    taoLable(370,675,570,725,BLACK,BLACK,GRAY,"Loai May Bay");
	    taoEditText(0,570,675,900,725,mapID,BLACK,DARKGRAY);
	    taoLable(1000,675,1150,725,BLACK,BLACK,GRAY,"So dong");
	    taoEditText(0,1150,675,1280,725,mapID,BLACK,DARKGRAY);
}

void manhinhmaybay(danhsachmaybay &dsmb,unsigned short int **mapID,int &idnext,bool isFindMB){
	maybay mb;
	resetmb(mb);
	bool kt=0;
	int tranghientai=1;
	int trangcuoi = ceil(dsmb.soluong/10.0);
	char s[50] = "";
	char d[50] = "";
	int vitri = 0;
	bool dangNhapLieu = 0;
	if (!isFindMB) {
		veKhungCongCuMB(mapID);
	}
	
	veKhungDSMB(mapID);
	if (dsEmpty(dsmb)) {
		settextstyle(0, 0, 2);
		outtextxy(825-strlen("! DANH SACH TRONG !")*4,135,"! DANH SACH TRONG !");
		
	    taoButton(0,790,510,860,540,mapID,BLACK,BLACK,GRAY,"XOA");
	    taoButton(0,910,510,980,540,mapID,BLACK,BLACK,GRAY,"SUA");
		}
		
	else {
		for(int i=0; i < dsmb.soluong && i< 10 ;i++ ){
				taodongdsmb(i+1,350,130+i*30,1300,160+i*30,*dsmb.data[i],0,mapID);
				setID(1000 +i,350,130+i*30,1300,160+i*30,mapID);
				}
		     if(! isFindMB){
		     	mb=*dsmb.data[0];
		     	vitri=1;
		     	clickmb(mb,1,mapID); 
			 }   
	}
	settextstyle(0,0,2);
	if( tranghientai < trangcuoi)  
		taoButton(NEXT_PAGE,1200,450,1275,480,mapID,BLACK,BLACK,LIGHTGREEN,"NEXT");
	else taoLable(1200,450,1275,480,BLACK,BLACK,GRAY,"NEXT");
		taoLable(375,450,450,480,BLACK,BLACK,GRAY,"BACK");
		
	int x,y;
	int idtmp;
	char chartemp;
	
	
	while (true) {
		delay(100);
		idtmp=0;
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			idtmp = mapID[y][x];
			clearmouseclick(WM_LBUTTONDOWN);
		}
			co: 
			switch(idtmp){
				case ADD_MB: //themmaybay 
					if (FullDS(dsmb)) {
						MessageBox(NULL,"So luong may bay vuot qua gioi han cho phep !","ERROR!",MB_ICONWARNING|MB_OK);
					}
					else{
					 dangNhapLieu=1;
		        	 if(  ! dsEmpty(dsmb) ){
		        	 	unclickmb(mb,vitri,mapID);
					 }
		        	 resetmb(mb);
		        	 s[0]='\0';
		        	 d[0]='\0';
		           	 resetthanhchucnang(mapID);
		           
		           	 taoButton(LUU_ADDMB,730,510,800,540,mapID,BLACK,BLACK,LIGHTGREEN,"LUU");
		           	 taoButton(HUY_ADDMB,850,510,920,540,mapID,BLACK,BLACK,LIGHTGREEN,"HUY");
		           	 taoEditText(ED_SHMB,500,575,900,625,mapID,BLACK,WHITE);
					 taoEditText(ED_SODAY,1150,575,1280,625,mapID,BLACK,WHITE);
					 taoEditText(ED_LOAIMB,570,675,900,725,mapID,BLACK,WHITE);	 
					 taoEditText(ED_SODONG,1150,675,1280,725,mapID,BLACK,WHITE);
					}
	           	break;
//	           	
//	           	case LUU_ADDMB:	// Luu Them May Bay
//	           	cout<<LUU_ADDMB;
//				if(checkmb(mb)){
//					dangNhapLieu=0;
//					  add_newmb_vaods(dsmb,mb);	
//					  Save_file_MB(dsmb);
//					  if((dsmb.soluong % 10   == 1)) {
//						trangcuoi++;
//						  if(trangcuoi-tranghientai ==1 )
//					         taoButton(NEXT_PAGE,1200,450,1275,480,mapID,BLACK,BLACK,LIGHTGREEN,"NEXT");
//					  }
//					  if(tranghientai==trangcuoi ){
//						if((dsmb.soluong==1) || (dsmb.soluong % 10 != 1)){
//							vitri=dsmb.soluong ;
//					     taodongdsmb(vitri,350,130+(vitri-1)%10*30,1300,160+(vitri-1)%10*30,*dsmb.data[vitri-1],0,mapID);
//					     setID(1000+(vitri-1)%10,350,130+(vitri-1)%10*30,1300,160+(vitri-1)%10*30,mapID);
//						}
//						clickmb(mb,vitri,mapID);
//				   	}
//					else{
//						mb = *dsmb.data[(tranghientai-1)*10];
//						vitri=(tranghientai-1)*10+1;
//						clickmb(mb,vitri,mapID);	
//					  }
//					resetthanhchucnang(mapID);
//					taoButton(ADD_MB,670,510,740,540,mapID,BLACK,BLACK,LIGHTGREEN,"THEM");
//				    taoButton(DELETE_MB,790,510,860,540,mapID,BLACK,BLACK,LIGHTGREEN,"XOA");
//				    taoButton(EDIT_MB,910,510,980,540,mapID,BLACK,BLACK,LIGHTGREEN,"SUA");
//					setID(0,500,575,900,625,mapID);
//					setID(0,1150,575,1280,625,mapID);
//					setID(0,570,675,900,725,mapID);
//					setID(0,1150,675,1280,725,mapID);
//					}
//	           	break;
//	           	
	           	case EDIT_MB: 
	           	 dangNhapLieu=1;
	           	 resetthanhchucnang(mapID);
	           	 
	           	 taoButton(LUU_EDITMB,730,510,800,540,mapID,BLACK,BLACK,LIGHTGREEN,"LUU");
	           	 taoButton(HUY_EDITMB,850,510,920,540,mapID,BLACK,BLACK,LIGHTGREEN,"HUY");
	           	           	
	           	 	 strcpy(s,toChars(mb.soday));
					 taoEditText(ED_SODAY,1150,575,1280,625,mapID,BLACK,WHITE);
	           	 	 setbkcolor(WHITE);
	        	 	 outtextxy(1155,590,toChars(mb.soday));
	        	 	 strcpy(s,toChars(mb.soday));
	        	 	 
	        	 	 strcpy(d,toChars(mb.sodong));
	        	 	 taoEditText(ED_SODONG,1150,675,1280,725,mapID,BLACK,WHITE);
	        	 	 setbkcolor(WHITE);
	        	 	 outtextxy(1155,690,toChars(mb.sodong));
	        	 	 strcpy(d,toChars(mb.sodong));
				
				 taoEditText(ED_SHMB,500,575,900,625,mapID,BLACK,WHITE);
				 setbkcolor(WHITE);
	        	 outtextxy(505,590,mb.sohieumaybay);
				 taoEditText(ED_LOAIMB,570,675,900,725,mapID,BLACK,WHITE);
				 setbkcolor(WHITE);
	        	 outtextxy(575,690,mb.loaimaybay);
	        	  
	        	 break;

	           	
	           	case ED_SHMB:      // Nhap SHMB
	        	  	do{
	        	  		idtmp = ED_SHMB;
		        	  	Input(505,590,INHOA_VIETLIEN,mb.sohieumaybay,MAXLENGHT_SHMB,idtmp,mapID,kt);
		        	  	if(idtmp ==HUY_ADDMB || idtmp ==HUY_EDITMB)
		        	  	  break;
		        		if(timkiem_mb(dsmb,mb.sohieumaybay) != -1)
		        		   MessageBox(NULL,"So Hieu May Bay Da Ton Tai \n   Vui Long Nhap Lai! !","THONG BAO",MB_ICONWARNING|MB_OK);
		        		} while(timkiem_mb(dsmb,mb.sohieumaybay) != -1);
	        		if(kt==1) goto co;
	        		
	        	case ED_SODAY:    // Nhap So Day Cua May BAy
			    	do{
				    	idtmp=ED_SODAY;
				    	Input(1155,590,NUMBER,s,MAXLENGHT_SODAY,idtmp,mapID,kt);
				    	if(idtmp ==HUY_ADDMB || idtmp ==HUY_EDITMB)
		        	  	  break;
					    mb.soday=  ChangeCharToNum(s);
		
					    if (mb.soday <= 0)
					       MessageBox(NULL," Vui Long Nhap So day > 0 !","THONG BAO",MB_ICONWARNING|MB_OK);
					} while(mb.soday < 0 );
				
					if(kt==1) goto co;
					
				case ED_SODONG:    // Nhap So Dong Cua May BAy
			    	do{
				    	idtmp=ED_SODONG;
				    	Input(1155,690,NUMBER,d,MAXLENGHT_SODONG,idtmp,mapID,kt);
				    	if(idtmp ==HUY_ADDMB || idtmp ==HUY_EDITMB)
		        	  	  break;
					    mb.sodong =  ChangeCharToNum(d);
		
					    if (mb.sodong <= 0)
					       MessageBox(NULL," Vui Long Nhap So dong > 0 !","THONG BAO",MB_ICONWARNING|MB_OK);
					} while(mb.sodong < 0 );
				
					if(kt==1) goto co;
				
				case ED_LOAIMB:   // Nhap Loai May Bay
					idtmp=ED_LOAIMB;
					Input(575,690,CHUSOTHUONG,mb.loaimaybay,MAXLENGHT_LMB,idtmp,mapID,kt);
					if(kt==1) goto co;
				break;
				
				
				case  HUY_ADDMB :  //Huy Luu
				
					dangNhapLieu=0;
					resetthanhchucnang(mapID);
					taoButton(ADD_MB,670,510,740,540,mapID,BLACK,BLACK,LIGHTGREEN,"THEM");
					if( !dsEmpty(dsmb)){
						taoButton(DELETE_MB,790,510,860,540,mapID,BLACK,BLACK,LIGHTGREEN,"XOA");
				    	taoButton(EDIT_MB,910,510,980,540,mapID,BLACK,BLACK,LIGHTGREEN,"SUA");
					}
					else{
						taoButton(0,790,510,860,540,mapID,BLACK,BLACK,GRAY,"XOA");
				    	taoButton(0,910,510,980,540,mapID,BLACK,BLACK,GRAY,"SUA");
					}
				    
				     taoEditText(0,500,575,900,625,mapID,BLACK,DARKGRAY);
					 taoEditText(0,1150,575,1280,625,mapID,BLACK,DARKGRAY);
					 taoEditText(0,570,675,900,725,mapID,BLACK,DARKGRAY);
					 taoEditText(0,1150,675,1280,725,mapID,BLACK,DARKGRAY);
				    if( !dsEmpty(dsmb)){
						mb = *dsmb.data[(tranghientai-1)*10];
						vitri=(tranghientai-1)*10+1;
						clickmb(mb,vitri,mapID);
				    }
					break;
				case DELETE_MB: 
				if (MessageBox(NULL,"Xac Nhan Xoa ","THONG BAO",MB_ICONWARNING|MB_OKCANCEL) == IDOK) 
				{
				
					delete_mb_khoids(dsmb ,vitri-1);
					Save_file_MB(dsmb);
					setfillstyle(1,WHITE);
		        	bar(351,131+(vitri-1) % 10*30,1300,430);
		        	setcolor(BLUE);
		        	for(int i=(vitri-1)%10; i+(tranghientai-1)*10 < dsmb.soluong && i < 10 ;i++ )
		     		   taodongdsmb(i+1+(tranghientai-1)*10,350,130+i*30,1300,160+i*30,*dsmb.data[i+(tranghientai-1)*10],0,mapID);
	     		if( dsmb.soluong % 10 == 0){
		     			trangcuoi--;
		     			
		     			if(dsEmpty(dsmb) ){
		     				setbkcolor(WHITE);
		     				outtextxy(825-strlen("! DANH SACH TRONG !")*4,135,"! DANH SACH TRONG !");
		     			    taoEditText(0,500,575,900,625,mapID,BLACK,DARKGRAY);
							taoEditText(0,1150,575,1280,625,mapID,BLACK,DARKGRAY);
							taoEditText(0,570,675,900,725,mapID,BLACK,DARKGRAY);
							taoEditText(0,1150,675,1280,725,mapID,BLACK,DARKGRAY);
						    taoButton(0,790,510,860,540,mapID,BLACK,BLACK,GRAY,"XOA");
						    taoButton(0,910,510,980,540,mapID,BLACK,BLACK,GRAY,"SUA");
						    setID(0,350,130,1300,160,mapID);
		     				resetmb(mb);
						 }
		     			else {
		     					if(trangcuoi < tranghientai){
		     						idtmp=121;
								    goto co;
								 }
								if(trangcuoi == tranghientai){
									 taoButton(0,1200,450,1275,480,mapID,BLACK,BLACK,GRAY,"NEXT");
								}
						 	}
					 	}
					 	
				else {
						if(trangcuoi == tranghientai)
							setID(0,350,130+(dsmb.soluong % 10)*30,1300,160+(dsmb.soluong % 10)*30,mapID);
					}
								 
				if( ! dsEmpty(dsmb)){
     	      			mb = *dsmb.data[(tranghientai-1)*10];
						vitri=(tranghientai-1)*10+1;
						clickmb(mb,vitri,mapID);
					}
				}
	        	
				break;
				
				case LUU_EDITMB: 
				if(checkmb(mb)==1){
					dangNhapLieu=0;
					edit_mb(dsmb,vitri-1,mb);
					clickmb(mb,vitri,mapID);
				 
					Save_file_MB(dsmb);
					resetthanhchucnang(mapID);
					taoButton(ADD_MB,670,510,740,540,mapID,BLACK,BLACK,LIGHTGREEN,"THEM");
				    taoButton(DELETE_MB,790,510,860,540,mapID,BLACK,BLACK,LIGHTGREEN,"XOA");
				    taoButton(EDIT_MB,910,510,980,540,mapID,BLACK,BLACK,LIGHTGREEN,"SUA");
					setID(0,500,575,900,625,mapID);
					setID(0,1150,575,1280,625,mapID);
					setID(0,570,675,900,725,mapID);
					setID(0,1150,675,1280,725,mapID);
				
				}			
				break;
				case  HUY_EDITMB :  //Huy Luu
				
					dangNhapLieu=0;
					resetthanhchucnang(mapID);
					taoButton(ADD_MB,670,510,740,540,mapID,BLACK,BLACK,LIGHTGREEN,"THEM");
					taoButton(DELETE_MB,790,510,860,540,mapID,BLACK,BLACK,LIGHTGREEN,"XOA");
			    	taoButton(EDIT_MB,910,510,980,540,mapID,BLACK,BLACK,LIGHTGREEN,"SUA");
				     taoEditText(0,500,575,900,625,mapID,BLACK,DARKGRAY);
					 taoEditText(0,1150,575,1280,625,mapID,BLACK,DARKGRAY);
					 taoEditText(0,570,675,900,725,mapID,BLACK,DARKGRAY);
					 taoEditText(0,1150,675,1280,725,mapID,BLACK,DARKGRAY);
					 
						mb = *dsmb.data[vitri-1];
						
						clickmb(mb,vitri,mapID);
				    
					break;
				
				case 1000:case 1001:case  1002 :case 1003: case 1004 :case 1005: case 1006 :case 1007: case 1008: case 1009:
	        	 	
				        if( ! dangNhapLieu){
				        	
				        	if((tranghientai-1)*10 < vitri && (tranghientai)*10 >= vitri ){
				        	unclickmb(mb,vitri,mapID);
				        	}
					        vitri=(idtmp-1000+1)+(tranghientai-1)*10;
					        if( isFindMB){
				        		idnext=vitri-1;
				        		return;
							}
					       
				        	mb=*dsmb.data[idtmp-1000+(tranghientai-1)*10];
//				        	strcpy(s,toChars(mb.soday*mb.sodong));
				        	clickmb(mb,vitri,mapID);
						}
				        	
				        	break;
	        	case ID_CHUYENBAY:case ID_VE:case ID_THONGKE:case ID_EXIT:   // case Menu
	        		if( ! isFindMB){
	        	  	if(dangNhapLieu){
	        			if( MessageBox(NULL," Du Lieu Vua Nhap Chua Duoc Luu \n"
						         			"    Ban co muon thoat khong ??? "
											,"THONG BAO",MB_ICONWARNING|MB_OKCANCEL) == IDOK){
	        				idnext=idtmp;
	        					return;
						  }	
			          	}
						else{
							idnext=idtmp;
		        			return;
							}
						}
					
				default:
						cout<<"hihi";
					if (kbhit()){    // Bat Phim Khi Chua CLick Vao EdiitText
					chartemp=getch();
					break;
				}

			}
		}
}



	
	
///////////////////////////////////////// CHUYEN BAY /////////////////////////////////////////////////
void vekhungdscb(unsigned short int ** mapID){
	
		taoLable(650,0,1000,50,BLACK,BLACK,GRAY,"DANH SACH CHUYEN BAY");
			// LOC
		taoLable(320,70,400,90,BLACK,BLACK,GRAY,"MaCB");
		taoEditText(LOC_MACB,400,70,560,90,mapID,BLACK,WHITE);
		taoLable(630,70,700,90,BLACK,BLACK,GRAY,"DATE");
		taoEditText(LOC_NGAY,700,70,730,90,mapID,BLACK,WHITE);
		taoEditText(LOC_THANG,750,70,780,90,mapID,BLACK,WHITE);
		taoEditText(LOC_NAM,800,70,850,90,mapID,BLACK,WHITE);
		setbkcolor(WHITE);
		outtextxy(732,70,"/");
		outtextxy(782,70,"/");
		taoLable(925,70,1045,90,BLACK,BLACK,GRAY,"DiemDen");
		taoEditText(LOC_DIEMDEN,1045,70,1330,90,mapID,BLACK,WHITE);
		rectangle(300,100,1350,430);
		line(300,130,1350,130);
		line(300+5*8 ,100,300+5*8,130);
		line(300+35*8,100,300+35*8,130);
		line(300+65*8,100,300+65*8,130);
		line(300+85*8,100,300+85*8,130);
		line(300+120*8,100,300+120*8,130);
		setbkcolor(WHITE);
		settextstyle(8, 0, 0);
		setusercharsize(1,2,1,2);
		outtextxy(300+5*4-strlen("STT")*4,110,"STT");
		outtextxy(300+20*8-strlen("MaCB")*4,110,"MaCB");
		outtextxy(300+50*8-strlen("SoHieuMB")*4,110,"SoHieuMB");
		outtextxy(300+75*8-strlen("ThoiGian")*4,110,"ThoiGian");
		outtextxy(300+102*8-strlen("DiemDen")*4,110,"DiemDen");
		outtextxy(300+125*8-strlen("TrangThai")*4,110,"TrangThai");
		settextstyle(0, 0, 2);
		
}
void vekhungnhaplieucb(unsigned short int ** mapID){
	
		setcolor(BLACK);
		// THANH TRANG THAI
		setbkcolor(BLACK);
		rectangle(300,500,1350,750);
		line(300,550,1350,550);
		taoButton(ADD_CB,650,510,750,540,mapID,BLACK,BLACK,LIGHTGREEN,"Them");
		taoButton(CANCEL_CB,775,510,875,540,mapID,BLACK,BLACK,LIGHTGREEN,"HuyCB");
		taoButton(EDIT_CB,900,510,1000,540,mapID,BLACK,BLACK,LIGHTGREEN,"Sua");	
		// KHUNG NHAP LIEU
		taoLable(350,570,450,610,BLACK,BLACK,GRAY,"MaCB");
	    taoEditText(0,450,570,800,610,mapID,BLACK,DARKGRAY);
	    
	    taoLable(850,570,950,610,BLACK,BLACK,GRAY,"SHMB");
	    taoEditText(0,950,570,1300,610,mapID,BLACK,DARKGRAY);
	    
	    
	    taoLable(350,630,470,670,BLACK,BLACK,GRAY,"DiemDen");
	    
	    taoEditText(0,470,630,975,670,mapID,BLACK,DARKGRAY); 
	    
	    taoLable(1000,630,1150,670,BLACK,BLACK,GRAY,"TrangThai");
	    taoLable(1150,630,1300,670,BLACK,BLACK,DARKGRAY,"");
	    
	   	taoLable(350,690,460,730,BLACK,BLACK,GRAY,"Ngay");
		taoEditText(0,460,690,515,730,mapID,BLACK,DARKGRAY);	
		taoLable(520,690,610,730,BLACK,BLACK,GRAY,"Thang");
		taoEditText(0,610,690,665,730,mapID,BLACK,DARKGRAY); 
		taoLable(670,690,730,730,BLACK,BLACK,GRAY,"Nam");
		taoEditText(0,730,690,830,730,mapID,BLACK,DARKGRAY);
		taoLable(865,690,940,730,BLACK,BLACK,GRAY,"Time");
		taoEditText(0,940,690,995,730,mapID,BLACK,DARKGRAY);
		taoEditText(0,1020,690,1075,730,mapID,BLACK,DARKGRAY);
		setbkcolor(WHITE);
		outtextxy(997,700,":");
		settextstyle(0, 0, 2);
		
}

void taodongdscb(int stt, int x, int y,int x1,int y1,chuyenbay &cb){
	
		setcolor(BLACK);
		settextstyle(8, 0, 0);
		setusercharsize(1,2,1,2);
	    line(x,y1,x1,y1);
		line(x+5*8 ,y,300+5*8,y1);
		line(300+35*8,y,300+35*8,y1);
		line(300+65*8,y,300+65*8,y1);
		line(300+85*8,y,300+85*8,y1);
		line(300+120*8,y,300+120*8,y1);
		
		outtextxy(300+5*4-textwidth(toChars(stt))/2,y+10,toChars(stt));
		outtextxy(300+20*8-textwidth(cb.MaCB)/2,y+10,cb.MaCB);
		outtextxy(300+50*8-textwidth(cb.sohieumaybay)/2,y+10,cb.sohieumaybay);
//		outtextxy(300+75*8-textwidth(tocharDate(cb.mytime))/2,y+10,tocharDate(cb.mytime));
		outtextxy(300+102.5*8-textwidth(cb.sanbayden)/2,y+10,cb.sanbayden);
		if(cb.trangthai == HUYCHUYEN)
			 outtextxy(300+125.5*8-textwidth("HUYCHUYEN")/2,y+10,"HUYCHUYEN");
		else if(cb.trangthai == CONVE)
		    
		      outtextxy(300+125.5*8-textwidth("CONVE")/2,y+10,"CONVE");
		 else if(cb.trangthai == HETVE)
		     
		      outtextxy(300+125.5*8-textwidth("HETVE")/2,y+10,"HETVE");
		     
		else 
		      outtextxy(300+125.5*8-textwidth("HOANTAT")/2,y+10,"HOANTAT");
	
		settextstyle(0,0,2);
}



void manhinhchuyenbay(unsigned short int ** mapID,danhsachmaybay &dsmb,PTR &First,int &idnext ) {
	vekhungdscb(mapID);
	vekhungnhaplieucb(mapID);
	chuyenbay cb;
	resetcb(cb);
	PTR nodechay;
	
	
	settextstyle(0, 0, 2);
	if( dsCBEmpty(First) ){
		 outtextxy(825-strlen("! DANH SACH TRONG !")*4,135,"! DANH SACH TRONG !");
			taoButton(0,775,510,875,540,mapID,BLACK,BLACK,GRAY,"HuyCB");
			taoButton(0,900,510,1000,540,mapID,BLACK,BLACK,GRAY,"Sua");
	}
	else {
		int slcb=0;
		for(nodechay = First; nodechay != NULL; nodechay = nodechay -> next ){
				slcb++;
				if(slcb <=10){
					taodongdscb(slcb,300,100+slcb*30,1350,130+slcb*30,nodechay->data);
		     		setID(1000+slcb,300,100+slcb*30,1350,130+slcb*30,mapID);
				}
//				if (slcb % 10 ==1){	
//					trangcuoi++;
//					dautrang[trangcuoi] = new nodeCB;
//				   dautrang[trangcuoi]= nodechay;
//					}
			}
		if(slcb > 10){	
			taoButton(NEXT_PAGECB,1200,450,1300,480,mapID,BLACK,BLACK,LIGHTGREEN,"NEXT>");
		}
		else
		  taoButton(0,1200,450,1300,480,mapID,BLACK,BLACK,GRAY,"NEXT>");
		taoButton(0,350,450,450,480,mapID,BLACK,BLACK,GRAY,"<BACK");
	}


}


//////////////////////////////////////// VE /////////////////////////////////////////////////////
void vekhungve(unsigned short int ** mapID) {
	taoLable(650,0,1000,50,BLACK,BLACK,GRAY,"DANH SACH VE");
	rectangle(300,100,1350,430);
		line(300,130,1350,130);
		line(300+5*8 ,100,300+5*8,130);
		line(300+35*8,100,300+35*8,130);
		line(300+65*8,100,300+65*8,130);
		line(300+85*8,100,300+85*8,130);
		line(300+120*8,100,300+120*8,130);
}


/////////////////////////////////////// 
void vekhungthongke(unsigned short int ** mapID) {
	taoLable(650,0,1000,50,BLACK,BLACK,GRAY,"THONG KE");
}



#pragma once
#include "define.h"	
#define file_may_bay "datamaybay"					
struct maybay {
	char sohieumaybay[15];
	char loaimaybay[30];
	int soday,sodong;
	int soChuyenDaBay = 0;
};

struct danhsachmaybay{
	maybay *data[300];
	int soluong = 0;
};

maybay *newmb(maybay mb) {
	
	maybay *temp = new maybay;
	*temp = mb;
	return temp;
};

void add_newmb_vaods(danhsachmaybay &dsmb, maybay &mb){
	dsmb.data[dsmb.soluong] = newmb(mb);
	dsmb.soluong ++;
}

//-----------------------------------------FILE MAY BAY ---------------------------------
void Save_file_MB(danhsachmaybay &dsmb) {
 		FILE * PTR;
 			
		 if ((PTR=fopen(file_may_bay,"wb"))==NULL)
		 {  
		 cout<<"ERROR! Khong The Mo File May Bay"<<endl;
		 return;
		 }
		 for (int i=0; i < dsmb.soluong; i++){
		 	
		   fwrite (dsmb.data[i], sizeof(maybay),1,PTR);
		 }
		 	fclose(PTR);
}

void Open_file_MB (danhsachmaybay &dsmb) {
	       FILE * PTR;
	       maybay temp;
		 if ((PTR=fopen(file_may_bay,"rb"))==NULL)
		 {  
		 	cout<<"ERROR! Khong The Mo File May Bay"<<endl;
		 	return;
		 }
		  dsmb.soluong=0;
		 while  (fread (&temp, sizeof (maybay), 1, PTR)!=0) {
		 	
		add_newmb_vaods(dsmb,temp);
	 }
	 	fclose(PTR);
	}
	
bool dsEmpty(danhsachmaybay &dsmb) {
	return (dsmb.soluong == 0 ? true : false);
}


bool FullDS(danhsachmaybay &dsmb) {
	return (dsmb.soluong > 300 ? true : false);
}

void delete_mb_khoids(danhsachmaybay &dsmb , int vitri){
	delete dsmb.data[vitri];
	for(int i=vitri; i< dsmb.soluong -1; i++ )
		dsmb.data[i]= dsmb.data[i+1];
	dsmb.soluong--;
}
int timkiem_mb(danhsachmaybay &dsmb, char *sohieuMB){
	for(int i=0  ;i < dsmb.soluong ;i++)
	    { 
	        if(strcmp(dsmb.data[i]->sohieumaybay, sohieuMB) == 0)
	           return i;
		}
   return -1;
}

void edit_mb(danhsachmaybay &dsmb , int vitri, maybay &mb){
	    *dsmb.data[vitri]=  mb ;
}


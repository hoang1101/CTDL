#pragma once
#include "define.h"	
#include "maybay.h"
#include "ngay.h"
#define file_chuyen_bay "datachuyenbay"

// --------------- trang thai ----------------
enum TrangThai {
	HUY_CHUYEN,
	CON_VE,
	HET_VE,
	HOAN_TAT,
};

//-------------- ve -------------------
struct ve {
	char cmnd[12];
	char vitri[5];
};

//------------- chuyen bay -----------------
struct chuyenbay {
	char MaCB[MAXLENGHT_MACB+1];
	char sanbayden[MAXLENGHT_SANBAYDEN+1];
	char sohieumaybay[MAXLENGHT_SHMB+1];
	TrangThai trangthai;
//	Day_time mytime;
	ve *dsve = NULL;//------ ds ve may bay ---------
	int sove;
};

struct nodeCB {
	chuyenbay data;
	nodeCB *next = NULL;
};

typedef struct nodeCB *PTR;

nodeCB *taonodemoi(chuyenbay &cb) {
	nodeCB *temp = new nodeCB;
	temp->data = cb;
	temp->next = NULL;
	return temp;
}

void InsertLast(PTR &First, chuyenbay cb) {
    PTR p = taonodemoi(cb);
    if (First == NULL) {
        First = p;
    } else {
        PTR Last = First;
        while (Last->next != NULL) {
            Last = Last->next;
        }
        Last->next = p;
    }
}

bool dsCBEmpty(PTR first) {
	return (first == NULL);
}

////-----------------------FILE CHUYEN BAY--------------------------------------
void Save_file_chuyen_bay(PTR &first){

	FILE *f = fopen (file_chuyen_bay, "wb");
	if (f==NULL) 
	{  	cout<<"ERROR! Khong The Mo File Chuyen Bay"<<endl;
		 		 return ;
	}

	for (PTR p=first ; p!=NULL ; p=p->next)
	 {
	 	 chuyenbay &data = p->data; // Khai báo bi?n sv trong vòng l?p
        fwrite(&data, sizeof(chuyenbay), 1, f);
        fwrite(data.dsve, sizeof(ve), 1, f);
	 }
	  
	fclose (f);
}



void Open_file_chuyen_bay(PTR &first ){
	FILE * f;
	PTR p;
	chuyenbay cb;
	if ((f=fopen(file_chuyen_bay,"rb"))==NULL)
	{  cout<<"ERROR! Khong The Mo File Chuyen Bay"<<endl;
	 	return ;
	}	 
 
	while (first != NULL) {
        p = first;
        first = p->next;
        delete p;
    }

	while (fread(&cb, sizeof(chuyenbay), 1, f) == 1) {
        cb.dsve = new ve;
        fread(cb.dsve, sizeof(ve), 1, f);
        InsertLast(first, cb);
    }

    fclose(f);
}





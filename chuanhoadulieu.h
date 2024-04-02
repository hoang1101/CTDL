#include<conio.h>
#include<math.h>
//#include "ngayh.h"

using namespace std;

char* toChars(unsigned long long num){
	
	char* a = new char[100];
	if (num == 0)
	{
		a[0] = '0';
		a[1] = '\0';
	}
	else
	{
		int l = floor(log10(num)+1);
		a[l--] = '\0';
		while(num>0)
		{
			a[l--] = num%10+48; //to char
			num/=10;
		}
	}
	return a;
}
bool isLetter(char c){
	
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z' ) || (c == ' '))
		return 1;
		
	return 0;	 
}

bool choPhepNhap(char s[], int n){
	if(strlen(s)<n)
		return 1;
	return 0;	
}

int checkNhapLieu(char c, char s[]){
	
	if(strlen(s) == 0 && c == ' ') // Khoa Phim Cach Nhap Vao Chuoi Rong
		return 0;
else if(strlen(s) != 0 && s[strlen(s)-1] == ' ' && c == ' ') //Khoa Nhap 2 Phim Cach Lien Tiep
			return 0;	
else if((strlen(s) != 0 && s[strlen(s)-1] == ' ' && c != ' ') || (strlen(s) == 0 && c != ' '))//  Viet Hoa Tu Dau Tien Hoac Sau Dau Cach
			return -1;
			
	return 1;	 
}
void AddChuoi(char c,char str[]){
	
	strncat(str, &c , 1);
}
bool isNum(char c){
	
	if(c >= '0' && c <= '9')
		return 1;
		
	return 0;	 
}
unsigned long long ChangeCharToNum (char str[]){
	
	unsigned long long n = 0;
	for(int i = 0; i<strlen(str); i++){
		
		n = n * 10;
		n += (str[i]-48);
	}
	return n;
}


void Nhap(int x,int y,int kieuChuanHoa, char c, char *s, int n){
	
//	if(c==8 && strlen(s) != 0)  {    //Phim BackSpace
//		outtextxy(x+textwidth(s),y," ");
//		s[strlen(s)-1] = '\0';	
//		}
	if(kieuChuanHoa== CHUTHUONG ){     // NHAP CHU THONG THUONG
	
		if(isLetter(c) && choPhepNhap(s,n)){
			
			if(checkNhapLieu(c,s) == 1){
				
				AddChuoi(c,s);
			}
			else if(checkNhapLieu(c,s)==-1)	{
				
					c = toupper(c);
					AddChuoi(c,s);
				}		
		}
		
	}
	else if(kieuChuanHoa == NUMBER)     //NHAP SO
	{
		if(isNum(c) && choPhepNhap(s,n)){
				AddChuoi(c,s);
		}
	}
	else if(kieuChuanHoa== INHOA_VIETLIEN)        //NHAP CHU IN HOA VA SO KO SPACE
	{
		if((isNum(c) || isLetter(c)) && choPhepNhap(s,n) && c != ' '){
			
			if(checkNhapLieu(c,s) == 1|| checkNhapLieu(c,s) == -1){
				c = toupper(c);
				AddChuoi(c,s);
			}
		}
	}
	else
	if(kieuChuanHoa== CHUSOTHUONG)   // Nhap Chu So Thong Thuong
	{
		if((isNum(c) || isLetter(c)) && choPhepNhap(s,n))
		{
			
			if(checkNhapLieu(c,s) == 1){
				AddChuoi(c,s);
			}
			else
				if(checkNhapLieu(c,s)==-1){
					c = toupper(c);
					AddChuoi(c,s);
				}
		}
	}
 	outtextxy(x,y,s);	
}

void Input(int x,int y,int kieuChuanHoa, char s[], int n, int &id,unsigned short int **mapID,bool &kt){
	kt=0;
	char c;
	int idtmp=id;
	int h,k;
	setbkcolor(WHITE);
	setcolor(BLACK);
	while(true){
			if(ismouseclick(WM_LBUTTONDOWN)){
				getmouseclick(WM_LBUTTONDOWN, h, k);
				idtmp = mapID[k][h];
				clearmouseclick(WM_LBUTTONDOWN);
	      	  }
	      	  
	      	if(id != idtmp) {
			 	 kt=1;
			  	id=idtmp;
			  	if(s[strlen(s)-1]==' ')
			    	s[strlen(s)-1]='\0';
			  	return ;
			  }
	      	
		    if (kbhit()){
				c=getch();
				if(c!= 13){
						if(c==8 && strlen(s) != 0)  {    //Phim BackSpace
							outtextxy(x+textwidth(s),y," ");
							s[strlen(s)-1] = '\0';	
						  }
					   else	Nhap(x,y,kieuChuanHoa,c,s,n);
					}
				else {
						if(s[strlen(s)-1]==' ')
		    				s[strlen(s)-1]='\0';
						return ;
					}
				}
			else { 
					outtextxy(x+textwidth(s),y,"|");
					outtextxy(x+textwidth(s),y," ");	
				}
	
	}
}


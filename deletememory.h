using namespace std;
unsigned short int **PT_MapID;
maybay **PT_MB;


void Delete_dsmb(){
	for(int i=0;i<MAXMAYBAY;i++){
		if(PT_MB[i] == NULL)
	      return;
		delete PT_MB[i];
	}
}
void	DeleteMapID(){
	for(int i=0;i<= WD_HEIGHT;i++)
		   delete [] PT_MapID[i];
	delete [] PT_MapID;
}

void DeleteMemory(){
		DeleteMapID();
		Delete_dsmb();

}


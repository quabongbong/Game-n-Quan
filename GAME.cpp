#include<stdio.h>
#include<windows.h>
#include<conio.h>

enum state {INGAME = 0, GAMEOVER} state;

//tao ham gotoxy
void gotoxy(int x, int y){
        static HANDLE h = NULL;  
        if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD c = { x, y };  
        SetConsoleCursorPosition(h,c);
}

//tao khung tro choi
void khungTroChoi(){
	for(int j = 1; j<10; j++){
		if(j == 1){
			for(int i=0; i<=71; i++){
				if(i==71) printf("\n");
				else printf("_");
			}
        }
        else if(j==5){
        	for(int i=0; i<=71; i++){
        		if(i == 71) printf("\n");
        		else if(i % 10 == 0) printf("|");
        		else if(i>=11 && i<= 59) printf("_");
        		else printf(" ");
				}
				}
		else if(j==9){
			for(int i=0; i<=71; i++){
        		if(i == 71) printf("\n");
        		else if(i % 10 == 0) printf("|");
        		else printf("_");
				}
		}
		else {
			for(int i=0; i<=71; i++){
				if(i==71) printf("\n");
				else if(i % 10 == 0) printf("|");
        		else printf(" ");
			}
		}
		}
}

//Hien thi tren man hinh
void hienThi(){
	int soSoi[2][6];
    int diemSo[2] = {0,0};
    for(int i = 0; i<2; i++){
    	for(int j = 0; j<6; j++){
    		if(j == 0) soSoi[i][j] = 10;
    		else soSoi[i][j] = 5;
		}
	}
	for(int j =0; j<6; j++){
		if(j==0){
			gotoxy(5, 4); printf("%d", soSoi[0][0]);
			gotoxy(65, 4); printf("%d", soSoi[1][0]);
	        }
	    else {
			for(int i =0; i<2; i++){
		       	gotoxy((2*j+1)*5,(i+1)*3
				   ); printf("%d", soSoi[1][j]);
			   	}
           	}
	}
    gotoxy(0, 10); printf("Nguoi choi 1: %d\nNguoi choi 2: %d", diemSo[0], diemSo[1]);
}
void ingame(){
	khungTroChoi();
	state = 10;
}
void gameover(){
	
}
int main(){
	while(1){
		switch(state){
			case INGAME:
				ingame();
				break;
			case GAMEOVER:
				gameover();
				break;
		}
		}
	return 0;
	
}

#include<stdio.h>
#include<windows.h>
#include<conio.h>

enum state {MENU = 0, INGAME, INFORMATION, GAMEOVER} state;

void gotoxy(int x, int y){
        static HANDLE h = NULL;  
        if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD c = { x, y };  
        SetConsoleCursorPosition(h,c);
}

void SetColor(WORD color)
{ 
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0; wAttributes |= color;
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

//tao khung tro choi
void khungTroChoi(){
	gotoxy(0, 5);
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

//hien thi tren man hinh
void hienThi(int soSoi[2][6], int diemSo[2]){	
	gotoxy(5, 10); printf("%d", soSoi[0][0]);
	gotoxy(65, 10); printf("%d", soSoi[1][0]);
	gotoxy(15, 7); printf("%d", soSoi[0][1]);
	gotoxy(25, 7); printf("%d", soSoi[0][2]);
	gotoxy(35, 7); printf("%d", soSoi[0][3]);
	gotoxy(45, 7); printf("%d", soSoi[0][4]);
	gotoxy(55, 7); printf("%d", soSoi[0][5]);
	gotoxy(15, 11); printf("%d", soSoi[1][5]);
	gotoxy(25, 11); printf("%d", soSoi[1][4]);
	gotoxy(35, 11); printf("%d", soSoi[1][3]);
	gotoxy(45, 11); printf("%d", soSoi[1][2]);
	gotoxy(55, 11); printf("%d", soSoi[1][1]);
    gotoxy(0, 15); printf("Nguoi choi 1: %d\nNguoi choi 2: %d", diemSo[0], diemSo[1]);
}

//cac buoc di
void phai1(int a[2][6], int j, int k){
	int x =1;
	k=a[1][j];
	a[1][j]=0;
	for(int i=j-1; i>=0; i--){
		a[0][i]++;
		k--;
		if(k==0) break;
	}
}
void trai0(int a[2][6], int j, int k){
	int x=0;
	k=a[0][j];
	a[0][j]=0;
	for(int i =j+1; i<=5; i++){
		a[1][i]++;
		k--;
		if(k==0) break;
	}
}
void trai1(int a[2][6], int j, int k){
	k=a[1][j];
	a[1][j]=0;
	int x=1;
	for(int i = j+1; i<=5; i++){
		a[0][i]++;
		k--;
		if(k==0) break;
	}
}
void phai0(int a[2][6], int j, int k){
	int x=0;
	k=a[0][j];
	a[0][j]=0;
	for(int i = j-1; i>=0; i--){
		a[1][i]++;
		k--;
		if(k==0) break;
	}
}
void chuyenLuotT(int a[2][6], int b[2], int player, int x, int y){
	int f;
	if(a[x][y+1] == 0){
		if(a[x][y+2] != 0){
			a[x][y+2] = 0;
		}
	}
	if(a[x][y+1] != 0){
		f=a[x][y+1];
		if(x == 0){
			trai0(a, y+1, f);
		}
		else trai1(a, y+1, f);
		}
	}

void chuyenLuotP(int a[2][6], int b[2], int player, int x, int y){
	int f;
	if(a[x][y-1] == 0){
		if(a[x][y-2] != 0){
		    a[x][y] = 0;
		}
	}
	if(a[x][y+1] != 0){
		f = a[x][y-1];
		if(x == 0) phai0(a, y-1, f);
		else phai1(a, y-1, f);
	}
}
void nguoi1(int arr[2][6], int b[2]){
	int oDuocChon, player = 1, k1, k2, x, huongDi;
	int soSoiODC;
	if(kbhit()){
	huongDi = getch();
	}
	switch(huongDi){
	case 48:
		x=1;
		oDuocChon = 1;
		soSoiODC = arr[1][oDuocChon];
		trai1(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			phai0(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 49:
		x=1;
		oDuocChon = 2;
		soSoiODC =arr[1][oDuocChon];
		trai1(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			phai0(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 50:
		x=1;
		oDuocChon = 3;
		soSoiODC =arr[1][oDuocChon];
		trai1(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			phai0(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 51:
		x=1;
		oDuocChon = 4;
		soSoiODC =arr[1][oDuocChon];
		trai1(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			phai0(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 52:
		x=1;
		oDuocChon = 5;
		soSoiODC =arr[1][oDuocChon];
		trai1(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			phai0(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 53:
		x=1;
		oDuocChon = 1;
		soSoiODC =arr[1][oDuocChon];
		phai1(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
		   trai0(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 54:
		x=1;
		oDuocChon =2;
		soSoiODC =arr[1][oDuocChon];
		phai1(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			trai0(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
		break;
	case 55:
		x=1;
		oDuocChon =3;
		soSoiODC =arr[1][oDuocChon];
		phai1(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			trai0(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
		break;
	case 56:
		x=1;
		oDuocChon =4;
		soSoiODC =arr[1][oDuocChon];
		phai1(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			trai0(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	case 57:
		x=1;
		oDuocChon =5;
		soSoiODC =arr[1][oDuocChon];
		phai1(arr, oDuocChon, soSoiODC);
		if(
		soSoiODC!=0){
			x=0;
			trai0(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	break;		
	}
}
void nguoi2(int arr[2][6], int b[2]){
	int oDuocChon, player = 1, k1, k2, x, huongDi;
	int soSoiODC;
	if(kbhit()){
	huongDi = getch();
	}
	switch(huongDi){
	case 97:
		x=0;
		oDuocChon = 1;
		soSoiODC =arr[0][oDuocChon];
		trai0(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			phai1(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 98:
		x=0;
		oDuocChon = 2;
		soSoiODC =arr[0][oDuocChon];
		trai0(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			phai1(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 99:
		x=0;
		oDuocChon = 3;
		soSoiODC =arr[0][oDuocChon];
		trai0(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			phai1(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 100:
		x=0;
		oDuocChon = 4;
		soSoiODC =arr[0][oDuocChon];
		trai0(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			phai1(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 101:
		x=0;
		oDuocChon = 5;
		soSoiODC =arr[0][oDuocChon];
		trai0(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			phai1(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 102:
		x=0;
		oDuocChon = 1;
		soSoiODC =arr[0][oDuocChon];
		phai0(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			trai1(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 103:
		x=0;
		oDuocChon =2;
		soSoiODC =arr[0][oDuocChon];
		phai0(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			trai1(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
		break;
	case 104:
		x=0;
		oDuocChon =3;
		soSoiODC =arr[0][oDuocChon];
		phai0(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			trai1(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
		break;
	case 105:
		x=0;
		oDuocChon =4;
		soSoiODC =arr[0][oDuocChon];
		phai0(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			trai1(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	case 106:
		x=0;
		oDuocChon =5;
		soSoiODC =arr[0][oDuocChon];
		phai0(arr, oDuocChon, soSoiODC);
		if(
		soSoiODC!=0){
			x=0;
			trai1(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	break;		
	}
}

int ingame(){
	khungTroChoi();	
	int soSoi[2][6], g;
	for(int i = 0; i<2; i++){
    	for(int j = 0; j<6; j++){
    		if(j == 0) soSoi[i][j] = 10;
    		else soSoi[i][j] = 5;
		}
	}
    int diemSo[2] = {35,35};
    hienThi(soSoi, diemSo);
//main
    while(1){
		if(soSoi[1][0] == 0 && soSoi[0][0] == 0){
			system("cls");
			state = GAMEOVER;
			break;
		}
		if(diemSo[0] == 0|diemSo[1] == 0){
			system("cls");
			state = GAMEOVER;
			break;
		}
		nguoi1(soSoi, diemSo);
		diemSo[0] =0;
		for(int j = 0; j<6; j++){
    		diemSo[0] += soSoi[1][j];
		}
		hienThi(soSoi, diemSo);
		nguoi2(soSoi, diemSo);
		diemSo[1] = 0;
		for(int j = 0; j<6; j++){
    		diemSo[1] += soSoi[0][j];
		}
		hienThi(soSoi, diemSo);
}
    return diemSo[0], diemSo[1];
}

void gameover(){
	SetColor(14);
    system("cls");
	gotoxy(13,5);
	printf("....Game over....\n\t");
	system("pause");
	getchar();
	state = MENU;
}

void information(){
	system("cls");
	SetColor(14);
	khungTroChoi();
	gotoxy(20,2); printf("HUONG DAN CACH CHOI:");
	gotoxy(10,16); printf("Nguoi choi 1 dung cac phim tu 0 - 9:");
	gotoxy(15,17); printf("- Phim 0 - 4: chon tuong ung o 1 - 5 de rai soi sang trai");
	gotoxy(15,18); printf("- Phim 5 - 9: chon tuong ung o 1 - 5 de rai soi sang phai");
	gotoxy(10,19); printf("Nguoi choi 2 dung cac phim tu a - k:");
	gotoxy(15,20); printf("- Phim a - e: chon tuong ung o 1 - 5 de rai soi sang trai");
	gotoxy(15,21); printf("- Phim f - k: chon tuong ung o 1 - 5 de rai soi sang phai");
	gotoxy(10,22); printf("Tro choi ket thuc khi 2 quan bi deu khong con hoac 1 ben khong con dan");
	gotoxy(3, 10); printf("Quan 1");
	gotoxy(63, 10); printf("Quan 2");
	gotoxy(15, 7); printf("1");
	gotoxy(25, 7); printf("2");
	gotoxy(35, 7); printf("3");
	gotoxy(45, 7); printf("4");
	gotoxy(55, 7); printf("5");
	gotoxy(15, 11); printf("5");
	gotoxy(25, 11); printf("4");
	gotoxy(35, 11); printf("3");
	gotoxy(45, 11); printf("2");
	gotoxy(55, 11); printf("1");
	gotoxy(5,25); printf("Nhan Enter de quay lai MENU");	
	gotoxy(5,27); printf("Hong Loan - 20203903");
	gotoxy(5,28); printf("Ky Thuat Lap Trinh C/C++");
	getchar();
	state = MENU;
}
void menu(){
	SetColor(14);
	system("cls");
    gotoxy(25,3);
	printf("Game: O AN QUAN");
	gotoxy(30,5);
	SetColor(4);
	printf("1. PLAY");
	gotoxy(30,6);
	printf("2. INFORMATION");
	int choice = 1;
	int oldChoice = 1;
	int next = 1;
	int key;
	SetColor(14);
	gotoxy(29,5);	printf("%c",16);
	while(state==MENU){
		if(kbhit()){
			key = getch();
			if(key==80) {
			choice++;
			if(choice ==4) choice = 1;
			}
			if(key==72) {
			choice --;
			if(choice == 0) choice = 3;
			}
		switch (choice) {
			case 1 :
				if(oldChoice!=choice){
				
				gotoxy(29,6);
				printf(" ");
				gotoxy(29,7);
				printf(" ");
				oldChoice = 1;	
				gotoxy(29,5);
				SetColor(14);
				printf("%c",16);
				}
				break;
			case 2 :
				if(oldChoice!=choice){
				gotoxy(29,5);
				printf(" ");
				gotoxy(29,7);
				printf(" ");
		        gotoxy(29,6);
		        SetColor(14);
				printf("%c",16);
				oldChoice = 2;
				}
				break;
		}
		if(key==13){
		switch (choice){
		case 1:			
			state = INGAME;
			break;
			case 2:
				state = INFORMATION;
				break;	
		}
		}	
	}
	}
}

int main(){
	state = MENU;
    menu();
while(1){
	switch (state){
		case MENU : 
		menu();
		break;
		case INGAME :
			ingame();
			break;
		break;
		case INFORMATION :
			information();
			break;
		case GAMEOVER:
			gameover();
			break;
	}	
}
}

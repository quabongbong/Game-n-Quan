#include<stdio.h>
#include<windows.h>
#include<conio.h>

enum state {MENU = 0, HUONGDAN, INGAME, GAMEOVER} state;

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

//cac buoc di
void phai1(int a[2][6], int j, int k){
	int x =1;
	a[1][j]=0;
	for(int i=j+1; i<6; i++){
		a[1][i]++;
		k--;
		if(k==0) break;
	}
}
void phai0(int a[2][6], int j, int k){
	int x=0;
	a[0][j]=0;
	for(int i =j+1; i<6; i++){
		a[0][i]++;
		k--;
		if(k==0) break;
	}
}
void trai1(int a[2][6], int j, int k){
	a[1][j]=0;
	int x=1;
	for(int i = j-1; i>=0; i--){
		a[1][i]++;
		k--;
		if(k==0) break;
	}
}
void trai0(int a[2][6], int j, int k){
	int x=0;
	a[0][j]=0;
	for(int i = j-1; i>=0; i--){
		a[1][i]++;
		k--;
		if(k==0) break;
	}
}
void chuyenLuotT(int a[2][6], int b[2], int player, int x, int y){
	if(a[x][y-1] == 0 && y!= 0){
		if(a[x][y-2] != 0){
			b[player] += a[x][y-2];
		}
	}
	else if(a[x][y-1] == 0 && y== 1){
		if(x == 0) x =1;
		else x = 0;
		if(a[x][y-2] != 0 && y == 1){
			b[player] += a[x][1];
		}
	}
}
void chuyenLuotP(int a[2][6], int b[2], int player, int x, int y){
	if(a[x][y+1] == 0 && y!= 5){
		if(a[x][y+2] != 0){
			b[player] += a[x][y+2];
		}
	}
	else if(a[x][y+1] == 0 && y== 5){
		if(x == 0) x =1;
		else x = 0;
		if(a[x][y+2] != 0 && y == 5){
			b[player] += a[x][5];
		}
	}
}
void nguoi1(int arr[2][6], int b[2]){
	int oDuocChon, player = 1, k1, k2, x, huongDi;
	int soSoiODC = arr[1][oDuocChon];
	if(kbhit()){
	huongDi = getch();
	}
	switch(huongDi){
	case 48:
		x=1;
		oDuocChon = 0;
		trai1(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			phai0(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 49:
		x=1;
		oDuocChon = 1;
		trai1(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			phai0(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 50:
		x=1;
		oDuocChon = 2;
		trai1(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			phai0(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 51:
		x=1;
		oDuocChon = 3;
		trai1(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			phai0(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 52:
		x=1;
		oDuocChon = 4;
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
		phai1(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			trai0(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	case 57:
		x=1;
		oDuocChon =5;
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
	int soSoiODC = arr[1][oDuocChon];
	if(kbhit()){
	huongDi = getch();
	}
	switch(huongDi){
	case 48:
		x=0;
		oDuocChon = 0;
		trai0(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			phai1(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 49:
		x=0;
		oDuocChon = 1;
		trai0(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			phai1(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 50:
		x=0;
		oDuocChon = 2;
		trai0(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			phai1(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 51:
		x=0;
		oDuocChon = 3;
		trai0(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			phai1(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 52:
		x=0;
		oDuocChon = 4;
		trai0(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			phai1(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 53:
		x=0;
		oDuocChon = 1;
		phai0(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			trai0(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	    break;
	case 54:
		x=0;
		oDuocChon =2;
		phai0(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			trai1(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
		break;
	case 55:
		x=0;
		oDuocChon =3;
		phai0(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			trai1(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
		break;
	case 56:
		x=0;
		oDuocChon =4;
		phai0(arr, oDuocChon, soSoiODC);
		if(soSoiODC!=0){
			x=0;
			trai1(arr, oDuocChon, soSoiODC);
		}
		else chuyenLuotT(arr, b, player, x, oDuocChon);
	case 57:
		x=0;
		oDuocChon =5;
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

//hien thi tren man hinh
void hienThi(int soSoi[2][6], int diemSo[2]){	
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
	int soSoi[2][6];

	for(int i = 0; i<2; i++){
    	for(int j = 0; j<6; j++){
    		if(j == 0) soSoi[i][j] = 10;
    		else soSoi[i][j] = 5;
		}
	}
    int diemSo[2] = {0,0};
    hienThi(soSoi, diemSo);
    
//main
    while(1){
		if(soSoi[1][0] == 0 | soSoi[0][6] == 0) break;
		nguoi1(soSoi, diemSo);
		diemSo[0] =0;
		for(int j = 0; j<6; j++){
    		diemSo[0] += soSoi[1][j];
		}
		hienThi(soSoi, diemSo);
		if(soSoi[0]==0) break;
		if(soSoi[1][0] == 0 | soSoi[0][6] == 0) break;
		nguoi2(soSoi, diemSo);
		diemSo[1] = 0;
		for(int j = 0; j<6; j++){
    		diemSo[1] += soSoi[0][j];
		}
		hienThi(soSoi, diemSo);
		if(soSoi[1]==0) break;
}
}

void gameover(int d[2]){
	gotoxy(10, 5);
	printf("Game Over!\n");
	if(d[0]> d[1]) printf("Player 1 Win");
	else printf("Player 2 Win");
}

void huongDan(){
	printf("Huong dan cach choi:\n");
	printf("Nguoi choi dung cac phim tu 0 - 9\n");
	printf("- Phim 0 - 4: chon tuong ung o 1 - 5 de rai soi sang trai\n");
	printf("- Phim 5 - 9: chon tuong ung o 1 - 5 de rai soi sang phai\n");
	printf("Tro choi ket thuc khi 2 quan bi deu khong con hoac 1 ben khong con dan\n");
	printf("Nhan 0 de quay lai MENU\n");	
}
void menu(){
	gotoxy(10, 5); printf("Game: O An Quan\n");
	gotoxy(10, 10); printf("Phim 1. Huong dan:\n");
	gotoxy(10, 15); printf("Phim 2. Choi game:\n");
}

int main(){
	int diemSo[2];
	while(1){
		switch(state){
			case MENU:
				menu();
				break;
			case INGAME:
				ingame();
				break;
			case HUONGDAN:
				huongDan();
				break;
		}
		}
	return 0;
}

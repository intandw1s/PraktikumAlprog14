#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Deklarasi Variabel
void hanoi(int n, char x, char y, char z);
void menu();
void hanoi_rekursif();
void hanoi_iteratif();

// Validasi
int input(){
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 48-57 BERNILAI "0-9"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
    	system("color 4F");
        printf("INPUT TIDAK VALID!\n");
        printf("Masukan Input Baru : ");
        input();
    }else{
    	system("color F0");
        val = atoi(angka);
        if(val>=1 && val<=10){
            return val;
        }else{
        	system("color 4F");
            printf("STACK OVERFLOW\n");
            printf("Masukan Input Baru : ");
            input();
        }
    }
}

int validasiPilihan(){
	int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 48-57 BERNILAI "0-9"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
    	system("color 4F");
        printf("INPUT TIDAK VALID!\n");
        printf("Masukan Input Baru : ");
        validasiPilihan();
    }else{
    	system("color F0");
        val = atoi(angka);
        if(val>=1 && val<=3){
            return val;
        }else{
        	system("color 4F");
            printf("INPUT TIDAK VALID!\n");
            printf("Masukan Input Baru : ");
            validasiPilihan();
        }
    }
}

// Menu Program
void menu() {
	int pilihan;
    printf("|===================================================|\n");
	printf("                    PROGRAM MENARA                   \n");
	printf("                         HANOI                       \n");
	printf("---------------------------------------------------- \n");
	printf("                 - Oleh Kelompok 14 -                \n");
	printf("|===================================================|\n\n");
	printf ("\Daftar Menu Pilihan : \n");
	printf("\t1. Menara Hanoi Rekursif\n");
	printf("\t2. Menara Hanoi Iteratif\n");
    printf("\t3. Keluar\n\n");
	printf("----------------------------------------------------\n");
	printf("\Masukan Menu Pilihan Anda: ");
	pilihan=input();
	system("cls");

	switch(pilihan){
		case 1 : {
			hanoi_rekursif();
			break;
		}case 2 :{
		    hanoi_iteratif();
            break;
        }default:{
            exit(0);
			break;
        }
	}
}

//Main
int main(){
	system("cls");
    system("COLOR F0");
    menu();
    return 0;
}
//Prosedur
void hanoi(int n, char x, char y, char z){
    char cakram=n+'0';
	cakram=cakram+16;
    if(n>0) {
		hanoi(n-1,x,z,y);
	  	printf("Pindahkan Cakram %c dari Tiang %c ke Tiang %c\n",cakram,x,z);
	    hanoi(n-1,y,x,z);
	}
}

void hanoi_rekursif(){
    int cakram,pilihan,hasil,x;

    printf("|===================================================|\n");
	printf("                    PROGRAM MENARA                   \n");
	printf("                         HANOI                       \n");
	printf("---------------------------------------------------- \n");
	printf("                     - REKURSIF -                    \n");
	printf("|===================================================|\n\n");
    printf("Masukan Jumlah Cakram : ");
    cakram=input();
    printf("\n----------------------------------------------------\n");

    hasil=pow(2,cakram)-1;
	printf ("\nJumlah Langkah Minimum Pemindahan Cakram adalah %d\n\n",hasil);
    printf("\Langkah - Langkah Pemindahan Cakram :\n\n");
    hanoi(cakram,'1','2','3');

    printf("\n====================================================\n");
    printf("       1.Ulangi        2.Menu         3.Keluar\n");
    printf("----------------------------------------------------\n");
    printf("Masukan Menu Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
        hanoi_rekursif();
	    break;
	    case 2:
	    menu();
	    break;
	    default:
	    exit(0);
	    break;
    }
}

void hanoi_iteratiff(){
    int cakram,pilihan,hasil,x;

    printf("|===================================================|\n");
	printf("                    PROGRAM MENARA                   \n");
	printf("                         HANOI                       \n");
	printf("---------------------------------------------------- \n");
	printf("                     - ITERATIF -                    \n");
	printf("|===================================================|\n\n");
    printf("Masukan Jumlah Cakram : ");
    cakram=input();
    printf("\n------------------------------------------------------\n");
    printf("\nLangkah - Langkah Pemindahan Cakram :\n\n");

    for(x=1;x<(1 << cakram);x++){
        char nama=cakram+'0';
        nama=nama+16;

        printf("Pindahkan Cakram %c dari Tiang %d ke Tiang %d\n", nama, ((x&(x-1))%cakram )+ 1,(((x|(x-1))+1)%cakram) + 1);
        hasil=pow(2,cakram)-1;
        }
    printf ("\nJumlah Langkah Minimum Menara Hanoi adalah %d\n",hasil);

    printf("\n======================================================\n");
    printf("       1.Ulangi        2.Menu         3.Keluar\n");
    printf("-----------------------------------------------------\n");
    printf("Masukan Menu Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
        hanoi_iteratiff();
	    break;
	    case 2:
	    menu();
	    break;
	    default:
	    exit(0);
	    break;
    }
}

void hanoi_iteratif(){
    int cakram,pilihan,hasil,x;
    int langkah = 1;

    printf("|===================================================|\n");
	printf("                    PROGRAM MENARA                   \n");
	printf("                         HANOI                       \n");
	printf("---------------------------------------------------- \n");
	printf("                     - ITERATIF -                    \n");
	printf("|===================================================|\n\n");
    printf("Masukan Jumlah Cakram : ");
    cakram=input();
    printf("\n----------------------------------------------------\n");

    hasil=pow(2,cakram)-1;
    printf ("\nJumlah Langkah Minimum Menara Hanoi adalah %d\n\n",hasil);
    printf("\Langkah - Langkah Pemindahan Cakram :\n\n");
    hanoi(cakram,'1','2','3');

    printf("\n=====================================================\n");
    printf("       1.Ulangi        2.Menu         3.Keluar\n");
    printf("-----------------------------------------------------\n");
    printf("Masukan Menu Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
        hanoi_iteratif();
	    break;
	    case 2:
	    menu();
	    break;
	    default:
	    exit(0);
	    break;
    }
}

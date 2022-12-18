#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//DEKLRASI PROSEDUR
void menu();
void bubble_sort(int angka[], int n);
void acak1();
void acak2();
void acak3();


//VALIDASI
int validasipilihan() {
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("\nHARAP MASUKKAN PILIHAN YANG SESUAI ^-^\n");
        printf("Silahkan masukkan ulang >.< : ");
        validasipilihan();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=3){
            return val;
        }else{
            printf("\nHARAP MASUKKAN PILIHAN YANG SESUAI ^-^\n");
            printf("Silahkan masukkan ulang >.< : ");
            validasipilihan();
        }
    }
}

int validasimenu(){
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("\nHARAP MASUKKAN PILIHAN YANG SESUAI ^-^\n");
        printf("Silahkan masukkan ulang >.< : ");
        validasimenu();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=4){
            return val;
        }else{
        printf("\nHARAP MASUKKAN PILIHAN YANG SESUAI ^-^\n");
        printf("Silahkan masukkan ulang >.< : ");
        validasimenu();
        }
    }
}

//MAIN
int main(){
    system("COLOR E8");
    menu();
    system("pause");
    return 0;
}
//COVER
void cover(){
    printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t|                 Hi! Halo! Ni Hao!               |\n");
    printf("\t\t\t\t|              ^0^ SELAMAT DATANG ^v^             |\n");
    printf("\t\t\t\t|.................................................|\n");
    printf("\t\t\t\t|             PROGRAM PENGURUTAN DATA             |\n");
    printf("\t\t\t\t|                   BUBBLE SORT                   |\n");
    printf("\t\t\t\t|.................................................|\n");
    printf("\t\t\t\t|                 BY : KELOMPOK 14                |\n");
    printf("\t\t\t\t|--------------------INTRUKSI---------------------|\n");
    printf("\t\t\t\t+=================================================+\n\n");
    printf("\t\t\t\t ---------IKUTI SETIAP PERINTAH DENGAN BENAR!---------\n");
    printf("\t\t\t\t !Masukkan apa saja untuk lanjut ke menu berikutnya!\n");
    getch();
    system("cls");
}

int sekalimuncul = 0;
void menu(){
    if (sekalimuncul != 1){
    cover();
    sekalimuncul=1;
    }
    int pilihan;

    printf("+=============================================+\n");
    printf("|              PROGRAM BUBBLE SORT            |\n");
    printf("|---------------------------------------------|\n");
    printf("|                  KELOMPOK-14                |\n");
    printf("+=============================================+\n");
    printf("1. 1000 Data | 2. 16000 Data  | 3. 64000 Data  \n");
    printf("             | 4. Keluar      |                \n");
    printf("-----------------------------------------------\n");
    printf("Masukkan Pilihan Anda : ");
    pilihan = validasimenu();
    system("cls");

	switch(pilihan){
	    case 1:
	    acak1();
	    break;
	    case 2:
	    acak2();
	    case 3:
	    acak3();
	    break;
	    default:
        printf("\t\t\t\t+=================================================+\n");
        printf("\t\t\t\t|                     PROGRAM                     |\n");
        printf("\t\t\t\t|                  TELAH BERHENTI                 |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t+=================================================+\n\n");
	    exit(0);
	    break;
    }
}


//BUBLE SORT BIASA & POINTER
void bubble_sort(int angka[], int n){
    clock_t waktu;
    int i, j, temp;
    float durasi[1];
    int *pangka = angka;
    int data=1;

    printf("+-------------------------------------------------------------------------------------------------------------+\n");
    printf("\t\t\t\t\t\tData Acak\n");
    printf("+-------------------------------------------------------------------------------------------------------------+\n\n");

    for(i=0; i<n; i++){
        printf("\t");
        for(j=0; j<=0; j++){
            printf("data no %d = ", data);
            printf("%d ", angka[i]);
            data += 1;
        }
        printf("\n");
	}

	waktu = clock();
	for(i=0; i<n-1; i++){
		for(j=0; j<n-1-i; j++){
			if(angka[j] > angka[j+1]){
				temp = angka[j];
				angka[j] = angka[j+1];
				angka[j+1] = temp;
			}
		}
	}
    waktu = clock() - waktu;
    durasi[0] = (float)(waktu) / CLOCKS_PER_SEC;

    waktu = clock();
	for(i=0; i<n-1; i++){
		for(j=0; j<n-1-i; j++){
			if(*(pangka+j) > *(pangka+j+1)){
				temp = *(pangka+j);
				*(pangka+j) = *(pangka+j+1);
				*(pangka+j+1) = temp;
			}
		}
	}
	waktu = clock() - waktu;
	durasi[1] = (float)(waktu) / CLOCKS_PER_SEC;

    data =1;
    printf("\n\n+-------------------------------------------------------------------------------------------------------------+\n");
    printf("\t\t\t\t\t\tSesudah Pengurutan\n");
    printf("+-------------------------------------------------------------------------------------------------------------+\n\n");
	for(i=0; i<n; i++){
        printf("\t");
        for(j=0; j<=0; j++){
            printf("data no %d = ", data);
            printf("%d ", angka[i]);
            data += 1;
        }
        printf("\n");
	}

	printf("\n\n");
	printf("+===================================+\n");
	printf("|          Waktu Pengurutan         |\n");
	printf("+-----------------------------------+\n");
	printf(" Cara biasa : %f detik             \n", durasi[0]);
	printf(" Pointer    : %f detik             \n", durasi[1]);
	printf("+===================================+\n\n\n");
}

//DATA ACAK 1000
void acak1(){
    int angka[1000], n, i, pilihan;

    n = sizeof(angka) / sizeof(angka[0]);
    srand((unsigned) time(NULL));

    for(i=0; i<n; i++){
		angka[i] = rand();
	}

	bubble_sort(angka, n);

    printf("=====================================\n");
    printf("1.Ulangi      2.Kembali     3.Keluar\n");
    printf("-------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasipilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    acak1();
	    break;
	    case 2:
	    menu();
	    break;
	    default:
        printf("\t\t\t\t+=================================================+\n");
        printf("\t\t\t\t|                     PROGRAM                     |\n");
        printf("\t\t\t\t|                  TELAH BERHENTI                 |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t+=================================================+\n\n");
	    exit(0);
	    break;
    }
}

//DATA ACAK 16000
void acak2(){
    int angka[16000], n, i, pilihan;

    n = sizeof(angka) / sizeof(angka[0]);
    srand((unsigned) time(NULL));

    for(i=0; i<n; i++){
		angka[i] = rand();
	}

	bubble_sort(angka, n);

    printf("=====================================\n");
    printf("1.Ulangi      2.Kembali     3.Keluar\n");
    printf("-------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasipilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    acak2();
	    break;
	    case 2:
	    menu();
	    break;
	    default:
        printf("\t\t\t\t+=================================================+\n");
        printf("\t\t\t\t|                     PROGRAM                     |\n");
        printf("\t\t\t\t|                  TELAH BERHENTI                 |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t+=================================================+\n\n");
	    exit(0);
	    break;
    }
}

//DATA ACAK 64000
void acak3(){
    int angka[64000], n, i, pilihan;

    n = sizeof(angka) / sizeof(angka[0]);
    srand((unsigned) time(NULL));

    for(i=0; i<n; i++){
		angka[i] = rand();
	}

	bubble_sort(angka, n);

    printf("=====================================\n");
    printf("1.Ulangi      2.Kembali     3.Keluar\n");
    printf("-------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasipilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    acak3();
	    break;
	    case 2:
	    menu();
	    break;
	    default:
        printf("\t\t\t\t+=================================================+\n");
        printf("\t\t\t\t|                     PROGRAM                     |\n");
        printf("\t\t\t\t|                  TELAH BERHENTI                 |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t+=================================================+\n\n");
	    exit(0);
	    break;
    }
}

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int fibonacci(int n);
void iteratif(int n);
void rekursif(int n);

void menu();
int main(){
	printf("===============================\n");
	printf("||      PROGRAM Fibonacci    ||\n");
	printf("||         Kelompok 14       ||\n");
	printf("===============================\n");
	menu();
    return 0;
}

//VALIDASI
int inputbilangan(){
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=48 && angka[i]<=57){ //PEMBATAS PADA ASCII DIMANA 48-57 BERNILAI "0-9"
        }
		else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("INPUT TIDAK SESUAI\n");
        printf("Masukkan input kembali : ");
        inputbilangan();
		}
		else{
        val = atoi(angka);
        if(val>=1){
            return val;
        }
		else{
            printf("INPUT TIDAK SESUAI\n");
            printf("Masukkan input kembali : ");
            inputbilangan();
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
        if(angka[i]>=48 && angka[i]<=57){ //PEMBATAS PADA ASCII DIMANA 48-57 BERNILAI "0-9"
        }
		else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("INPUT TIDAK SESUAI\n");
        printf("Masukkan input kembali : ");
        validasiPilihan();
    	}
	else{
        val = atoi(angka);
        if(val>=1 && val<=3){
            return val;
        }
		else{
            printf("INPUT TIDAK SESUAI\n");
            printf("Masukkan input kembali : ");
            validasiPilihan();
			}
    	}
}

//FUNGSI & PROSEDUR
void menu(); //deklarasi menu

int rekursiffibonacci(int j){
	int fibonancci;
	if(j==1||j==2){
		return 1;
	}
	else{
		fibonancci=rekursiffibonacci(j-1)+rekursiffibonacci(j-2);
		return fibonancci;
	}
}

int fibonacci(int n){
    if (n == 0){
        return 0;
    } else if (n == 1){
        return 1;
    } else {
       return fibonacci(n-2) + fibonacci(n-1);
    }
}

void iteratiffibonacci(){
	int n,i;
	int f1=1;
	int f2=1;
	int hasil;
	int pilihan;

	printf("===================================\n\n");
	printf("       PROGRAM DERET FIBONACCI     \n\n");
    printf("-------------------------------------\n");
    printf("              ITERATIF               \n");
	printf("===================================\n\n");
	printf("Masukkan Jumlah Deret yang Diinginkan: ");
	n=inputbilangan();

	printf("\n-----------------------------------\n");
    printf("DERET FIBONACCI : \n");
	for(i=1;i<=n;i++){
		if(i==1){
			hasil=f1;
		}
		else if(i==2){
			hasil=f2;
		}
		else{
			hasil=f1+f2;
			f1=f2;
			f2=hasil;
		}
		printf("%d ",hasil);
	}
    printf("\n\n================================\n");
    printf("       1.Ulangi  2.Kembali  3.Exit  \n");
    printf("------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
        iteratiffibonacci();
	    break;
	    case 2:
	    menu();
	    break;
	    default:
	    exit(0);
	    break;
    }
}

void rekursif(){
    int pilihan;
	int n,j;
	printf("===================================\n\n");
	printf("      PROGRAM DERET FIBONACCI      \n\n");
    printf("-------------------------------------\n");
    printf("             REKURSIF                \n");
	printf("===================================\n\n");
	printf("Masukkan Jumlah Deret yang diinginkan: ");
	n=inputbilangan();

    printf("\n-----------------------------------\n");
	printf("DERET FIBONACCI : \n");
	for(j=1;j<=n;j++){
		printf("%d ", rekursiffibonacci(j));
		}
    printf("\n\n=================================\n");
    printf("   1.Ulangi   2.Kembali    3.Exit    \n");
    printf("-------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
        rekursif();
	    break;
	    case 2:
	    menu();
	    break;
	    default:
	    exit(0);
	    break;
    }
}

//MENU
void menu(){
	int pilih;

	printf("============================\n\n");
	printf("   PROGRAM DERET FIBONACCI  \n\n");
	printf("============================\n\n");
	printf("\t1. Deret Fibonancci Rekursif\n");
	printf("\t2. Deret Fibonancci Iteratif\n");
	printf("\t3. Keluar\n");
	printf("------------------------------\n");
	printf("Masukkan Pilihan: ");
	pilih=validasiPilihan();
	system("cls");

	if(pilih==1){
		rekursif();
	}
	else if(pilih==2){
		iteratiffibonacci();
	}
	else{
		exit(0);
	}

}

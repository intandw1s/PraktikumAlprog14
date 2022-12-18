#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//DEKLRASI PROSEDUR
void menu();
void kubus();

//STRUCT DAN UNION
typedef struct {
int panjang, lp, vol;
}kubus_s;

typedef union{
int panjang, lp, vol;
}kubus_u;

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
        if(val>=1 && val<=2){
            return val;
        }else{
            printf("\nHARAP MASUKKAN PILIHAN YANG SESUAI ^-^\n");
            printf("Silahkan masukkan ulang >.< : ");
            validasipilihan();
        }
    }
}

float validasibilangan(){
    int i = 0;
    int salah =0;
    int titik=0;
    char angka[100];
    float val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    if(angka[0]>=48 && angka[0]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"

    }else{
        salah += 1;
    }

    for(i=1;i<array; i++){
        if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"

        }else if(angka[i]==46){ // PEMBATAS PADA ASCII DIMANA 45 BERNILAI "."
            titik += 1;
        }else{
            salah += 1;
        }
    }

    if(salah>0 || titik>1){
        printf("HARAP MASUKAN BILLANGAN YANG SESUAI^-^\n");
        printf("Silahkan masukkan ulang >.< : ");
        validasibilangan();
    }else{
        val = atof(angka);
        return val;
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
    printf("\t\t\t\t|             PROGRAM PERHITUNGAN KUBUS           |\n");
    printf("\t\t\t\t|               DENGAN STRUCT & UNION             |\n");
    printf("\t\t\t\t|.................................................|\n");
    printf("\t\t\t\t|                 BY : KELOMPOK 14                |\n");
    printf("\t\t\t\t|--------------------INTRUKSI---------------------|\n");
    printf("\t\t\t\t+=================================================+\n\n");
    printf("\t\t\t\t ---------IKUTI SETIAP PERINTAH DENGAN BENAR!---------\n");
    printf("\t\t\t\t !Masukkan apa saja untuk lanjut ke menu berikutnya!\n");
    getch();
    system("cls");
}

//MENU
int sekalimuncul = 0;
void menu(){
    if (sekalimuncul != 1){
    cover();
    sekalimuncul=1;
    }
    int pilihan;

    printf("+===================================================+\n");
    printf("|   PROGRAM PERHITUNGAN KUBUS DENGAN STRUCT/UNION   |\n");
    printf("|---------------------------------------------------|\n");
    printf("|                     KELOMPOK-14                   |\n");
    printf("+===================================================+\n");
    printf("                1. Mulai  | 2. Keluar             \n");
    printf("----------------------------------------------------\n");
    printf("Masukkan Pilihan Anda : ");
    pilihan = validasipilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    kubus();
	    break;
	    default:
        printf("\t\t\t\t+=================================================+\n");
        printf("\t\t\t\t|                     PROGRAM                     |\n");
        printf("\t\t\t\t|                  TELAH BERHENTI                 |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t+=================================================+\n\n");
	    exit(1);
	    break;
    }
}


//KUBUS
void kubus(){
    int panjangsisi, ukuran_memori[2],pilihan;
    kubus_s structs;
    kubus_u unions[3];
    printf("======================================================================\n");
    printf("                         KUBUS STRUCT & UNION                         \n");
    printf("----------------------------------------------------------------------\n");
    printf("                              KELOMPOK 14                             \n");
    printf("======================================================================\n");
    printf("Masukkan panjang sisi kubus : ");
    panjangsisi=validasibilangan();
    printf(".\n");
    printf(".\n");
    printf(".\n");

    structs.panjang = panjangsisi;
    structs.lp      = 6 * structs.panjang * structs.panjang;
    structs.vol  = structs.panjang * structs.panjang * structs.panjang;
    ukuran_memori[0]=sizeof(kubus_s);

    unions[0].panjang = panjangsisi;
    unions[1].lp      = 6 * unions[0].panjang * unions[0].panjang;
    unions[2].vol  = unions[0].panjang * unions[0].panjang * unions[0].panjang;
    ukuran_memori[1]=sizeof(kubus_u);

    printf("+--------------------------------------+\n");
    printf("|                Struct                |\n");
    printf("+--------------------------------------+\n");
    printf("   Panjang Sisi   : %d \n", structs.panjang);
    printf("   Luas Permukaan : %d      \n", structs.lp);
    printf("   Volume Kubus   : %d  \n", structs.vol);
    printf("========================================\n");
    printf("   Ukuran Memori  : %d\n\n",ukuran_memori[0]);
    printf("+--------------------------------------+\n");
    printf("|                Union                 |\n");
    printf("+--------------------------------------+\n");
    printf("   Panjang Sisi   : %d       \n", unions[0]);
    printf("   Luas Permukaan : %d       \n", unions[1]);
    printf("   Volume Kubus   : %d       \n", unions[2]);
    printf("========================================\n");
    printf("   Ukuran Memori  : %d\n", ukuran_memori[1]);
    printf("........................................\n");
    printf("    1.Ulangi         |    2.Kembali     \n");
    printf("========================================\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasipilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    kubus();
	    break;
	    default:
	    menu();
    }
}

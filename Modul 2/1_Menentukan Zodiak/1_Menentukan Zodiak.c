#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//  DEKLARASI PROSEDUR
void cover();
void zodiak();

//  VALIDASI
int validasitahun(){
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
        printf("\nHARAP MASUKKAN TAHUN YANG SESUAI ^-^\n");
        printf("Silahkan masukkan ulang >.< : ");
        validasitahun();
    }else{
        val = atoi(angka);
        if(val>=1000 && val<=2021){
            return val;
        }else{
            printf("\nHARAP MASUKKAN TAHUN YANG SESUAI ^-^\n");
            printf("Silahkan masukkan ulang >.< : ");
            validasitahun();
        }
    }
}

int validasitanggal(){
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
        printf("\nHARAP MASUKKAN TANGGAL YANG SESUAI ^-^\n");
        printf("Silahkan masukkan ulang >.< : ");
        validasitanggal();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=31){
            return val;
        }else{
            printf("\nHARAP MASUKKAN TANGGAL YANG SESUAI ^-^\n");
            printf("Silahkan masukkan ulang >.< : ");
            validasitanggal();
        }
    }
}

int validasibulan(){
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
        printf("\nHARAP MASUKKAN BULAN YANG SESUAI ^-^\n");
        printf("Silahkan masukkan ulang >.< : ");
        validasibulan();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=12){
            return val;
        }else{
            printf("\nHARAP MASUKKAN BULAN YANG SESUAI ^-^\n");
            printf("Silahkan masukkan ulang >.< : ");
            validasibulan();
        }
    }
}


int validasipilihan(){
	int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=49 && angka[i]<=50){ // PEMBATAS PADA ASCII DIMANA 49-50 BERNILAI "1-2"

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

//MAIN
int main(){
    system("COLOR F5");
    zodiak();
    system("pause");
    return 0;
}

//COVER
void cover(){
    printf("\t\t\t\t+=================================================+\n");
    printf("\t\t\t\t|                 Hi! Halo! Ni Hao!               |\n");
    printf("\t\t\t\t|              ^0^ SELAMAT DATANG ^v^             |\n");
    printf("\t\t\t\t|.................................................|\n");
    printf("\t\t\t\t|                PROGRAM MENENTUKAN               |\n");
    printf("\t\t\t\t|                     ZODIAK                      |\n");
    printf("\t\t\t\t|.................................................|\n");
    printf("\t\t\t\t|                 BY : KELOMPOK 14                |\n");
    printf("\t\t\t\t|--------------------INTRUKSI---------------------|\n");
    printf("\t\t\t\t+=================================================+\n\n");
    printf("\t\t---------IKUTI SETIAP PERINTAH AGAR ANDA MENGETAHUI ZODIAK YANG BENAR!---------\n");
    printf("\t\t\t\t !Masukkan apa saja untuk lanjut ke menu berikutnya!\n");
    getch();
    system("cls");
}

// ZODIAK
int sekalimuncul = 0;
void zodiak(){
    if (sekalimuncul != 1){
    cover();
    sekalimuncul=1;
    }
	int tanggal;
	int bulan;
	int pilihan;
	int tahun;

    printf("=================================================================\n\n");
	printf("                     PROGRAM MENENTUKAN ZODIAK                   \n\n");
	printf("=================================================================  \n");
    printf("                          Daftar Bulan                             \n");
    printf("-----------------------------------------------------------------  \n");
    printf("     <1> Januari    <2> Februari    <3> Maret      <4> April       \n");
    printf("     <5> Mei        <6> Juni        <7> Juli       <8> Agustus     \n");
    printf("     <9> September  <10> Oktober    <11> November  <12> Desember   \n");
    printf("=================================================================  \n");
    printf("Masukkan Tahun Lahir Anda : ");
    tahun=validasitahun();
    printf("Masukkan Tanggal Lahir Anda (1-31): ");
    tanggal=validasitanggal();
    printf("Masukkan Bulan Lahir Anda (1-12)  : ");
    bulan=validasibulan();
    printf("-----------------------------------------------------------------  \n");

    if((tahun%400==0||tahun%100==0||tahun%4==0)&&(bulan==2&&tanggal==29)){
        printf("\t\t Zodiak Anda adalah 'Pisces'\n");
    }else{
        if((tanggal>=21 && tanggal<=31 && bulan==3)||(tanggal>=1 && tanggal<=19 &&bulan==4)){
            printf("\t\t   Zodiak Anda adalah 'Aries'\n");
        }else if ((tanggal>=20&&tanggal<=30&&bulan==4)||(tanggal>=1&&tanggal<=20&&bulan==5)){
            printf("\t\t   Zodiak Anda adalah 'Taurus'\n");
        }else if((tanggal>=21&&tanggal<=31&&bulan==5)||(tanggal>=1&&tanggal<=20&&bulan==6)){
            printf("\t\t   Zodiak Anda adalah 'Gemini'\n");
        }else if((tanggal>=21&&tanggal<=30&&bulan==6)||(tanggal>=1&&tanggal<=22&&bulan==7)){
            printf("\t\t   Zodiak Anda adalah 'Cancer'\n");
        }else if((tanggal>=23&&tanggal<=31&&bulan==7)||(tanggal>=1&&tanggal<=22&&bulan==8)){
            printf("\t\t   Zodiak Anda adalah 'Leo'\n");
        }else if((tanggal>=23&&tanggal<=31&&bulan==8)||(tanggal>=1&&tanggal<=22&&bulan==9)){
            printf("\t\t   Zodiak Anda adalah 'Virgo'\n");
        }else if((tanggal>=23&&tanggal<=30&&bulan==9)||(tanggal>=1&&tanggal<=22&&bulan==10)){
            printf("\t\t   Zodiak Anda adalah 'Libra'\n");
        }else if((tanggal>=23&&tanggal<=31&&bulan==10)||(tanggal>=1&&tanggal<=21&&bulan==11)){
            printf("\t\t   Zodiak Anda adalah 'Scorpio'\n");
        }else if((tanggal>=22&&tanggal<=30&&bulan==11)||(tanggal>=1&&tanggal<=21&&bulan==12)){
            printf("\t\t   Zodiak Anda adalah 'Sagitarius'\n");
        }else if((tanggal>=22&&tanggal<=31&&bulan==12)||(tanggal>=1&&tanggal<=19&&bulan==1)){
            printf("\t\t   Zodiak Anda adalah 'Capricon'\n");
        }else if((tanggal>=20&&tanggal<=31&&bulan==1)||(tanggal>=1&&tanggal<=18&&bulan==2)){
            printf("\t\t   Zodiak Anda adalah 'Aquarius'\n");
        }else if((tanggal>=19&&tanggal<=28&&bulan==2)||(tanggal>=1&&tanggal<=20&&bulan==3)){
            printf("\t\t   Zodiak Anda adalah 'Pisces'\n");
        }else{
            printf("Pilihan anda tidak tersedia\n");
            printf("Zodiak tidak ditemukan -_-\n");
            printf("Pastikan tahun, tanggal dan bulan yang anda masukkan sudah benar ^.^\n");
			}
		}

    printf("=================================================================  \n");
    printf("                 1.Ulangi      atau      2.Keluar                  \n");
    printf("-----------------------------------------------------------------  \n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasipilihan();
    system("cls");

	switch(pilihan){
	    case 1:
        zodiak();
	    break;
	    default:
	    printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|    ^o^ TERIMAKASIH & SAMPAI JUMPA KEMBALI ^v^   |\n");
        printf("\t\t\t\t|=================================================|\n\n");
        exit(0);
    }
}

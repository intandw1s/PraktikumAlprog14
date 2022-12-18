#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define PHI 3.14

//FUNGSI VOLUME
float hitung_vol_tabung(float jari2, float tinggi){
	float vol;
    vol = PHI*(jari2*jari2)*tinggi;
	return vol;
}

float hitung_vol_bola(float jari2){
	float vol;
	vol= 4.0/3.0*PHI*jari2*jari2*jari2;
	return vol;
}

float hitung_vol_limas_segiempat(float sisialas, float tinggi){
    float vol;
    vol =  1.0/3.0*(sisialas*sisialas)*tinggi;
    return vol;
}

float hitung_vol_prisma_segitiga(float alasAlas, float tinggiAlas, float tinggiprisma){
    float vol;
    vol = 1.0/2.0*alasAlas*tinggiAlas*tinggiprisma;
    return vol;
}

float hitung_vol_kerucut(float jari2, float tinggi){
    float vol;
    vol = 1.0/3.0*PHI*jari2*jari2*tinggi;
    return vol;
}

//FUNGSI LUAS PERMUKAAN
float hitung_LP_tabung(float jari2, float tinggi){
	float LP = 2*PHI*jari2*(jari2+tinggi);
	return LP;
}

float hitung_LP_bola(float jari2){
	float LP;
	LP = 4*PHI*jari2*jari2;
	return LP;
}

float hitung_LP_limas_segiempat(float sisialas, float tinggilimas){
	float tinggisegitiga = sqrt(pow(sisialas/2,2) + pow(tinggilimas,2));
	float LP ;
	LP = (sisialas*sisialas) + (4*1/2*sisialas*tinggisegitiga);
    return LP;
}

float hitung_LP_prisma_segitiga(float sisiAlas, float tinggiAlas, float sisimiring, float tinggiprisma){
	float LP;
	LP = (2*1/2*sisiAlas*tinggiAlas) + ((sisiAlas+tinggiAlas+sisimiring)*tinggiprisma);
    return LP;
}

float hitung_LP_kerucut(float jari2, float tinggi){
	float pelukis = sqrt(pow(jari2,2) + pow(tinggi,2));
	float LP;
    LP= (PHI*(jari2*jari2))+(PHI*jari2*pelukis);
    return LP;
}

//=====================================================================
//FUNGSI VALIDASI INPUT
//Cek Menu
int validasimenu (){
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=49 && angka[i]<=54){ // PEMBATAS PADA ASCII DIMANA 49-54 BERNILAI "1-6"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("\nMAAF INPUTAN ANDA TIDAK SESUAI\n\n");
        printf("Silahkan Masukkan Ulang Pilihan Menu : ");
        validasimenu();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=6){
            return val;
        }else{
            printf("\nMAAF INPUTAN ANDA TIDAK SESUAI\n\n");
            printf("Silahkan Masukkan Ulang Pilihan Menu : ");
            validasimenu();
        }
    }
}
//Cek Pilihan
int validasiPilihan (){
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=49 && angka[i]<=52){ // PEMBATAS PADA ASCII DIMANA 49-52 BERNILAI "1-4"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("\nMAAF INPUTAN ANDA TIDAK SESUAI\n\n");
        printf("Silahkan Masukkan Ulang Pilihan Menu : ");
        validasiPilihan();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=4){
            return val;
        }else{
            printf("\nMAAF INPUTAN ANDA TIDAK SESUAI\n\n");
            printf("Silahkan Masukkan Ulang Pilihan Menu : ");
            validasiPilihan();
        }
    }
}

//Cek Pilihan
int validasi(){
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=49 && angka[i]<=51){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "1-3"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("\nMAAF INPUTAN ANDA TIDAK SESUAI\n\n");
        printf("Silahkan Masukkan Ulang Pilihan Menu : ");
        validasi();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=3){
            return val;
        }else{
            printf("\nMAAF INPUTAN ANDA TIDAK SESUAI\n\n");
            printf("Silahkan Masukkan Ulang Pilihan Menu : ");
            validasi();
        }
    }
}
//Cek Bilangan
float validasiBil(){
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
        printf("\nHARAP MASUKAN BILLANGAN YANG SESUAI\n");
        printf("Silahkan masukkan ulang : ");
        validasiBil();
    }else{
        val = atof(angka);
        return val;
    }
}

//MENU COVER
void menu(){
    printf("\t\t\t\t|=================================================|\n");
    printf("\t\t\t\t|              PROGRAM PERHITUNGAN                |\n");
    printf("\t\t\t\t|            VOLUME & LUAS PERMUKAAN              |\n");
    printf("\t\t\t\t|.................................................|\n");
    printf("\t\t\t\t|      PROGRAM INI DIBUAT OLEH KELOMPOK 14        |\n");
    printf("\t\t\t\t|.................................................|\n");
    printf("\t\t\t\t|--------------------INTRUKSI---------------------|\n");
    printf("\t\t\t\t|=================================================|\n\n\n\n");
    printf("\t\t---------IKUTI SETIAP PERINTAH AGAR ANDA MENDAPATKAN PERHITUNGAN YANG BENAR!---------\n");
    printf("\t\t\t\t !Masukkan apa saja untuk lanjut ke menu berikutnya!\n");
    getch();
    system("cls");
}
//MENU
int sekalimuncul = 0;
int main(){
    if (sekalimuncul != 1){
    menu();
    sekalimuncul=1;
    }
    int pilihan;
    printf("\t\t\t\t|=================================================|\n");
    printf("\t\t\t\t|              PROGRAM PERHITUNGAN                |\n");
    printf("\t\t\t\t|                  BANGUN RUANG                   |\n");
    printf("\t\t\t\t|.................................................|\n");
    printf("\t\t\t\t|            LUAS PERMUKAAN & VOLUME              |\n");
    printf("\t\t\t\t|=================================================|\n\n");
    printf("Pilihan Menu :\n\n");
    printf("\t1.Volume Bangun Ruang\n");
    printf("\t2.Luas Permukaan Bangun Ruang\n");
    printf("\t3.Keluar\n");
    printf("-------------------------------------------------\n");
    printf("\nMasukan Nomor Menu(1 untuk Volume, 2 untuk Luas Permukaan, 3 untuk Keluar) : ");
    pilihan = validasi();
    printf("\n");
    system("cls");


    switch (pilihan){
	    case 1:
	    Volumebangunruang();
	    break;
	    case 2:
	    LuasPermukaanbangunruang();
	    break;
	    default:
        printf("PROGRAM TELAH BERHENTI\n\n");
	    break;
	 }
}

// Sub Menu Volume
int Volumebangunruang(){
  	int pilihan;

    printf("\t\t\t\t|=================================================|\n");
    printf("\t\t\t\t|              PROGRAM PERHITUNGAN                |\n");
    printf("\t\t\t\t|                  BANGUN RUANG                   |\n");
    printf("\t\t\t\t|.................................................|\n");
    printf("\t\t\t\t|                     VOLUME                      |\n");
    printf("\t\t\t\t|=================================================|\n\n");
    printf("Pilih Bangun Ruang Dibawah \n");
    printf("\t1.Tabung \n");
    printf("\t2.Bola \n");
    printf("\t3.Limas Segiempat\n");
    printf("\t4.Prisma Segitiga\n");
    printf("\t5.Kerucut \n");
    printf("\t6.Kembali \n");
    printf("-----------------------------------------------------------\n");
    printf("\nMasukan Nomor Menu (Pilih 1/2/3/4/5/6) : ");
    pilihan = validasimenu();
    printf("\n");
    system("cls");

    switch (pilihan){
        case 1:
	    volTabung();
	    break;
	    case 2:
	    volBola();
        case 3:
	    volLimasSegiempat();
	    break;
	    case 4:
	    volPrismaSegitiga();
	    break;
	    case 5:
	    volKerucut();
	    break;
	    default:
	    main();
	    break;
	 }

}

// Volume Tabung
int volTabung(){
	float jari2;
	float tinggi;
	float vol;
	int pilihan;

    printf("+===========================================================+\n");
    printf("|                 PROGRAM MENGHITUNG VOLUME                 |\n");
    printf("|-----------------------------------------------------------|\n");
    printf("|                           Tabung                          |\n");
    printf("+===========================================================+\n\n");
    printf("Masukan Panjang Jari-Jari Alas (cm) : ");
    jari2 = validasiBil();
    printf("Masukan Tinggi Tabung (cm) : ");
    tinggi = validasiBil();
    printf("------------------------------------------------------------\n\n");
    vol = hitung_vol_tabung(jari2, tinggi);
    printf("Volume Tabung adalah : %.2f cm3\n",vol);
    printf("\n\n=============================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU       4.Keluar  \n");
    printf("-------------------------------------------------------------\n");
    printf("\nMasukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    volTabung();
	    break;
	    case 2:
	    Volumebangunruang();
	    break;
	    case 3:
	    main();
	    break;
	    default:
        printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|         MASUKKAN APA SAJA UNTUK KELUAR!         |\n");
        printf("\t\t\t\t|=================================================|\n\n");
        break;
	 }
}

// Volume Bola
int volBola(){
    float jari2;
	float vol;
	int pilihan;

    printf("+===========================================================+\n");
    printf("|                 PROGRAM MENGHITUNG VOLUME                 |\n");
    printf("|-----------------------------------------------------------|\n");
    printf("|                          Bola                             |\n");
    printf("+===========================================================+\n\n");
    printf("Masukan Panjang Jari-Jari Bola (cm) : ");
    jari2 = validasiBil();
    vol= hitung_vol_bola(jari2);
    printf("------------------------------------------------------------\n\n");
    printf("Volume Prisma Segitiga adalah : %.2f cm2\n",vol);

    printf("\n\n=============================================================\n");
       printf("     1.Ulangi      2.Kembali       3.MENU       4.Keluar \n");
    printf("-------------------------------------------------------------\n");
    printf("\nMasukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    volBola();
	    break;
	    case 2:
	    Volumebangunruang();
	    break;
	    case 3:
	    main();
	    break;
	    default:
        printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|         MASUKKAN APA SAJA UNTUK KELUAR!         |\n");
        printf("\t\t\t\t|=================================================|\n\n");
        break;
	 }
}

// Volume Limas Segiempat
int volLimasSegiempat(){
	float sisialas;
	float tinggi;
	float vol;
	int pilihan;

    printf("+===========================================================+\n");
    printf("|                 PROGRAM MENGHITUNG VOLUME                 |\n");
    printf("|-----------------------------------------------------------|\n");
    printf("|                      Limas Segiempat                      |\n");
    printf("+===========================================================+\n\n");
    printf("Masukan Panjang Sisi Alas (cm) : ");
    sisialas = validasiBil();
    printf("Masukan Tinggi (cm) : ");
    tinggi = validasiBil();
    printf("------------------------------------------------------------\n\n");
    vol = hitung_vol_limas_segiempat(sisialas, tinggi);
    printf("Volume Limas Segiempat adalah : %.2f cm3\n",vol);
    printf("\n\n=============================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU       4.Keluar  \n");
    printf("-------------------------------------------------------------\n");
    printf("\nMasukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    volLimasSegiempat();
	    break;
	    case 2:
	    Volumebangunruang();
	    break;
	    case 3:
	    main();
	    break;
	    default:
        printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|         MASUKKAN APA SAJA UNTUK KELUAR!         |\n");
        printf("\t\t\t\t|=================================================|\n\n");
        break;
	 }
}

// Volume Prisma Segitiga
int volPrismaSegitiga(){
    float alasAlas;
	float tinggiAlas;
	float tinggiprisma;
	float vol;
	int pilihan;

    printf("+===========================================================+\n");
    printf("|                 PROGRAM MENGHITUNG VOLUME                 |\n");
    printf("|-----------------------------------------------------------|\n");
    printf("|                      Prisma Segitiga                      |\n");
    printf("+===========================================================+\n\n");
    printf("Masukan Panjang Sisi Alas pada Alas (cm) : ");
    alasAlas = validasiBil();
    printf("Masukan Tinggi Alas (cm) : ");
    tinggiAlas = validasiBil();
    printf("Masukan Tinggi Prisma (cm) : ");
    tinggiprisma = validasiBil();
    vol= hitung_vol_prisma_segitiga(alasAlas, tinggiAlas, tinggiprisma);
    printf("------------------------------------------------------------\n\n");
    printf("Volume Prisma Segitiga adalah : %.2f cm2\n",vol);

    printf("\n\n=============================================================\n");
       printf("     1.Ulangi      2.Kembali       3.MENU       4.Keluar \n");
    printf("-------------------------------------------------------------\n");
    printf("\nMasukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    volPrismaSegitiga();
	    break;
	    case 2:
	    Volumebangunruang();
	    break;
	    case 3:
	    main();
	    break;
	    default:
        printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|         MASUKKAN APA SAJA UNTUK KELUAR!         |\n");
        printf("\t\t\t\t|=================================================|\n\n");
        break;
	 }
}


// Volume Kerucut
int volKerucut(){
	float jari2;
	float tinggi;
	float vol;
	int pilihan;

    printf("+===========================================================+\n");
    printf("|                 PROGRAM MENGHITUNG VOLUME                 |\n");
    printf("|-----------------------------------------------------------|\n");
    printf("|                         Kerucut                           |\n");
    printf("+===========================================================+\n\n");
    printf("Masukan Panjang Jari-Jari (cm) : ");
    jari2 = validasiBil();
    printf("Masukan Tinggi (cm) : ");
    tinggi = validasiBil();
    printf("------------------------------------------------------------\n\n");
    vol = hitung_vol_kerucut( jari2, tinggi);
    printf("Volume Kerucut adalah : %.2f cm3\n",vol);

    printf("\n\n=============================================================\n");
    printf("     1.Ulangi      2.Kembali       3.MENU       4.Keluar \n");
    printf("-------------------------------------------------------------\n");
    printf("\nMasukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    volKerucut();
	    break;
	    case 2:
	    Volumebangunruang();
	    case 3:
	    main();
	    break;
	    default:
        printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|         MASUKKAN APA SAJA UNTUK KELUAR!         |\n");
        printf("\t\t\t\t|=================================================|\n\n");
        break;
	 }
}

// Sub Menu Luas Permukaan
int  LuasPermukaanbangunruang(){
  	int pilihan;

    printf("\t\t\t\t|=================================================|\n");
    printf("\t\t\t\t|              PROGRAM PERHITUNGAN                |\n");
    printf("\t\t\t\t|                  BANGUN RUANG                   |\n");
    printf("\t\t\t\t|.................................................|\n");
    printf("\t\t\t\t|                 LUAS PERMUKAAN                  |\n");
    printf("\t\t\t\t|=================================================|\n\n");
    printf("Pilih Bangun Ruang Dibawah :\n");
    printf("\t1.Tabung\n");
    printf("\t2.Bola\n");
    printf("\t3.Limas Segiempat\n");
    printf("\t4.Prisma Segitiga\n");
    printf("\t5.Kerucut \n");
    printf("\t6.Kembali\n");
    printf("-----------------------------------------------------------\n");
    printf("\nMasukan Nomor Menu : ");
    pilihan = validasimenu();
    system("cls");

    switch (pilihan){
        case 1:
        LPtabung();
	    break;
	    case 2:
	    LPbola();
	    break;
	    case 3:
        LPlimassegiempat();
	    break;
	    case 4:
	    LPprismasegitiga();
	    break;
	    case 5:
	    LPkerucut();
	    break;
	    default:
	    main();
	    break;
	 }
}

// Luas Permukaan Tabung
int LPtabung(){
    float jari2;
	float tinggi;
	float LP;
	int pilihan;

    printf("+===========================================================+\n");
    printf("|              PROGRAM MENGHITUNG LUAS PERMUKAAN            |\n");
    printf("|-----------------------------------------------------------|\n");
    printf("|                          Tabung                           |\n");
    printf("+===========================================================+\n\n");
    printf("Masukan Panjang Jari-Jari Alas(cm) : ");
    jari2 = validasiBil();
    printf("Masukan Tinggi Tabung (cm) : ");
    tinggi = validasiBil();
    printf("-------------------------------------------------------------\n");
    LP = hitung_LP_tabung(jari2, tinggi);
    printf("Luas Permukaan Limas Segiempat adalah : %.2f cm2\n",LP);

    printf("\n\n=============================================================\n");
    printf("     1.Ulangi      2.Kembali       3.MENU       4.Keluar \n");
    printf("-------------------------------------------------------------\n");
    printf("\nMasukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    LPtabung();
	    break;
	    case 2:
	    LuasPermukaanbangunruang();
	    case 3:
	    main();
	    break;
	    default:
        printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|         MASUKKAN APA SAJA UNTUK KELUAR!         |\n");
        printf("\t\t\t\t|=================================================|\n\n");
        break;
	 }
}

// Luas Permukaan Bola
int LPbola(){
    float jari2;
	float LP;
	int pilihan;

    printf("+===========================================================+\n");
    printf("|              PROGRAM MENGHITUNG LUAS PERMUKAAN            |\n");
    printf("|-----------------------------------------------------------|\n");
    printf("|                             Bola                          |\n");
    printf("+===========================================================+\n\n");
    printf("Masukan Panjang Jari-Jari Bola(cm) : ");
    jari2 = validasiBil();
    printf("-------------------------------------------------------------\n");
    LP = hitung_LP_bola(jari2);
    printf("Luas Permukaan Bola adalah : %.2f cm2\n",LP);

    printf("\n\n=============================================================\n");
    printf("     1.Ulangi      2.Kembali       3.MENU       4.Keluar \n");
    printf("-------------------------------------------------------------\n");
    printf("\nMasukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    LPbola();
	    break;
	    case 2:
	    LuasPermukaanbangunruang();
	    case 3:
	    main();
	    break;
	    default:
        printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|         MASUKKAN APA SAJA UNTUK KELUAR!         |\n");
        printf("\t\t\t\t|=================================================|\n\n");
        break;
	 }
}

// Luas Permukaan Limas Segiempat
int LPlimassegiempat(){
    float sisialas;
	float tinggilimas;
	float LP;
	int pilihan;

    printf("+===========================================================+\n");
    printf("|              PROGRAM MENGHITUNG LUAS PERMUKAAN            |\n");
    printf("|-----------------------------------------------------------|\n");
    printf("|                       Limas Segiempat                     |\n");
    printf("+===========================================================+\n\n");
    printf("Masukan Panjang Sisi Alas (cm) : ");
    sisialas = validasiBil();
    printf("Masukan Tinggi Limas (cm) : ");
    tinggilimas = validasiBil();
    printf("-------------------------------------------------------------\n");
    LP = hitung_LP_limas_segiempat(sisialas, tinggilimas);
    printf("Luas Permukaan Limas Segiempat adalah : %.2f cm2\n",LP);

    printf("\n\n=============================================================\n");
    printf("     1.Ulangi      2.Kembali       3.MENU       4.Keluar \n");
    printf("-------------------------------------------------------------\n");
    printf("\nMasukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    LPlimassegiempat();
	    break;
	    case 2:
	    LuasPermukaanbangunruang();
	    case 3:
	    main();
	    break;
	    default:
        printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|         MASUKKAN APA SAJA UNTUK KELUAR!         |\n");
        printf("\t\t\t\t|=================================================|\n\n");
        break;
	 }
}
// Luas Permukaan Prisma Segitiga
int LPprismasegitiga(){
    float sisialas;
	float tinggialas;
	float sisimiring;
	float tinggiprisma;
	float LP;
	int pilihan;

    printf("+===========================================================+\n");
    printf("|              PROGRAM MENGHITUNG LUAS PERMUKAAN            |\n");
    printf("|-----------------------------------------------------------|\n");
    printf("|                       Prisma Segitiga                     |\n");
    printf("+===========================================================+\n\n");
    printf("Masukan Panjang Sisi Alas (cm) : ");
    sisialas = validasiBil();
    printf("Masukan Tinggi Alas (cm) : ");
    tinggialas = validasiBil();
    printf("Masukan Panjang Sisi Miring (cm) : ");
    sisimiring = validasiBil();
    printf("Masukan Tinggi Prisma (cm) : ");
    tinggiprisma = validasiBil();
    printf("-------------------------------------------------------------\n");
    LP = hitung_LP_prisma_segitiga(sisialas, tinggialas, sisimiring, tinggiprisma);
    printf("Luas Permukaan Prisma Segitiga adalah : %.2f cm2\n",LP);

    printf("\n\n=============================================================\n");
       printf("     1.Ulangi      2.Kembali       3.MENU       4.Keluar \n");
    printf("-------------------------------------------------------------\n");
    printf("\nMasukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    LPprismasegitiga();
	    break;
	    case 2:
	    LuasPermukaanbangunruang();
	    case 3:
	    main();
	    break;
	    default:
        printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|         MASUKKAN APA SAJA UNTUK KELUAR!         |\n");
        printf("\t\t\t\t|=================================================|\n\n");
        break;
	 }
}

// Luas Permukaan Kerucut
int LPkerucut(){
    float jari2;
	float tinggi;
	float LP;
	int pilihan;

    printf("+===========================================================+\n");
    printf("|              PROGRAM MENGHITUNG LUAS PERMUKAAN            |\n");
    printf("|-----------------------------------------------------------|\n");
    printf("|                          Kerucut                          |\n");
    printf("+===========================================================+\n\n");
    printf("Masukan Panjang Jari-jari (cm) : ");
    jari2 = validasiBil();
    printf("Masukan Tinggi (cm) : ");
    tinggi = validasiBil();
    printf("-------------------------------------------------------------\n");
    LP = hitung_LP_kerucut( jari2, tinggi);
    printf("Luas Permukaan Kerucut adalah : %.2f cm2\n",LP);
    printf("\n\n=============================================================\n");
    printf("     1.Ulangi      2.Kembali       3.MENU       4.Keluar \n");
    printf("-------------------------------------------------------------\n");
    printf("\nMasukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    LPkerucut();
	    break;
	    case 2:
        LuasPermukaanbangunruang();
	    case 3:
	    main();
	    break;
	    default:
        printf("\t\t\t\t|=================================================|\n");
        printf("\t\t\t\t|                   PROGRAM                       |\n");
        printf("\t\t\t\t|                TELAH BERHENTI                   |\n");
        printf("\t\t\t\t|.................................................|\n");
        printf("\t\t\t\t|         MASUKKAN APA SAJA UNTUK KELUAR          |\n");
        printf("\t\t\t\t|=================================================|\n\n");
        break;
	 }
}

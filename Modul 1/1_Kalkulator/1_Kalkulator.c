#include <stdio.h>
#include<stdlib.h>

//Pengecekan Ulang
int cek_ulang(){
     int ulang;
     char huruf;
     scanf("%i%c",&ulang,&huruf);
     if((huruf!='\n')||(ulang<1||ulang>3)){
        printf("INPUTAN ANDA SALAH MOHON MASUKKAN ULANG\n");
        printf("Masukkan input : ");
        fflush(stdin);
        return cek_ulang();
    }
        else{
        return ulang;
    }
}

//Pengecekan Menu
int cek_menu(){
     int ulang;
     char huruf;
     scanf("%i%c",&ulang,&huruf);
     if((huruf!='\n')||(ulang<1||ulang>5)){
        printf("INPUTAN MENU ANDA SALAH MOHON MASUKKAN ULANG\n");
        printf("Masukkan nomor menu : ");
        fflush(stdin);
        return cek_menu();
    }
        else{
        return ulang;
    }
}

// Pengecekan Angka
float validasiFloat(){
    int i = 0;
    int salah = 0;
    int titik = 0;
    char angka[100];
    float val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    if(angka[0]>=48 && angka[0]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"

    }
        else if(angka[0]==45){  // PEMBATAS PADA ASCII DIMANA 45 BERNILAI "-"

        }
        else{
        salah += 1;
        }

    for(i=1;i<array; i++){
        if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"

        }
            else if(angka[i]==46){ // PEMBATAS PADA ASCII DIMANA 45 BERNILAI "."
            titik += 1;
            }
                else{
                salah += 1;
                }
    }

    if(salah>0 || titik>1){
        printf("INPUTAN ANDA SALAH MOHON MASUKKAN ULANG\n");
        printf("Masukkan bilangan : ");
        validasiInt();
    }
        else{
        val = atof(angka);
        return val;
        }
}

//pengecekan untuk angka pada modulus
int validasiInt(){
    int i = 0;
    int salah = 0;
    char angka[100];
    float val;
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
        printf("INPUTAN ANDA SALAH MOHON MASUKKAN ULANG\n");
        printf("Masukkan bilangan : ");
        validasiInt();
    }else{
        val = atof(angka);
        return val;
    }
}

void Penjumlahan();
void Pengurangan();
void Perkalian();
void Pembagian();
void Modulus();


int main(){
    int ulang, menu;

    printf("=======================================\n\n");
    printf("          PROGRAM KALKULATOR   \n\n");
    printf("=======================================\n\n");

    printf("\tMenu Kalkulator\n\n 1. Penjumlahan\n 2. Pengurangan\n 3. Perkalian\n 4. Pembagian\n 5. Modulus\n\n");
    printf("Pilih Menu Kalkulasi dengan Memasukkan Nomor Menu (1/2/3/4/5) \n\n");
    printf("Masukkan menu: ");
    menu = cek_menu();
    system("cls");

    if (menu>= 1 && menu < 2){
        Penjumlahan();
    }
        else if (menu>=2 && menu < 3){
            Pengurangan();
        }
            else if(menu>=3 && menu < 4){
                Perkalian();

            }
                else if(menu>=4 && menu < 5){
                   Pembagian();

                }
                     else if(menu>=5 && menu < 6){
                        Modulus();
                    }
                        else{
                            printf("Tidak ada pada pilihan menu");
                        }

    return 0;
}

void Penjumlahan(){
    float a, b;
    float jml;
    int pilihan;

    printf("=========================\n\n");
    printf("   PROGRAM PENJUMLAHAN   \n\n");
    printf("=========================\n\n");

        printf("Masukkan bilangan pertama : ");
        a = validasiFloat();
        printf("Masukkan bilangan kedua : ");
        b = validasiFloat();
        jml = a+b;
        printf("Hasil dari penjumlahan : %.2f\n\n\n", jml);
        printf("Apakah anda ingin mengulang?\n\n\n");
        printf("============================\n\n");
        printf("1. Ulang  2. Kembali  3. Exit  \n\n");
        printf("============================\n\n");
        printf("Masukkan Menu:");
        pilihan = cek_ulang();
        system("cls");

        switch(pilihan){
	    case 1:
	    Penjumlahan();
	    break;
	    case 2:
	    main();
	    break;
	    default:
	    exit(0);
	    break;
	 }
}
void Pengurangan(){
    float a, b, krg;
    int pilihan;

    printf("=========================\n\n");
    printf("   PROGRAM PENGURANGAN   \n\n");
    printf("=========================\n\n");

        printf("Masukkan bilangan pertama : ");
        a = validasiFloat();
        printf("Masukkan bilangan kedua : ");
        b = validasiFloat();
        krg= a-b;
        printf("Hasil dari Pengurangan : %.2f\n\n\n", krg);
        printf("Apakah anda ingin mengulang?\n\n\n");
        printf("============================\n\n");
        printf("1. Ulang  2. Kembali  3. Exit  \n\n");
        printf("============================\n\n");
        printf("Masukkan Menu:");
        scanf("%d", &pilihan);
        system("cls");

        switch(pilihan){
            case 1:
            Pengurangan();
            break;
            case 2:
            main();
            break;
            default:
            exit(0);
            break;
	 }
}
void Perkalian(){
    float a, b, kali;
    int pilihan;

    printf("=========================\n\n");
    printf("    PROGRAM PERKALIAN    \n\n");
    printf("=========================\n\n");

        printf("Masukkan bilangan pertama : ");
        a = validasiFloat();
        printf("Masukkan bilangan kedua : ");
        b = validasiFloat();
        kali= a*b;
        printf("Hasil dari Perkalian : %.2f\n\n\n", kali);
        printf("Apakah anda ingin mengulang?\n\n\n");
        printf("============================\n\n");
        printf("1. Ulang  2. Kembali  3. Exit  \n\n");
        printf("============================\n\n");
        printf("Masukkan Menu:");
        scanf("%d", &pilihan);
        system("cls");

        switch(pilihan){
            case 1:
            Perkalian();
            break;
            case 2:
            main();
            break;
            default:
            exit(0);
            break;
	 }
}
void Pembagian(){
    float a, b, bagi;
    int pilihan;

    printf("=========================\n\n");
    printf("    PROGRAM PEMBAGIAN    \n\n");
    printf("=========================\n\n");

        printf("Masukkan bilangan pertama : ");
        a = validasiFloat();
        printf("Masukkan bilangan kedua : ");
        b = validasiFloat();
        bagi= a/b;
        printf("Hasil dari Pembagian : %.2f\n\n\n", bagi);
        printf("Apakah anda ingin mengulang?\n\n\n");
        printf("============================\n\n");
        printf("1. Ulang  2. Kembali  3. Exit  \n\n");
        printf("============================\n\n");
        printf("Masukkan Menu:");
        scanf("%d", &pilihan);
        system("cls");

        switch(pilihan){
            case 1:
            Pembagian();
            break;
            case 2:
            main();
            break;
            default:
            exit(0);
            break;
	 }
}
void Modulus(){
    int a, b, mod, pilihan;

    printf("=========================\n\n");
    printf("     PROGRAM MODULUS     \n\n");
    printf("=========================\n\n");

        printf("Masukkan bilangan pertama : ");
        a = validasiInt();
        printf("Masukkan bilangan kedua : ");
        b = validasiInt();
        mod = a%b;
        printf("Hasil dari Modulus : %i\n\n\n", mod);
        printf("Apakah anda ingin mengulang?\n\n\n");
        printf("============================\n\n");
        printf("1. Ulang  2. Kembali  3. Exit  \n\n");
        printf("============================\n\n");
        printf("Masukkan Menu:");
        scanf("%d", &pilihan);
        system("cls");

        switch(pilihan){
            case 1:
            Modulus();
            break;
            case 2:
            main();
            break;
            default:
            exit(0);
            break;
	 }
}

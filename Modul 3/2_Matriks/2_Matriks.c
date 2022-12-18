#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int matriks1[50][50], matriks2[50][50], hasil[50][50];

float inputValidasi(){
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 48-51 BERNILAI "0-9"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("INPUT TIDAK SESUAI\n\n");
        printf("Masukan input ulang : ");
        inputValidasi();
    }else{
        val = atoi(angka);
        return val;
    }
}

int validasi(){
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
        printf("INPUTAN ANDA TIDAK SESUAI\n\n");
        printf(">> Masukan input ulang : ");
        validasi();
    }else{
        val = atoi(angka);
        return val;
    }
}

int validasiPilihan() {
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
        printf("INPUTAN ANDA TIDAK SESUAI\n\n");
        printf(">> Masukan Pilihan Menu : ");
        validasiPilihan();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=4){
            return val;
        }else{
            printf("INPUTAN ANDA TIDAK SESUAI\n\n");
            printf(">> Masukan Pilihan Menu : ");
            validasiPilihan();
        }
    }
}

int validasiMenu() {
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=49 && angka[i]<=52){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "1-3"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("INPUTAN ANDA TIDAK SESUAI\n\n");
        printf(">> Masukan Pilihan Menu : ");
        validasiMenu();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=4){
            return val;
        }else{
            printf("INPUTAN ANDA TIDAK SESUAI\n\n");
            printf(">> Masukan Pilihan Menu : ");
            validasiMenu();
        }
    }
}

int main();

void pertambahan_matriks(int m, int n){
    int i, j;

    printf("\t\n Hasil penjumlahan matriks :\n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            hasil[i][j] = matriks1[i][j] + matriks2[i][j];
            printf("%d\t", hasil[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void perkalian_matriks(int m, int n, int p, int q){
    int i, j, k;
    int jumlah = 0;

    for(i=0; i<m; i++){
        for(j=0; j<q; j++){
            for(k=0; k<p; k++){
                jumlah = jumlah + (matriks1[i][k] * matriks2[k][j]);
            }
            hasil[i][j] = jumlah;
            jumlah = 0;
        }
    }
    printf("\t Hasil perkalian matriks:\n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%d\t", hasil[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void transpose_matriks(int n, int m){
    int i, j;

    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            hasil[j][i] = matriks1[i][j];
        }
    }
    printf("\t Hasil transpose matriks:\n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%d\t", hasil[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void transpose(){
    int i, j, m, n, p, q, pilihan;

    printf("=========================================\n\n");
    printf("             OPERASI MATRIKS             \n");
    printf("-----------------------------------------\n");
    printf("                TRANSPOSE               \n");
    printf("=========================================\n\n");

    printf("Masukkan jumlah baris matriks pertama : ");
    m=inputValidasi();
    printf("Masukkan jumlah kolom matriks pertama : ");
    n=inputValidasi();

    printf("-----------------------------------------\n");
    printf("Masukkan elemen matriks pertama: \n");
    for(i = 0; i<m; i++){
        for(j = 0; j<n; j++){
            matriks1[i][j]=validasi();
        }
    }
    printf("=========================================\n");
    transpose_matriks(n, m);


    printf("\n=========================================\n");
    printf("1.Ulangi      2.Kembali       3.Exit\n");
    printf("-----------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
        case 1:
            transpose();
            break;
        case 2:
            main();
            break;
	    default:
            exit(0);
            break;
    }
}

void perkalian(){
    int i, j, m, n, p, q, pilihan;

    printf("=========================================\n\n");
    printf("             OPERASI MATRIKS             \n");
    printf("-----------------------------------------\n");
    printf("                PERKALIAN                \n");
    printf("=========================================\n\n");

    printf("Masukkan jumlah baris matriks pertama : ");
    m=inputValidasi();
    printf("Masukkan jumlah kolom matriks pertama : ");
    n=inputValidasi();

    printf("Masukkan jumlah baris matriks kedua   : ");
    p=inputValidasi();
    printf("Masukkan jumlah kolom matriks kedua   : ");
    q=inputValidasi();
    printf("-----------------------------------------\n");
        if(n != p){
            printf("\t Matriks tidak dapat diproses\n");
        }else{
            printf("Masukkan elemen matriks pertama: \n");
            for(i=0; i<m; i++){
                for(j=0; j<n; j++){
                    matriks1[i][j]=validasi();
                }
            }
            printf("\nMasukkan elemen matriks kedua: \n");
            for(i = 0; i<p; i++){
                for(j = 0; j<q; j++){
                    matriks2[i][j]=validasi();
                }
            }
        printf("=========================================\n");
        perkalian_matriks(m, n, p, q);
        }
    printf("\n=========================================\n");
    printf("1.Ulangi      2.Kembali       3.Exit\n");
    printf("-----------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
        case 1:
            perkalian();
            break;
        case 2:
            main();
            break;
	    default:
            exit(0);
            break;
    }
}

void pertambahan(){
    int i, j, m, n, p, q, pilihan;

    printf("=========================================\n\n");
    printf("             OPERASI MATRIKS             \n");
    printf("-----------------------------------------\n");
    printf("               PERTAMBAHAN               \n");
    printf("=========================================\n\n");

    printf("Masukkan jumlah baris matriks pertama : ");
    m=inputValidasi();
    printf("Masukkan jumlah kolom matriks pertama : ");
    n=inputValidasi();

    printf("Masukkan jumlah baris matriks kedua   : ");
    p=inputValidasi();
    printf("Masukkan jumlah kolom matriks kedua   : ");
    q=inputValidasi();
    printf("-----------------------------------------\n");
        if(n != p){
            printf("Matriks tidak dapat diproses\n");
        }else{
            printf("Masukkan elemen matriks pertama: \n");
            for(i=0; i<m; i++){
                for(j=0; j<n; j++){
                    matriks1[i][j]=validasi();
                }
            }
            printf("\nMasukkan elemen matriks kedua: \n");
            for(i = 0; i<p; i++){
                for(j = 0; j<q; j++){
                    matriks2[i][j]=validasi();
                }
            }
        printf("=========================================\n");
        pertambahan_matriks(m, n);
        }

    printf("\n=========================================\n");
    printf("1.Ulangi      2.Kembali       3.Exit\n");
    printf("-----------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

    switch(pilihan){
        case 1:
            pertambahan();
            break;
        case 2:
            main();
            break;
	    default:
            exit(0);
            break;
    }
}

int main(){
    system("COLOR F0");
    int pilihan;
    int ulang;

    printf("=========================================\n\n");
    printf("             OPERASI MATRIKS             \n\n");
    printf("=========================================\n\n");
    printf("\t1. Pertambahan\n");
    printf("\t2. Perkalian\n");
    printf("\t3. Transpose\n");
    printf("\t4. Exit\n");
    printf("-----------------------------------------\n");
    printf("Masukkan pilihan : ");
    pilihan = validasiMenu();
    system("cls");

    switch(pilihan){
	    case 1:
	    pertambahan();
	    break;
	    case 2:
	    perkalian();
	    break;
	    case 3:
	    transpose();
	    break;
	    default:
	    exit(0);
	    break;
    }
    return 0;
}
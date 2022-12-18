#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// DEKLARASI VARIABLE
float mean(float data[], int jumlah);
float median(float data[], int jumlah);
int modus(float bil[], int jumlah, float mod[]);
void sorting_nilai(float data[], int jumlah);

// VALIDASI
float input(){
    int i = 0;
    int salah =0;
    int titik=0;
    char angka[100];
    float val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"

        }else if(angka[i]==46){ // PEMBATAS PADA ASCII DIMANA 45 BERNILAI "."
            titik += 1;
        }else{
            salah += 1;
        }
    }

    if(salah>0 || titik>1){
        system("color 4F");
        printf("MASUKAN NILAI YANG SESUAI!\n");
        printf("Masukkan input : ");
        return input();
    }else{
        val = atof(angka);
        if(val>0){
            return val;
        }else{
            system("color 4F");
            printf("INPUT TIDAK VALID!\n");
            printf("Masukkan input kembali : ");
            return input();
        }
    }
}

int inputdata(){
    int i = 0;
    int salah =0;
    int titik=0;
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
        system("color 4F");
        printf("MASUKAN NILAI YANG SESUAI!\n");
        printf("Masukkan input : ");
        return input();

    }else{
        val = atoi(angka);
        if(val>0){
            return val;
        }else{
            system("color 4F");
            printf("INPUT TIDAK VALID!\n");
            printf("Masukkan input kembali : ");
            return inputdata();
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
        printf("INPUT TIDAK VALID!\n");
        printf("Masukkan input kembali : ");
        validasiPilihan();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=2){
            return val;
        }else{
            printf("INPUT TIDAK VALID!\n");
            printf("Masukkan input kembali : ");
            validasiPilihan();
        }
    }
}

// RUMUS KALKULASI
float mean(float data[], int jumlah){
    float hasil = 0;
    int i;

    for(i = 0; i < jumlah; i++){
        hasil = hasil + data[i];
    }

    hasil = hasil / jumlah;

    return hasil;
}

float median(float data[], int jumlah){
    float hasil;
    int tengah = jumlah / 2;

    if(jumlah % 2 == 0){
        hasil = (data[tengah-1] + data[tengah]) / 2;
    }else{
        hasil = data[tengah];
    }

    return hasil;
}

int modus(float bil[], int jumlah, float mod[]){
    int n_angka[jumlah];
    int i, j;
    int jumlah_tmp;
    int max = 0;
    int z = 0;
    int status;
    int a = 0;

    for(i = 0; i < jumlah; i++){
        mod[i] = 0;
        jumlah_tmp = 0;
        for(j = 0; j < jumlah; j++){
            if(bil[i] == bil[j]){
                jumlah_tmp++;
            }
        }
        if(jumlah_tmp > max){
            max = jumlah_tmp;
        }
        n_angka[i] = jumlah_tmp;
    }

    for(i = 0; i < jumlah; i++){
        status = 0;
        if(n_angka[i] == max){
            z++;
            for(j = 0; j < jumlah; j++){
                if(bil[i] == mod[j]){
                    status = 1;
                }
            }
            if(status == 0){
                mod[a] = bil[i];
                a++;
            }
        }
    }

    if(jumlah == z){
        return 0;
    }else{
        return a;
    }
}

void sorting_nilai(float data[], int jumlah){
    int i, j;
    float temp;
    for(i = 0; i < jumlah - 1; i++){
	    for(j = 0; j < jumlah - 1; j++){
		    if(data[j+1] < data[j]){
			    temp      = data[j];
			    data[j]   = data[j+1];
    			data[j+1] = temp;
		    }
    	}
	}
}

// MAIN
int main() {
    system("color F0");
    int jumlah;
    int i;
    float hasil_mean;
    float hasil_median;
    float hasil_modus;
    int pilihan;
    float *alamat;

    printf("|=====================================|\n");
    printf("           Program Statistika          \n");
    printf("               Menghitung              \n");
    printf("            MEAN MEDIAN MODUS          \n");
    printf("--------------------------------------\n");
    printf("          - Oleh Kelompok 14 -          \n");
    printf("|=====================================|\n\n");

    printf("Masukan Jumlah Data : ");
    jumlah = inputdata();

    float data[jumlah];
    // pointer dari input
    alamat = &data;

    system("color F0");
    printf("\nMasukan Nilai Data :          \n");
    for(i = 0; i < jumlah; i++){
        printf("Masukan Nilai Data ke - %d : ", i+1);
        alamat[i] = input();
    }

    sorting_nilai(data, jumlah);
    system("color F0");
    printf("\n--------------------------------------\n");
    printf("Data setelah Diurutkan : \n");
    printf(">> ");
        for(i = 0; i < jumlah; i++){
            printf("%.0f  ", data[i]);
    }

    hasil_mean = mean(data, jumlah);
    hasil_median = median(data, jumlah);
    float mod[jumlah];
    hasil_modus = modus(data, jumlah, mod);

    printf("\n\nMean Data Tersebut : \n>> %.2f\n", hasil_mean);

    printf("\nMedian Data Tersebut : \n>> %.2f\n", hasil_median);

    if(hasil_modus == 0){
        printf("\nModus Data Tersebut : \n>> ");
        printf("Tidak Ada Modus dari Data Tersebut\n");
    }else{
        printf("\nModus Data Tersebut : \n>> ");
        for(i = 0; i < hasil_modus; i++){
            if(i == 0){
                printf(" %.0f", mod[i]);
            }else{
                printf(", %.0f", mod[i]);
            }
        }
    }

    printf("\n\n========================================\n");
    printf("    1. Ulangi Hitung      2.Keluar \n");
    printf("----------------------------------------\n");
    printf("Masukan Pilihan :");
    pilihan = validasiPilihan();
    system("cls");

	switch (pilihan){
	    case 1:
	    main();
	    break;
	    default:
	    exit(0);
	    break;
	 }
}

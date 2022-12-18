#include <stdio.h>
#include <stdlib.h>
int menu();
int ulang();

void desimal_biner();
void biner_desimal();
int ubah(int x, int y);
void kesalahan();
int input();
/* UNTUK COVER ANGGOTA KELOMPOK */
void cover(){
	printf( "\t\t\t---------------------------------------------------------------\n");
	printf("\t\t\t|---------------------KELOMPOK 14 ALPROG----------------------|\n");
	printf("\t\t\t|=============================================================|\n");
	printf("\t\t\t|>> Program Menghitung Konversi Bilangan Biner Dan Desimal  <<|\n");
	printf("\t\t\t---------------------------------------------------------------\n");
}
/* PROGRAM UTAMA */
int main(){
    int pilihan, hasil;
    kembali:
    system("cls");
    cover();
    system("pause");
    system("cls");
    pilihan = menu();
if(pilihan == 0){
    system("cls");
    printf("\n\n\t\t\t>> PROGRAM SELESAI <<\n\n");
    exit(0);
}
    else if(pilihan == 1){   
    system("cls");
    desimal_biner();
    }
        else if(pilihan == 2){
        system("cls");
        biner_desimal();
}
        else{
        char nilai;
        system("cls");
        kesalahan();
        main();
    }
    printf("\n");
    system("pause");
    hasil = ulang();

    if(hasil == 1){
    goto kembali;
}
        else{
        exit;
    }
}

/* FUNGSI MENJALANKAN MENU PROGRAM */
int menu(){
int menu;
    printf("\n\n");
    printf("===================================\n");
    printf("| MENU PROGRAM                      |\n");
    printf("|                                   |\n");
    printf("|>> 1.Konversi Desimal ke Biner <<  |\n");
    printf("|>> 2.Konversi Biner ke Desimal <<  |\n");
    printf("|                                   |\n");
    printf("|                                   |\n");
    printf("| EXIT(0)<<                         |\n");
    printf("===================================\n");
    printf("\n>> Masukan Pilihan : ");
    menu = input();

return menu;
}



void desimal_biner()
{
    int n,i=1, k, nilai;
    int j, biner[10];
    printf("\t\tMasukkan Bilangan Desimal\n\n\t >>");
    n = input();
    nilai = n;
    while(n>0){
    biner[i]=n%2;
    n=n/2;
    i=i+1;
    k=i;
    }
printf("Berikut Hasil Bilangan Biner dari %d\n>> ", nilai);
    for(j=k-1;j>0;j--){
    printf("%d",biner[j]);
    }
}


void biner_desimal(){
typedef char array[MAKS];
    array bin;
    int d= 0, i= 0, n= 0, j, ch, pilih, lanjut;
    system("cls");
    printf("\t\tMasukan Bilangan Biner\n\n\t>> ");
    getchar();
    while((ch = getchar()) != '\n'){
	    if (ch == 48 || ch == 49){
	    bin[i++] = ch;
	    lanjut =1;
	}
			else if (ch != 48 || ch != 49){
		kesalahan();
		biner_desimal();
	}
}
if(lanjut == 1){
    printf("-------------------------------\n");
    for(j = i-1; j>=0; j--){
        d += (bin[j] - 48) * ubah(2, n);
        n++;
        printf("%3c", bin[j]); //cetak biner dengan 3 spasi
    }
    printf("\n-------------------------------\n");
    printf("bilangan desimal\n>> %d", d);
    }
}
int ubah(int x, int y){



int i =0, hasil = 1;
for(;i<y;){
        hasil = hasil * x;
        i++;
	}
	return hasil;
}
int ulang(){
    int cek;
    printf("\nApakah Anda Ingin Mengulang Program?\n1. YA\n2.Tidak\n>> ");
    cek = input();
        if(cek >2 || cek <1){
        kesalahan();
        ulang();
        }
            else{
            return cek;
            }
}
int input(){
    int angka;
    char karakter;
    if (scanf("%d%c",&angka,&karakter)!=2 || angka<1 ||
    karakter != '\n'){
    fflush(stdin);
    kesalahan();
    printf("\nMasukkan angka yang benar : ");
    return input();
}
         else {
        return angka;
}


}
/* PROSEDUR UNTUK MENAMPILKAN KESALAHAN */
void kesalahan(){
	printf("\t\t\t ===============================\n");
	printf("\t\t\t>> |INPUT YANG ANDA MASUKAN SALAH| <<\n");
	printf("\t\t\t ===============================\n");
	system("pause");
}

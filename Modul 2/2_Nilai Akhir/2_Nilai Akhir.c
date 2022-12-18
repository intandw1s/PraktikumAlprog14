#include <stdio.h>
#include <stdlib.h>
void hitung_nilai_akhir();

//VALIDASI

//Pengecekan (Validasi) Menu
int cek_menu(){
     int ulang;
     char huruf;
     scanf("%i%c",&ulang,&huruf);
     if((huruf!='\n')||(ulang<1||ulang>2)){
        printf("INPUTAN MENU ANDA SALAH MOHON MASUKKAN ULANG\n");
        printf("Masukkan nomor menu : ");
        fflush(stdin);
        return cek_menu();
    }
        else{
        return ulang;
    }
}

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

//Pengecekan(Validasi) Nilai
float validasiNilai(){
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
        printf("INPUT NILAI TIDAK SESUAI\n");
        printf("Masukkan input kembali : ");
        validasiNilai();
    }
    else{
        val = atof(angka);
        if(val>=0 && val<=100){
            return val;
        }else{
            printf("INPUT NILAI TIDAK SESUAI\n");
            printf("Masukkan input kembali : ");
            validasiNilai();
        }
    }
}

//Pengecekan (Validasi) Absen
int validasiAbsen(){
    int i = 0;
    int salah = 0;
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


   if (salah>0){
        printf("INPUT KEHADIRAN TIDAK SESUAI\n");
        printf("Masukkan input kembali : ");
        validasiAbsen();
    }
    else{
        val = atof(angka);
        if(val>=0 && val<=15){
            return val;
        }else{
            printf("INPUT KEHADIRAN TIDAK SESUAI\n");
            printf("Masukkan input kembali : ");
            validasiAbsen();
        }
    }
}

int main(){
    int menu;

    printf("============================================\n\n");
    printf("       PROGRAM MENGHITUNG NILAI AKHIR        \n\n");
    printf("============================================\n\n");
    printf("\tMENU\n\n 1. Hitung Nilai Akhir\n 2. Keluar Program\n");
    printf("Masukkan Menu (1/2): ");
    menu = cek_menu();
    system("cls");

    if(menu==1){
        hitung_nilai_akhir();
    }else{
        exit(0);
    }

    return 0;
}
void hitung_nilai_akhir(){
      int absen;
      float tgs1, tgs2, tgs3, quiz, uts, uas, hasil;
      int pilihan;

      printf("==============================\n\n");
      printf("        MASUKKAN NILAI        \n\n");
      printf("==============================\n\n");

      printf("Masukkan Jumlah Kehadiran : ");
      absen = validasiAbsen();
      printf("Masukkan Nilai Tugas 1 : ");
      tgs1 = validasiNilai();
      printf("Masukkan Nilai Tugas 2 : ");
      tgs2 = validasiNilai();
      printf("Masukkan Nilai Tugas 3 : ");
      tgs3 = validasiNilai();
      printf("Masukkan Nilai Quiz : ");
      quiz = validasiNilai();
      printf("Masukkan Nilai UTS : ");
      uts = validasiNilai();
      if (absen<12){

      }else {
           printf("Masukkan NIlai UAS : ");
           uas = validasiNilai();
      }

      hasil= ((((absen*100)/15)*0.05)+(((tgs1+tgs2+tgs3)*0.2)/3)+(quiz*0.15)+(uts*0.3)+(uas*0.3));
      printf("\nNilai Akhir Anda : %.2f\n", hasil);

      if(hasil>=80 && hasil<100){
        printf("\nAnda Mendapatkan Nilai A\n");
      }
      else if(hasil>=75 && hasil<80){
        printf("\nAnda Mendapatkan Nilai B+\n");
      }
       else if(hasil>=65 && hasil<75){
        printf("\nAnda Mendapatkan Nilai B\n");
      }
      else if(hasil>=60 && hasil<65){
        printf("\nAnda Mendapatkan Nilai C+\n");
      }
      else if(hasil>=55 && hasil<60){
        printf("\nAnda Mendapatkan Nilai C\n");
      }
      else if(hasil>=50 && hasil<55){
        printf("\nAnda Mendapatkan Nilai D+\n");
      }
      else if(hasil>=45 && hasil<50){
        printf("\nAnda Mendapatkan Nilai D\n");
      }
      else{
        printf("\nAnda Mendapatkan Nilai E\n");
      }

    printf("\n\nApakah anda ingin mengulang?\n\n");
    printf("============================\n\n");
    printf("1. Ulang  2. Kembali  3. Exit  \n\n");
    printf("============================\n\n");
    printf("Masukkan Menu:");
    scanf("%d", &pilihan);
    system("cls");

        switch(pilihan){
            case 1:
            hitung_nilai_akhir();
            break;
            case 2:
            main();
            break;
            default:
            exit(0);
            break;
         }
    }

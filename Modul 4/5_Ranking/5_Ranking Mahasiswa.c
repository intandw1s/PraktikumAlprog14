#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>
#include<conio.h>
#include<windows.h>

void menu();
void Data();
void Bubble_sort();
void Hasil();
int validasiPilihan();

struct mahasiswa{
	char nama[100];
	int nilai;
};

struct mahasiswa data_mhs[100];
int byk=0;

int main(){
    system("COLOR F0");
    int pilih;

    printf("==========================================\n\n");
    printf("          PROGRAM RANKING MAHASISWA      \n\n");
    printf("==========================================\n\n");
    printf("\t1. Mengurutkan Ranking\n");
    printf("\t2. Keluar\n");
    printf("==========================================\n\n");
    printf("Masukkan Pilihan Menu : ");
    pilih = cek_pilihan();
    system("cls");

    if(pilih==1){
        menu();
	}else{
        exit(0);
	}

    return 0;
}

void menu(){
    int pilih;

    printf("==========================================\n\n");
    printf("          PROGRAM RANGKING MAHASISWA      \n\n");
    printf("==========================================\n\n");
    Data();
    Bubble_sort();
    Hasil();

    printf("\n\n==========================================\n");
    printf("          1.Back         2.Exit   \n");
    printf("------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilih = cek_pilihan();
    system("cls");

	if(pilih==1){
        main();
	}else{
        exit(0);
	}

}

void Data(){
	int panjang;
	char nilai[3];
	FILE *fp;
	fflush(stdin);
	fp=fopen("asistenin.txt","r");
	while(fgets(data_mhs[byk].nama,255,fp)){
		panjang = strlen(data_mhs[byk].nama);
		data_mhs[byk].nama[panjang-1]='\0';
		fgets(nilai,255,fp);
		panjang = strlen(nilai);
		nilai[panjang]='\0';
		data_mhs[byk].nilai=atoi(nilai);
		byk++;
		fflush(stdin);
	}
	fclose(fp);
}

void Bubble_sort(){
    int i, j;
    struct mahasiswa tukar;
    fflush(stdin);
	for (i = 0; i < byk-1; i++)
         for (j = 0; j < byk-i-1; j++)
            if (data_mhs[j].nilai < data_mhs[j+1].nilai){
                tukar = data_mhs[j];
                data_mhs[j] = data_mhs[j+1];
                data_mhs[j+1] = tukar;
                fflush(stdin);
    }
}

void Hasil(){
	int i;
	fflush(stdin);
	FILE *fp;
	FILE *fq;
	fp=fopen("asistenout.txt","w");
	fq=fopen("asistenout.txt","a+");
	printf("Nilai Mata Kuliah Algoritma dan Pemrograman : \n\n");
	fprintf(fp, "%s\n\n", "Nilai Mata Kuliah Algoritma dan Pemrograman ");
	for(i=0 ; i<byk-1 ; i++){
		printf("[%d] %s %d\n",i+1, data_mhs[i].nama, data_mhs[i].nilai);
		fprintf(fq,"%s\n%d\n",data_mhs[i].nama, data_mhs[i].nilai);
		fflush(stdin);
	}
	fclose(fp);
	fclose(fq);
	fp = fopen("asistenout.txt","r");
	fclose (fp);
	ShellExecute(NULL, NULL, "asistenout.txt", NULL, NULL, SW_SHOWNORMAL);
}


int cek_pilihan(){
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
        printf("INPUT TIDAK SESUAI\n");
        printf("Masukkan input kembali : ");
        cek_pilihan();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=2){
            return val;
        }else{
            printf("INPUT TIDAK SESUAI\n");
            printf("Masukkan input kembali : ");
            cek_pilihan();
        }
    }
}

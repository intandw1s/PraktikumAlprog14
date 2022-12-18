#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void error(){
	printf("\tInputan Salah! Silahkan Input Ulang.\n");
	sleep(3);
	system("cls");
	main();
}

int validInt(int *var){
   char buff[1024];
   char check;

   if (fgets(buff, sizeof(buff), stdin) !=NULL){
    	if (sscanf(buff, "%d %c", var, &check) ==1){
			return 1;
		}
   }
    return 0;
}

void repeat(){
    char pil[10];
    
	fflush(stdin);
	printf ("\n\tKembali ke Program? (y/n) : "); 
	scanf("%s", &pil);
 	
	if(!strcmp(pil, "y") || !strcmp(pil, "Y")){
		system("cls");
		main();
	}else if(!strcmp(pil, "n") || !strcmp(pil, "N")){
		printf("\n\tTerimakasih Telah Menggunakan Program Ini!");
  		exit(0);
	}else{
		printf("\tInput Salah!\n");
		sleep(2);
		system("cls");
		repeat();
	}
}

void awal(){		
	printf("\t|____________________________________________|\n");
	printf("\t|            Menghitung Gaji Harian          |\n");
	printf("\t|                                            |\n");
	printf("\t|____________________________________________|\n");
	printf("\t|************** KELOMPOK 14 *****************|\n");
	printf("\t|____________________________________________|\n\n");
}

int main(){
	fflush(stdin);
	
	struct gaji{
		float gajiPerjam, gajiPokok, gajiLembur, akumulasiGaji; 
		int jamKerja, jamLembur; 
	}nilai;
	
	awal();
	printf("\tMasukkan jam kerja = "); 
	if(!validInt(&nilai.jamKerja)){
		error();
		sleep(1);
	}else if (nilai.jamKerja < 0 || nilai.jamKerja > 24){
		error();
		sleep(1);
	}
	system("cls");

	awal();
	printf("\n\tTotal Jam Kerja \t= %d\n", nilai.jamKerja); 
	
	if(nilai.jamKerja>8){
		nilai.jamLembur = nilai.jamKerja-8;
		nilai.gajiLembur = 8 * 10625; 
		nilai.gajiLembur = nilai.gajiLembur * nilai.jamLembur;
	}
		
	nilai.gajiPokok = nilai.jamKerja-nilai.jamLembur;
	nilai.gajiPokok = nilai.gajiPokok * 10625; 
	printf("\n\tGaji Pokok \t\t= Rp %.2f\n", nilai.gajiPokok);

	if(nilai.jamLembur>=1){
		printf("\n\tTotal Jam Lembur \t= %d\n", nilai.jamLembur);
		printf("\n\tGaji Tambahan (Lembur) \t= Rp %.2f\n", nilai.gajiLembur);
	}
	nilai.akumulasiGaji = nilai.gajiPokok + nilai.gajiLembur; 
	printf("\n\tAkumulasi Gaji Perhari \t= Rp %.2f\n", nilai.akumulasiGaji);
	
	repeat();
	return 0; 
}
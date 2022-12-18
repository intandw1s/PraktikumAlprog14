#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void menu_searching ();
void menu_sorting();
void sorting();
void insertion_sort();
void bubble_sort();
void quick_sort();

//PENGECEKAN ULANG
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

//PENGECEKAN INPUT
int cek_input(){
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
        printf("INPUT TIDAK SESUAI\n\n");
        printf("Masukan input ulang : ");
        cek_input();
    }else{
        val = atoi(angka);
        return val;
    }
}

int main(){
    system("COLOR F0");

    int pilihan;

    printf("=========================================\n\n");
    printf("      PROGRAM SEARCHING AND SORTING      \n\n");
    printf("=========================================\n");
    printf("\tMENU UTAMA \n\n 1. Searching\n 2. Sorting\n 3. Exit\n");
    printf("-----------------------------------------\n");
    printf("Masukkan Pilihan (1/2/3): ");
    pilihan = cek_input();

    if(pilihan==1){
        system("cls");
        menu_searching();
    }else if(pilihan==2){
        system("cls");
        menu_sorting();
    }else if(pilihan==3){
        printf("=========================================\n");
        printf("               TERIMA KASIH              \n");
        printf("=========================================\n");
        exit(1);
    }else{
        system("cls");
        printf("=========================================\n");
        printf("            INPUTAN ANDA SALAH          \n");
        printf("     MOHON MASUKAN INPUT YANG BENAR     \n");
        printf("=========================================\n");
        main();
    }

    system("pause");
    system("cls");

    return 0;
}

void menu_searching(){
    int pilihan, i, banyak;

    printf("=========================================\n\n");
    printf("            PROGRAM SEARCHING            \n\n");
    printf("=========================================\n");
    printf(" 1. 1000 Data\n 2. 16000 Data\n 3. 64000 Data\n 4. Kembali\n");
    printf("-----------------------------------------\n");
    printf("Masukkan Pilihan (1/2/3/4): ");
    pilihan = cek_input();

    if(pilihan>0 && pilihan<4){
        if(pilihan==1){
            int angka[1000];

            system("cls");
            banyak = sizeof(angka) / sizeof(angka[0]);
            srand((unsigned) time(NULL));

            for(i=0; i<banyak; i++){
                angka[i] = rand();
            }

            searching(angka, banyak);
        }else if(pilihan==2){
            int angka[16000];

            system("cls");
            banyak = sizeof(angka) / sizeof(angka[0]);
            srand((unsigned) time(NULL));

            for(i=0; i<banyak; i++){
                angka[i] = rand();
            }

            searching(angka, banyak);
        }else{
            int angka[64000];

            system("cls");
            banyak = sizeof(angka) / sizeof(angka[0]);
            srand((unsigned) time(NULL));

            for(i=0; i<banyak; i++){
                angka[i] = rand();
            }

            searching(angka, banyak);
        }

        printf("=====================================\n");
        printf("1.Ulangi  2. Menu Utama    3.Exit\n");
        printf("-------------------------------------\n");
        printf("Masukan Pilihan Anda : ");
        pilihan = cek_ulang();
        system("cls");

        switch(pilihan){
	    case 1:
            menu_searching();
            break;
        case 2:
            main();
            break;
	    default:
            exit(0);
            break;
        }
    }else if(pilihan==4){
        system("cls");
        main();
    }else{
        system("cls");
        printf("=========================================\n");
        printf("          INPUTKAN DENGAN BENAR          \n");
        printf("=========================================\n");
        menu_searching();
    }

}

void menu_sorting(){
    int pilihan, i, banyak;

    printf("=========================================\n\n");
    printf("             PROGRAM SORTING             \n\n");
    printf("=========================================\n");
    printf(" 1. 1000 Data\n 2. 16000 Data\n 3. 64000 Data\n 4. Kembali\n");
    printf("-----------------------------------------\n");
    printf("Masukkan Pilihan (1/2/3/4): ");
    pilihan = cek_input();

    if(pilihan>0 && pilihan<4){
        if(pilihan==1){
            int angka[1000];

            system("cls");
            banyak = sizeof(angka) / sizeof(angka[0]);
            srand((unsigned) time(NULL));

            for(i=0; i<banyak; i++){
                angka[i] = rand();
            }
            sorting(angka, banyak);
        }else if(pilihan==2){
            int angka[16000];

            system("cls");
            banyak = sizeof(angka) / sizeof(angka[0]);
            srand((unsigned) time(NULL));

            for(i=0; i<banyak; i++){
                angka[i] = rand();
            }

            sorting(angka, banyak);
        }else{
            int angka[64000];

            system("cls");
            banyak = sizeof(angka) / sizeof(angka[0]);
            srand((unsigned) time(NULL));

            for(i=0; i<banyak; i++){
                angka[i] = rand();
            }

            sorting(angka, banyak);

        }

        printf("=====================================\n");
        printf("1.Ulangi  2. Menu Utama    3.Exit\n");
        printf("-------------------------------------\n");
        printf("Masukan Pilihan Anda : ");
        pilihan = cek_ulang();
        system("cls");

        switch(pilihan){
	    case 1:
            menu_sorting();
            break;
        case 2:
            main();
            break;
	    default:
            exit(0);
            break;
        }

    }else if(pilihan==4){
        system("cls");
        main();
    }else{
        system("cls");
        printf("=========================================\n");
        printf("          INPUTKAN DENGAN BENAR          \n");
        printf("=========================================\n");
        menu_sorting();
    }
}

void sorting(int angka[], int banyak){

    int i, j, data=1, pilihan;
    clock_t waktu;
    double waktu1, waktu2, waktu3;

    waktu = clock();
    insertion_sort(angka, banyak);
    waktu = clock() - waktu;
    waktu1 = (double)(waktu) / CLOCKS_PER_SEC;

    waktu = clock();
    bubble_sort(angka, banyak);
    waktu = clock() - waktu;
    waktu2 = (double)(waktu) / CLOCKS_PER_SEC;

    waktu = clock();
    quick_sort(angka, 0, banyak-1);
    waktu = clock() - waktu;
    waktu3 = (double)(waktu) / CLOCKS_PER_SEC;

    for(i=0; i<banyak; i++){
        printf("\t");
        for(j=0; j<=0; j++){
            printf("data ke-%d = ", data);
            printf("%d ", angka[i]);
            data += 1;
        }
        printf("\n");
    }

    printf("=========================================\n");
    printf("        Waktu Yang Dibutuhkan        \n");
    printf("\n=========================================\n");
    printf("Insertion Sort  = %.12f \n", waktu1);
    printf("Bubble Sort     = %.12f \n", waktu2);
    printf("Quick Sort      = %.12f \n", waktu3);
    printf("=========================================\n");

    if(waktu1 < waktu2 && waktu1 < waktu3){
        printf("Insertion Sort Lebih Cepat \ndari Bubble Sort dan Quick Sort\n\n");
    }
    else if(waktu2 < waktu1 && waktu2 < waktu3){
        printf("Bubble Sort Lebih Cepat \ndari Insertion Sort dan Quick Sort\n\n");
    }
    else{
        printf("Quick Sort Lebih Cepat \ndari Insertion Sort dan Bubble Sort\n\n");
    }

}

void insertion_sort(int angka[], int banyak){
	int i,j,k;

	for(i=1; i<banyak; i++){
		k = angka[i];
		j = i - 1;
		while(j >= 0 && angka[j] > k){
			angka[j+1] = angka[j];
			j--;
		}
		angka[j+1] = k;
	}
}

void bubble_sort (int angka[], int banyak){
    int i, j, tukar; //variabel tukar sebagai tempat untuk bertukar

    for(i=0; i<banyak-1; i++){
		for(j=0; j<-i-1; j++){
			if(angka[j] > angka[j+1]){
				tukar = angka[j];
				angka[j] = angka[j+1];
				angka[j+1] = tukar;
			}
		}
	}
}

void quick_sort(int angka[],int terkecil,int terbesar){
	int i, j, k, tukar;

	if(terkecil<terbesar){
		k = terkecil;
    	i = terkecil;
    	j = terbesar;
    	while(i < j){
    		while(angka[i] <= angka[k] && i < terbesar){
            	i++;
    		}
    		while(angka[j] > angka[k]){
            	j--;
            }
        	if(i < j){
        		tukar = angka[i];
        		angka[i] = angka[j];
        		angka[j] = tukar;
        	}
    	}

		tukar = angka[k];
    	angka[k] = angka[j];
    	angka[j] = tukar;
    	quick_sort(angka, terkecil, j-1);
    	quick_sort(angka, j+1, terbesar);
	}
}


void searching(int angka[], int banyak){
    int i, j, angka_dicari,  counter = 0, data =1;
    clock_t waktu;
    double waktu1, waktu2;

    quick_sort(angka, 0, banyak-1);

    for(i=0; i<banyak; i++){
        printf("\t");
        for(j=0; j<=0; j++){
            printf("data ke-%d = ", data);
            printf("%d ", angka[i]);
            data += 1;
        }
        printf("\n");
    }

    printf("=========================================\n");
    printf("\nMasukkan Angka Yang Ingin Dicari : ");
    angka_dicari=cek_input();

    waktu = clock();
    sequential_search(angka, banyak, angka_dicari);
    waktu = clock() - waktu;
    waktu1 = (double)(waktu) / CLOCKS_PER_SEC;

    waktu = clock();
    binary_search(angka, 0, banyak-1, angka_dicari);
    waktu = clock() - waktu;
    waktu2 = (double)(waktu) / CLOCKS_PER_SEC;

    for(i=0; i<banyak; i++){
        if(angka[i] == angka_dicari){
            printf("\nAngka Ditemukan Pada Index : %d \n", i+1);
            counter++;
        }
    }

    if(counter==0){
        printf("\nTidak Ada Angka Yang Sesuai!\n");
    }

    printf("=========================================\n");
    printf("        Waktu Yang Dibutuhkan        \n");
    printf("=========================================\n");;
    printf("Sequential Search  = %.12f \n", waktu1);
    printf("Binary Search      = %.12f \n", waktu2);
    printf("=========================================\n");

    if(waktu1 < waktu2){
        printf("Sequential Search Lebih Cepat \ndari Binary Search\n\n");
    }
    else if(waktu1 > waktu2){
        printf("Binary Search Lebih Cepat \ndari Sequential Search\n\n");
    }else{
        printf("Binary Search Sama \ndengan Sequential Search\n\n");
    }
}



int sequential_search(int angka[],int banyak, int angka_dicari){
	int i;

    for(i=0; i<banyak; i++){
        if(angka[i]==angka_dicari){
             return i;
        }
    }
    return -1;
}

int binary_search(int angka[],int terkecil,int terbesar, int angka_dicari){

    if(terbesar >= terkecil){
        int tengah = terkecil + (terbesar - terkecil)/2;
        if(angka[tengah] == angka_dicari){
            return tengah;
        }
        if(angka[tengah] > angka_dicari){
            return binary_search(angka, terkecil, terbesar-1, angka_dicari);
            return binary_search(angka, tengah+1, terbesar, angka_dicari);
        }
   }
   return -1;
}



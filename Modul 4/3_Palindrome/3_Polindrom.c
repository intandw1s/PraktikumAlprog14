#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

FILE *kamuskata;

//VALIDASI
int validasi(char masukan[]){
    int i = 0;
    int salah = 0;

    while(masukan[i] != '\0'){
        if((masukan[i] >= 65 && masukan[i] <= 90) || (masukan[i] >= 97 && masukan[i] <= 122) || masukan[i] == ' '){
            i++;
        }else{
            salah = 1;
            masukan[i] = '\0';
        }
    }

    if(salah == 1){
        return 0;
    }else{
        return 1;
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
        printf("Masukan Input Kembali : ");
        validasiPilihan();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=3){
            return val;
        }else{
        	system("color 4F");
            printf("INPUT TIDAK VALID!\n");
            printf("Masukan Input Kembali : ");
            validasiPilihan();
        }
    }
}

char *palindrom(char x[]){
	int i,n=0;
	int p = strlen(x);
	char y[p];
	int p1=p;
	for(i=0;i<p1;i++){
		y[i]=x[p-1];
		p--;
	}
    for(i=0;i<p1;i++){
        if(y[i]!=x[i]){
            n=1;
        }
    }
	if(n==0){
		return("Palindrom");;
	}
	else{
		return ("Bukan Palindrom");
	}
}

void kata(char x[]){
	kamuskata=fopen("kamuskata.txt","a+");
	int i;
	int k;
	int count[100];
	bool isSame;
	int p= strlen(x);

	for(i=0;i< p;i++){
		count[i]=0;
		for(k=0;k<p;k++){
			if (x[i]==x[k]){
				count[i]++;
			}
		}
	}
	system("color F0");
	printf("==============================================\n\n");
	printf("Kata : %s",x);
	fprintf(kamuskata, "Kata : %s \nJumlah Huruf : ",x);
	printf("\nJumlah Huruf : ");
	for(i=0;i<p;i++){
		isSame=false;
		for(k=i-1;k>=0;k--){
			if (x[i]==x[k]){
				isSame=true;
				break;
			}
		}
		if(!isSame){
            if(x[i]==' '){

            }else{
			printf("%c=%d ",x[i],count[i]);
			fprintf(kamuskata,"%c=%d ",x[i],count[i]);
            }
		}
	}
	printf("\nHasil Pengecekan : %s",palindrom(x));
	fprintf(kamuskata,"\n# %s #\n\n",palindrom(x));
	fclose(kamuskata);
}

//MENU
int main();

int cek_palindrom(){
    int pilih,cek;
	char str[100];

    printf("|==============================================|\n");
    printf("                     PROGRAM                    \n");
    printf("                    PALINDROM                   \n");
    printf("-----------------------------------------------\n");
    printf("              - Cek Kata Palindrom -            \n");
    printf("|==============================================|\n\n");
    system("color F0");
    printf("Masukan Kata : ");
    fflush(stdin);
    scanf("%[^\n]", &str);

    cek = validasi(str);
    while(cek == 0){
    	system("color 4F");
        printf("Masukan Input Kembali : ");
        fflush(stdin);
        scanf("%[^\n]", &str);
        cek = validasi(str);
    }

    printf("\n");
    kata(str);

    printf("\n\n==============================================\n");
    printf("        1.Ulangi     2.Menu      3.Keluar   \n");
    printf("----------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilih = validasiPilihan();
    system("cls");

    switch(pilih){
	    case 1:
        cek_palindrom();
	    break;
	    case 2:
	    main();
	    break;
	    default:
	    exit(0);
	    break;
    }
}

int list_palindrom(){
    int pilih;
    char buff[255];
    FILE *fptr;

    printf("|==============================================|\n");
    printf("                     PROGRAM                    \n");
    printf("                    PALINDROM                   \n");
    printf("-----------------------------------------------\n");
    printf("            - Kamus Kata Palindrom -            \n");
    printf("|==============================================|\n\n");
    printf("DAFTAR KATA : \n\n");
    fflush(stdin);

    if ((fptr = fopen("kamuskata.txt","r")) == NULL){
        printf("Error: File tidak ada!");
        exit(1);
    }

    while(fgets(buff, sizeof(buff), fptr)){
        printf("%s", buff);
    }

    printf("==============================================\n");
    printf("        1.Ulangi     2.Menu      3.Keluar   \n");
    printf("----------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilih = validasiPilihan();
    system("cls");

    switch(pilih){
	    case 1:
        list_palindrom();
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
    int pilih;

    printf("|==============================================|\n");
    printf("                     PROGRAM                    \n");
    printf("                    PALINDROM                   \n");
    printf("-----------------------------------------------\n");
    printf("               - Oleh Kelompok 14 -             \n");
    printf("|==============================================|\n\n");
    printf("Daftar Pilihan :\n");
    printf("\t1. Cek Kata Palindrom\n");
    printf("\t2. Kamus Kata Palindrom\n");
    printf("\t3. Keluar\n");
    printf("----------------------------------------------\n");
    printf("\nMasukkan Pilihan Anda   : ");
    pilih = validasiPilihan();
    system ("cls");

    switch(pilih){
	    case 1:
        cek_palindrom();
	    break;
	    case 2:
	    list_palindrom();
	    break;
	    default:
	    exit(0);
	    break;
    }

    return 0;
}

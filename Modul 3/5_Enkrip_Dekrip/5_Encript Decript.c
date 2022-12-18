#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char str[255];

char validasiString(){
	int i = 0;

	printf("Masukkan Plaintext : ");
	scanf("%[^\n]", str); fflush(stdin);

	if(isalpha(str[0]) == 0){
		printf("MASUKKAN TIDAK VALID\n");
		printf("Tidak terdapat inputan, harap masukkan inputan!!!\n");
		printf("\n");
		validasiString();
	}else if (strlen(str) < 255){
		for (i = 0; i < strlen(str); i++){
			if (isdigit(str[i]) != 0){
				printf("MASUKKAN TIDAK VALID\n");
				printf("Input tidak boleh mengandung angka!!!\n");
				printf("\n");
				validasiString();
			}else if (ispunct(str[i]) != 0){
				printf("MASUKKAN TIDAK VALID\n");
				printf("Input tidak boleh mengandung tanda baca!!!\n");
				printf("\n");
				validasiString();
			}else{
				continue;
			}
		}
	}else{
		printf("      MASUKKAN TIDAK VALID\n");
		printf("      Input tidak boleh lebih dari 255 karakter!!!\n");
		printf("\n");
		validasiString();
	}
}

int validasimenu() {
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
        printf("INPUT TIDAK SESUAI\n\n");
        printf("Masukan Pilihan Menu : ");
        validasimenu();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=3){
            return val;
        }else{
            printf("INPUT TIDAK SESUAI\n\n");
            printf("Masukan Pilihan Menu : ");
            validasimenu();
        }
    }
}

int validasi(){
	int geser;
	char huruf;
	scanf("%d%c",&geser,&huruf);
	if(huruf!='\n'){
		printf("Inputan anda salah!\n");
		printf("Silahkan masukan ulang : ");
		fflush(stdin);
		return validasi();
	}else{
		return geser;
	}
}

int main();

void enkripsi(){
	char *pointerStr, cipher;
	int i, key, pilihan;
	printf("=========================================\n\n");
    printf("           PROGRAM ENKRIPSI\n\n");
    printf("=========================================\n");
	printf("Jumlah pergeseran : ");
	key=validasi();
	validasiString();
	pointerStr = str;

	for(i = 0; str[i] != '\0'; ++i){
		cipher = str[i];

		if(cipher >= 'a' && cipher <= 'z'){
			cipher = cipher + key;

			if (key > 0){
                if(cipher > 'z'){
                    cipher = cipher - 'z' + 'a' - 1;
                }
			}else{
                if(cipher < 'a'){
                    cipher = cipher - 'a' + 'z' + 1;
                }
			}

			str[i] = cipher;
		}
		else if(cipher >= 'A' && cipher <= 'Z'){
			cipher = cipher + key;

			if (key > 0){
                if(cipher > 'Z'){
                    cipher = cipher - 'Z' + 'A' - 1;
                }
			}else{
                if(cipher < 'A'){
                    cipher = cipher - 'A' + 'Z' + 1;
                }
			}

			str[i] = cipher;
		}
	}

	printf("\n-----------------------------------------\n");
	printf("\nHasil Enkripsi\t  : %s", str);

    printf("\n=========================================\n");
    printf("     1.Ulangi      2.Kembali       3.Exit\n");
    printf("-----------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasimenu();
    system("cls");

	switch(pilihan){
	    case 1:
        enkripsi();
	    break;
	    case 2:
        main();
	    break;
	    default:
	    exit(0);
	    break;
    }

}

void dekripsi(){
	char *pointerStr, cipher, pilihan;
	int i, key;
	printf("=========================================\n\n");
    printf("           PROGRAM DESKRIPSI\n\n");
    printf("=========================================\n");
	printf("Jumlah pergeseran : ");
	key=validasi();
	validasiString();
	pointerStr = str;

	for(i = 0; str[i] != '\0'; ++i){
		cipher = str[i];

		if(cipher >= 'a' && cipher <= 'z'){
			cipher = cipher - key;

            if(key > 0){
                if(cipher < 'a'){
                    cipher = cipher + 'z' - 'a' + 1;
                }
            }else{
                if(cipher > 'z'){
                    cipher = cipher + 'a' - 'z' - 1;
                }
            }

			str[i] = cipher;
		}
		else if(cipher >= 'A' && cipher <= 'Z'){
			cipher = cipher - key;

			 if(key > 0){
                if(cipher < 'A'){
                    cipher = cipher + 'Z' - 'A' + 1;
                }
            }else{
                if(cipher > 'Z'){
                    cipher = cipher + 'A' - 'Z' - 1;
                }
            }

			str[i] = cipher;
		}
	}

    printf("\n-----------------------------------------\n");
	printf("\nHasil Deskripsi\t  : %s", str);

    printf("\n=========================================\n");
    printf("     1.Ulangi      2.Kembali       3.Exit\n");
    printf("-----------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasimenu();
    system("cls");

	switch(pilihan){
	    case 1:
        dekripsi();
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
    int menu;
    int ulang;

    printf("=========================================\n\n");
    printf("      Program Enkripsi dan Dekripsi\n\n");
	printf("=========================================\n");
	printf("\t1. Enkripsi\n");
	printf("\t2. Deskripsi\n");
	printf("\t3. Keluar\n");
	printf("=========================================\n");
	printf(" Masukkan menu pilihan : ");
    menu = validasimenu();

	system("cls");
    if(menu == 1){
        enkripsi();
    }
    else if(menu == 2){
        dekripsi();
    }
    else if(menu == 3){
        printf("-----------------------------------------\n");
        printf("               TERIMA KASIH\n");
        printf("-----------------------------------------\n");
        exit(0);
    }
    else{
        system("cls");
        printf("=========================================\n");
        printf("          INPUTKAN DENGAN BENAR          \n");
        printf("=========================================\n\n");
        main();
    }

return(0);
}


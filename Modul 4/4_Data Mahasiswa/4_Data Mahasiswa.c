#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>

FILE *fMhs, *fTempMhs;

void intro(),
    menuData(),
    cariData(),
    inputData(),
    lihatData(),
    keluar(),
    ulangProgram();
int validasiInteger();

int main() {
    intro();
    return 0;
}

void intro() {
	printf("||================================================================||\n");
	printf("||              SISTEM INFORMASI DATA MAHASISWA 4.4               ||\n");
	printf("||================================================================||\n");
	printf("||                         KELOMPOK 14                            ||\n");
	printf("||================================================================||\n");
    getch();
    system("clear || cls");
    menuData();
}

void menuData() {
    system("clear || cls");
    printf("|| ================================================== ||\n");
    printf("||                    Data Mahasiswa                  ||\n");
    printf("|| ================================================== ||\n");
    printf("|| ================================================== ||\n");
    printf("|| 1. Cari  Data                                      ||\n");
    printf("|| 2. Input Data                                      ||\n");
    printf("|| 3. Lihat Data                                      ||\n");
    printf("|| 4. Keluar                                          ||\n");
    printf("|| ================================================== ||\n");

    while (true) {
        printf("|| Mohon masukkan kode pilihan anda : ");
        int kode = validasiInteger();
        printf("|| ================================================== ||\n");
        if (kode == 1) {
            system("cls || clear");
            cariData();
            getch();
            break;
        } else if (kode == 2) {
            system("clear || cls");
            inputData();
            getch();
            break;
        } else if (kode == 3) {
            system("clear || cls");
            lihatData();
            getch();
            break;
        } else if (kode == 4) {
            system("clear || cls");
            keluar();
            getch();
            break;
        } else {
            printf("|| Maaf, kode tidak ada atau salah.\n");
        }
    }
    ulangProgram();
}

void cariData() {
    // Read doang.
    char nim[20],
        cekNim[20],
        nama[100];
    printf("|| ================================================== ||\n");
    printf("||                 Cari Data Mahasiswa                ||\n");
    printf("|| ================================================== ||\n");

    // Input NIM.
    while (true) {
        int salah = 0;
        printf("|| Masukkan NIM  : ");
        scanf("%[^\n]", nim);
        fflush(stdin);
        for (int i = 0; i < strlen(nim); i++) {
            if(!isdigit(nim[i])) salah++;
        }
        if ((salah == 0) && (strlen(nim) == 10)) break;
        else printf("|| Maaf NIM salah, NIM harus 10 digit.\n");
    }

    // Cari data.
    fMhs = fopen("database.txt", "r");
    int read;
    int notFound = true;
    do {
        read = fscanf(fMhs, "%19[^,],%99[^\n]\n", cekNim, nama);
        if (read == 2) {
            if (strcmp(cekNim, nim) == 0) {
                printf("|| NIM  : %s\n", cekNim);
                printf("|| Nama : %s\n", nama);
                notFound = false;
                break;
            }
        }
    } while (!feof(fMhs));
    if (notFound) {
        printf("|| NIM tidak ditemukan.\n");
    }
    fclose(fMhs);
    printf("|| ================================================== ||\n");
}

void lihatData(){
    printf("Membaca file database.txt\n\n");
    outputfile();

    printf("\n===================================================\n");
    printf("||    Diatas merupakan isi dari file database    ||\n");
    printf("===================================================");
}

void outputfile(){
    char read;
    FILE *fp2=fopen("database.txt", "r");
    if(!fp2){
        printf("File tidak ditemukan!\n");
    }else{
        read = fgetc(fp2);
        while (read != EOF){
            printf ("%c", read);
            read = fgetc(fp2);
        }
        fclose(fp2);
    }
}

void inputData() {
    char nim[20],
        cekNim[20],
        nama[100];

    int hitung_ulang;
    do{
    printf("|| ================================================== ||\n");
    printf("||                Input Data Mahasiswa                ||\n");
    printf("|| ================================================== ||\n");

    // Input NIM.
    fMhs = fopen("database.txt", "r");
    while (true) {
        // Input NIM dan validasi format NIM.
        int salah = 0;
        printf("|| Masukkan NIM  : ");
        scanf("%[^\n]", nim);
        fflush(stdin);
        for (int i = 0; i < strlen(nim); i++) {
            if(!isdigit(nim[i])) salah++;
        }
        // Cek nim udah ada apa belum.
        if ((salah == 0) && (strlen(nim) == 10)) {
            int read;
            int notFound = true;
            do {
                read = fscanf(fMhs, "%19[^,],%99[^\n]\n", cekNim, nama);
                if (read == 2) {
                    if (strcmp(cekNim, nim) == 0) {
                        notFound = false;
                        break;
                    }
                }
            } while (!feof(fMhs));
            if (notFound) {
                printf("|| NIM valid\n");
                break;
            } else {
                printf("|| NIM sudah terdaftar.\n");
            }
        } else printf("|| Maaf NIM salah, NIM harus 10 digit.\n");
    }
    fclose(fMhs);

    // Input nama mahasiswa.
    fMhs = fopen("database.txt", "a");
    char namaMhs[100];
    while (true) {
        int salah = 0;
        printf("|| Masukkan nama : ");
        scanf("%[^\n]", namaMhs);
        fflush(stdin);
        for (int i = 0; i < strlen(namaMhs); i++) {
            if (!((namaMhs[i] >= 'A' && namaMhs[i] <= 'z') || namaMhs[i] == ' ')) salah++;
        }
        if (salah > 0) printf("|| Maaf, ada kesalahan. Mohon ulangi!\n");
        else break;
    }
    namaMhs[0] = toupper(namaMhs[0]);
    printf("|| ================================================== ||\n");
    fprintf(fMhs, "%s,%s\n", nim, namaMhs);
    fclose(fMhs);

    printf("\n\nApakah ingin menginputkan data ulang? (1 = Ya, 2 = Tidak) :");
    hitung_ulang=cek_pengulangan();
    system("cls");

    } while (hitung_ulang != 2);
}

int cek_pengulangan(){
	char cek;
	int list;
	if(cek=scanf("%d%c", &list, &cek)!=2 || list!=1 && list!=2 || cek != '\n'){
		fflush(stdin);
        printf("|| ================================================== ||\n");
		printf("||               Masukan opsi yang valid!             ||\n");
        printf("|| ================================================== ||\n");
		printf("|| Masukkan operasi yang akan dilakukan: ");
		return cek_pengulangan();
	}else{
		return list;
	}
}

void keluar(){
    system("cls");
    printf("=========================\n");
    printf("|                       |\n");
    printf("|      Terima kasih     |\n");
    printf("|                       |\n");
    printf("=========================\n");
    exit(0);
}

void ulangProgram() {
    int pilihan, menu;

    system("cls");
    printf("Apakah Anda ingin menjalankan program lagi? (1 = iya / 2 = tidak)\n");

    while (true) {
        printf("|| Mohon masukkan kode pilihan anda : ");
        int kode = validasiInteger();
        printf("|| ================================================== ||\n");

        if (kode == 1) {
            system("clear || cls");
            intro();
            break;

        } else if (kode == 2) {
            system("clear || cls");
            break;

        } else {
            printf("|| Maaf, kode tidak ada atau salah.\n");
        }
    }
}

int validasiInteger() {
    while (true) {
        char input[100], notValid;
        int valid;
        scanf("%[^\n]", input);
        fflush(stdin);
        if (sscanf(input, "%d%c", &valid, &notValid) == 1) {
            return valid;
            break;
        } else {
            printf("\n|| Maaf, input salah.\n|| ");
        }
    }
}

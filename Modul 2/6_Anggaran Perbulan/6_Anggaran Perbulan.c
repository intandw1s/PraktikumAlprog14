#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validdes(char s[],int pjg){
    int i=0;
    if(s[0] == '-'){
        i=1;
    }
    for (i=0;i<pjg;i++){
        if (s[i]!='0'&&s[i]!='1'&&s[i]!='2'&&s[i]!='3'&&s[i]!='4'&&s[i]!='5'&&s[i]!='6'&&s[i]!='7'&&s[i]!='8'&&s[i]!='9'){
            printf("\"Mohon masukkan input berupa integer(tanpa tanda minus(-))\"\n");
            printf("Masukan inputan pengganti : ");
            return 0;
        }
    }
    return 1;
}

int inputdes(){
    char sint[50];
    int panjang, n=0, cek=0;

    while(n<=0){
        while (cek!=1){
            scanf("%s", sint);
            panjang = strlen(sint);
            cek = validdes(sint,panjang);
        }
        n = convert(sint);
        if (n<=0){
            printf("\"Mohon masukkan bilangan desimal\"\n");
            printf("Masukan inputan pengganti : ");
            cek=0;
        }
    }
    return n;
}
int convert(char s[]){
    int i;
    int ns;
    int hasil=0;
    int p;
    int tanda;

    if (s[0] == '-'){
        tanda = -1;
    }
    if(tanda == -1){
        p = 1;
    }else{
        p = 0;
    }

    for (i=p; s[i] != '\0'; i++){
        ns = s[i] - 48;
        hasil = hasil * 10 + ns;
    }
    if (tanda == -1){
        hasil = hasil - (hasil*2);
    }
    return hasil;
}


float hitung_angsuran(float pinjaman, int lama){
    float angsuran=pinjaman/lama;
    return angsuran;
}

float hitung_bunga(int bulan, float pinjaman, float angsuran, float bunga_tahun){
    float bunga_temp=(pinjaman-((bulan-1)*angsuran))*bunga_tahun/12;
    return bunga_temp;
}

void cetak(float pinjaman, float bunga_tahun, int lama, float angsuran){
    float bunga_temp;
    float total;
    int bulan;

    printf("|===================================================|\n");
    printf("| Bulan |  Bunga  | Angsuran Pokok | Total Angsuran |\n");
    printf("|===================================================|\n");

    for(bulan=1;bulan<=lama;bulan++){
        bunga_temp=hitung_bunga(bulan, pinjaman, angsuran, bunga_tahun);
        total=angsuran+bunga_temp;
        printf("|%7d|%9.2f|%16.2f|%16.2f|\n",bulan, bunga_temp, angsuran, total);
    }

    printf("|===================================================|\n");
}

int main(){
    float pinjaman;
    float bunga_tahun;
    int lama;
    float angsuran;
    char ulang;

    start:
    printf("Program Menghitung Angsuran\n\n");
    printf("Masukkan data di bawah!\n");
    printf("Pokok Pinjaman\t: ");
    pinjaman=inputdes();
    printf("Bunga/tahun\t: ");
    bunga_tahun=inputdes();
    printf("Lama pinjaman\t: ");
    lama=inputdes();
    system("cls");

    bunga_tahun=bunga_tahun/100;
    angsuran=hitung_angsuran(pinjaman, lama);

    cetak(pinjaman, bunga_tahun, lama, angsuran);
	
	perulangan:
    printf("\n\nApakah anda ingin melakukan perhitungan lain? (y/t)\n");
    scanf("%s", &ulang);
    if(ulang== 'y'){
        system("cls");
        goto start;
    }else if(ulang== 't'){
        exit(0);
    }else{
    	system("cls");
        printf("Maaf input salah.");
        goto perulangan;
    }

    return 0;
}

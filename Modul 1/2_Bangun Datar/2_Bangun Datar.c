#include<stdio.h>
#include<windows.h>
#include<math.h>


float a,b,c,d,d1,d2,i,k,l,ls,p,r,s,sisi,t;
const float phi=3.14;
void header(void);
void input_pil(void);
void pengerjaan(void);
void menu(void);
int validasi();


int main(){

	header();
	input_pil();
	pengerjaan();
	menu();

}

void header(){
	system("cls");
	printf("==========Program Menghitung Luas dan Keliling Bangun Datar==========\n");
	printf("====================Kelompok 14 Alprog===============================\n");
	printf(" 1. Progam Menghitung Segitiga Sembarang\n 2. Program Menghitung Belah Ketupat\n 3. Program Menghitung Jajar Genjang\n 4. Program Menghitung Trapesium\n 5. Program Menghitung Lingkaran\n ");
	printf("=====================================================================\n");
	printf("=====================================================================\n");
}

void input_pil(){

	printf("Masukan pilihan: ");
	i = validasi(2);
	// scanf("%f", &i);
	system("cls");

}

	void pengerjaan(){    

		if (i==1){
			printf("Program Menghitung Segitiga Sembarang\n");
			printf(" 1. Menghitung Luas\n 2. Menghitung Keliling\n");
			printf("Masukan pilihan: ");
			i = validasi();
			//scanf ("%f", &i);
			system("cls");
			if (i==1){
				printf("Program Menghitung Luas\n");
				printf("Masukan nilai a: ");
				scanf ("%f", &a);
				printf("Masukan nilai b: ");
				scanf ("%f", &b);
				printf("Masukan nilai c: ");
				scanf ("%f", &c);
				s=0.5*(a+b+c);
                ls=sqrt(s*(s-a)*(s-b)*(s-c));
				printf("Maka Nilai luas segitiga sembarang adalah %.2f\n", ls);

			}
			else if (i==2){
				printf("Program Menghitung Keliling\n");
				printf("Masukan nilai sisi : ");
				scanf ("%f", &sisi);
				k=sisi+sisi+sisi;
				printf("Maka nilai keliling segitiga sembarang adalah %.2f\n",k);
			
			}
		}
	
		else if(i==2){
			printf ("Program Menghitung Belah Ketupat\n");
			printf (" 1. Menghitung Luas\n 2. Menghitung Keliling\n");
			printf ("Masukan pilihan: ");
			scanf ("%f", &i);
			system("cls");

				if(i==1){
					printf("Program Menghitung Luas Belah Ketupat\n");
					printf("Masukan nilai diagonal 1: ");
					scanf ("%f", &d1);
					printf("Masukan nilai diagonal 2: ");
					scanf ("%f", &d2);
					l=0.5*d1*d2;
					printf("Maka nilai luas belah ketupat adalah %.2f\n", l);

				}

				else if(i==2){
					printf("Program Menghitung Keliling Belah Ketupat\n");
					printf("Masukan nilai sisi: ");
					scanf ("%f", &sisi);
					k=4*sisi;
					printf("Maka nilai keliling belah ketupat adalah %.2f\n", k);

				}
		}

		else if(i==3){
			printf("Program Menghitung Jajar Genjang\n");
			printf("1. Menghitung Luas\n2. Menghitung Keliling\n");
			printf("Masukan pilihan: ");
			scanf ("%f", &i);
			system("cls");

				if(i==1){
					printf("Program Menghitung Luas Jajar Genjang\n");
					printf("Masukan nilai alas: ");
					scanf ("%f", &a);
					printf("Masukan nilai tinggi: ");
					scanf ("%f", &t);
					l=a*t;
					printf("Maka nilai luas jajar genjang adalah %.2f\n", l);
				}

				else if(i==2){
					printf("Program Menghitung Keliling Jajar Genjang\n");
					printf("Masukan nilai panjang: ");
					scanf ("%f", &p);
					printf("Masukan nilai lebar : ");
					scanf ("%f", &l);
					k=2*p+2*l;
					printf("Maka nilai keliling jajar genjang adalah %.2f\n", k);
	
				}
		}

		else if(i==4){
			printf("Program Menghitung Trapesium\n");
			printf("1. Menghitung Luas\n2. Menghitung Keliling\n");
			printf("Masukan pilihan: ");
			scanf ("%f", &i);
			system("cls");
				if(i==1){
					printf("Program Menghitung Luas Trapesium\n");
					printf("Masukan nilai alas a: ");
					scanf ("%f", &a);
					printf("Masukan nilai alas b: ");
					scanf ("%f", &b);
					printf("Masukan nilai tinggi: ");
					scanf ("%f", &t);
					l=0.5*(a+b)*t;
					printf("Maka nilai luas Trapesium adalah %.2f\n", l);
				}

				else if(i==2){
					printf("Program Menghitung Keliling Trapesium\n");
					printf("Masukan nilai a: ");
					scanf ("%f", &a);
					printf("Masukan nilai b : ");
					scanf ("%f", &b);
					printf("Masukan nilai c: ");
					scanf ("%f", &c);
					printf("Masukan nilai d: ");
					scanf ("%f", &d);
					k=a+b+c+d;
					printf("Maka nilai keliling Trapesium adalah %.2f\n", k);
				}
		}

		else if(i==5){
			printf("Program Menghitung Lingkaran\n");
			printf("1. Menghitung Luas\n2. Menghitung Keliling\n");
			printf("Masukan pilihan: ");
			scanf ("%f", &i);
			system("cls");
				if(i==1){
					printf("Program Menghitung Luas Lingkaran\n");
					printf("Masukan nilai jari-jari: ");
					scanf ("%f", &r);
					l=phi*r*r;
					printf("Maka nilai luas Lingkaran adalah %.2f\n", l);
				}

				else if(i==2){
					printf("Program Menghitung Keliling Lingkaran\n");
					printf("Masukan nilai jari-jari: ");
					scanf ("%f", &r);
					k=phi*r*2;
					printf("Maka nilai keliling Lingkaran adalah %.2f\n", k);
				}
		}


	}
	

	void menu(){
		int pilih;
	
		printf("1. Balik Ke Menu\n");
		printf("2. Keluar Dari Program\n");
		printf("Pilihan: ");
		pilih = validasi(1);

		// scanf("%d", &pilih);
	
			if (pilih==1){
				main();
		
			}
	
			else if (pilih==2){
				exit(0);
    		}
	
	}


	int validasi(int x){
		double pilihan = 0;
		int hasil;
		int i = 0;

		//perulangan untuk validasi
		do{
			pilihan = scanf("%d", &hasil);
			
			if (pilihan == 0){
				getchar();
				printf("Input invalid! Pilih dengan benar : ");
			}
			else if (x == 1){
				if (hasil > 2){
					printf("Input invalid! Pilih dengan benar : ");
				}
				else {
					i = 1;
				}  
			}
			else if(x == 2){
				if (hasil > 5){
					printf("Input invalid! Pilih dengan benar : ");
				}
				else {
					i = 1;
				}  
			}
			else{
				i = 1;
			} 
		} while (i != 1);

		return hasil;
	}
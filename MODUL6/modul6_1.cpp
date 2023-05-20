#include<iostream>
#include<conio.h>
#include<cstdlib>

using namespace std;

void tampil(string nama[], string id[], string waktu[], int n){
	cout << "===========================================================\n";
	cout << "                     DAFTAR ID PEMBELI\n";
	cout << "===========================================================\n";
	cout << "No.\t|  Waktu Pembelian  |   ID   |        NAMA\n";
	cout << "===========================================================\n";
	for(int i = 0; i < n; i++){
		cout << i + 1 << "\t|       " << waktu[i] << "       |  " << id[i] << "  |       " << nama[i] << endl;
	}
	cout << "===========================================================\n";
}

void sequential(string nama[], string id[], int n){
	bool ketemu;
	string cari;
	cout << "Cari data dengan memasukkan ID : ";
	cin >> cari;
	for(int i = 0; i < n; i++){
		ketemu = true;
		if(cari == id[i]){
			cout << "\nData ID ditemukan dengan nama " << nama[i] << " pada indeks ke - " << i << ", data ke - " << i + 1 << ".";
			break;
		}
		else
			ketemu = false;
	}
	if(ketemu == false)
		cout << "\nData tidak ditemukan.";
	getch();
}

void binary(string nama[], string id[], string waktu[], int n){
	string cari;
	int idInt[n];
	for(int i = 0; i < n; i++){
		idInt[i] = atoi(id[i].c_str());
	}
	int batasAtas = 0, batasBawah = n-1, tengah = 0;
	bool ketemu = false;
        
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
        	if(idInt[j] > idInt[j + 1]){
                int tampung = idInt[j];
                string tp = id[j];
                string temp = nama[j];
                string tem = waktu[j];
                idInt[j] = idInt[j + 1];
                nama[j] = nama[j + 1];
                id[j] = id[j + 1];
                waktu[j] =waktu[j + 1];
                idInt[j + 1] = tampung;
                nama[j + 1] = temp;
                id[j + 1] = tp;
                waktu[j + 1] = tem;
            }
        }
    }
    cout << "===========================================================\n";
	cout << "            DAFTAR ID PEMBELI SETELAH DIURUTKAN\n";
	cout << "===========================================================\n";
	cout << "No.\t|  Waktu Pembelian  |   ID   |        NAMA\n";
	cout << "===========================================================\n";
	for(int i = 0; i < n; i++){
		cout << i + 1 << "\t|       " << waktu[i] << "       |  " << id[i] << "  |       " << nama[i] << endl;
	}
	cout << "===========================================================\n\n";
    cout << "Cari data dengan memasukkan ID : ";
	cin >> cari;
	int cr = atoi(cari.c_str());
        
    while((batasAtas <= batasBawah) && (ketemu == false)){
	    tengah = (batasAtas + batasBawah)/2;
	    if(cr == idInt[tengah]){
	        ketemu = true;
	    }else if(idInt[tengah] <= cr){
	        batasAtas = tengah + 1;                
	    }else{
	        batasBawah = tengah - 1;
	    }
    }
    if(ketemu){
        cout << "\nData ID ditemukan dengan nama " << nama[tengah] << " pada indeks ke - " << tengah << ", data ke - " << tengah + 1 << ".";
	}else{
        cout << "\nData tidak ditemukan.";
    }
    getch();
}

int main(){
	string cari, x, y;
	int n, pilih;
	cout << "Masukan Jumlah Pembeli: ";
	cin >> n;
	cout << "\n\n===================================================\n";
	cout << "==           PROSES INPUT DATA PEMBELI           ==\n";
	cout << "===================================================\n\n";
	string nama[n], id[n], Tid[n], Tnama[n], Twaktu[n], waktu[n];
	for(int i = 0; i < n; i++){
		cout << "== Data Pembeli Ke - " << i + 1 << " ==\n";
		cout << "Masukan Nama Pembeli          : ";
		fflush(stdin); getline(cin, nama[i]);
		cout << "Masukkan Jam Pembelian   (JJ) : ";
		cin >> x;
		cout << "Masukkan Menit Pembelian (MM) : ";
		cin >> y;
		id[i] = x + y;
		Tid[i] = id[i];
		Tnama[i] = nama[i];
		waktu[i] = x + "." + y;
		Twaktu[i] = waktu[i];
		cout << endl;
	}
	do{
		system("cls");
		tampil(Tnama, Tid, Twaktu, n);
		cout << "Pilih Metode Pencarian\n";
		cout << "1. Sequential Search\n";
		cout << "2. Binary Search\n";
		cout << "3. Keluar\n\n";
		cout << "Pilih Menu : ";
		cin >> pilih;
		cout << endl;
		switch(pilih){
			case 1:
				sequential(Tnama, Tid, n);
				break;
			case 2:
				binary(nama, id, waktu, n);
				break;
			case 3:
				cout << "Program telah selesai.";
				exit(0);
			default:
				cout << "Menu tidak tersedia.";
				getch();
		}
	}while (pilih != 3);
}

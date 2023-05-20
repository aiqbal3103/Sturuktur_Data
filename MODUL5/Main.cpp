#include <iostream>
#include <string>

using namespace std;

struct Data_Mahasiswa {
    string nama, NIM, angkatan;
};

int Jumlah_mhs;
Data_Mahasiswa *mhs;

void Menambahkan_Data() {
    cout << "Banyak Mahasiswa yang ingin ditambah datanya: "; 
    cin >> Jumlah_mhs;
    cout << endl;
    cin.ignore();
    mhs = new Data_Mahasiswa[Jumlah_mhs];
    cout << "==============================\n" << endl;
    cout << "MASUKKAN DATA\n" << endl;
    for(int i = 0; i < Jumlah_mhs; i++) {
        cout << "Data Mahasiswa ke - " << i+1 << endl;
		getline (cin,mhs[i].nama);
		cout << "Nama  \t: ";
        cout << "NIM   \t: "; 
        getline (cin,mhs[i].NIM);
        cout << "Angkatan : "; 
		getline (cin,mhs[i].angkatan);
        cout << endl;
    }
}

void Menampilkan_Data() {
    for(int i = 0; i < Jumlah_mhs; i++) {
        cout << "Data Mahasiswa ke - " << i+1 << endl;
        cout << "Nama  \t: " << mhs[i].nama << endl;
        cout << "NIM   \t: " << mhs[i].NIM << endl;
        cout << "Angkatan : " << mhs[i].angkatan<< endl;
        cout << endl;
    }
}

int main() {ff
    int MainMenu;
    bool keluar = false;
    while (!keluar) {
        cout << "===== Menu =====" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Tampilkan Data" << endl;
        cout << "3. Keluar" << endl;
        cout << "PILIH MENU: ";
        cin >> MainMenu;
	    cin.ignore();
        switch (MainMenu) {
            case 1:
                Menambahkan_Data();
				break;
            case 2:
                Menampilkan_Data();
                break;
            case 3:
                keluar = true;
                cout << "Terima Kasih!" << endl;
                break;
            default:
                cout << "Menu yang Anda pilih tidak tersedia." << endl;
                break;
        }
    }
}

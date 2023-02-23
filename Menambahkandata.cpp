#include <iostream>
#include <string>

using namespace std;

struct Data_Mahasiswa {
    string nama, NIM, email;
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
        cout << "Email \t: " << mhs[i].email << endl;
        cout << endl;
    }
}

void Menghapus_Data() {
    int nomor_mahasiswa;
    cout << "Pilih nomor mahasiswa yang ingin dihapus (1-" << Jumlah_mhs << "): ";
    cin >> nomor_mahasiswa;

    // validasi nomor mahasiswa yang dipilih
    while (nomor_mahasiswa < 1 || nomor_mahasiswa > Jumlah_mhs) {
        cout << "Nomor mahasiswa yang Anda pilih tidak valid. Silakan coba lagi." << endl;
        cout << "Pilih nomor mahasiswa yang ingin dihapus (1-" << Jumlah_mhs << "): ";
        cin >> nomor_mahasiswa;
    }

    // memindahkan data ke array baru tanpa data mahasiswa yang dihapus
    Data_Mahasiswa *temp = new Data_Mahasiswa[Jumlah_mhs - 1];
    for(int i = 0, j = 0; i < Jumlah_mhs; i++) {
        if(i != nomor_mahasiswa - 1) {
            temp[j] = mhs[i];
            j++;
        }
    }
    delete[] mhs; // membebaskan memori array yang lama
    Jumlah_mhs--; // mengurangi jumlah mahasiswa
    mhs = temp; // mengganti array yang lama dengan array baru yang sudah dihapus

    cout << "Data mahasiswa berhasil dihapus." << endl << endl;
}

int main() {
    int MainMenu;
    bool keluar = false;
    while (!keluar) {
        cout << "===== Menu =====" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Tampilkan Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Keluar" << endl;
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
				Menghapus_Data();
				break;
            case 4:
                keluar = true;
                cout << "Terima Kasih!" << endl;
                break;
            default:
                cout << "Menu yang Anda pilih tidak tersedia." << endl;
                break;
        }
    }
    delete[] mhs; //membebaskan memori yang dialokasikan sebelumnya
    return 0;
}

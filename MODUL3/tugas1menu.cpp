#include <iostream>
#include <string>

using namespace std;

// deklarasi struktur data untuk node linked list
struct Mahasiswa {
    string nim;
    string nama;
    string jenisKelamin;
    Mahasiswa* next;
};

// deklarasi fungsi untuk menambahkan node ke linked list
void tambahNode(Mahasiswa** head, string nim, string nama, string jenisKelamin) {
    // alokasi memori untuk node baru
    Mahasiswa* newNode = new Mahasiswa;
    newNode->nim = nim;
    newNode->nama = nama;
    newNode->jenisKelamin = jenisKelamin;
    newNode->next = nullptr;

    // jika linked list kosong, maka node baru menjadi head
    if (*head == nullptr) {
        *head = newNode;
    }
    // jika linked list tidak kosong, tambahkan node baru ke akhir linked list
    else {
        Mahasiswa* current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// deklarasi fungsi untuk mencetak isi linked list
void cetakList(Mahasiswa* head) {
    // jika linked list kosong, tidak ada yang dicetak
    if (head == nullptr) {
        cout << "Linked list kosong" << endl;
    }
    // jika linked list tidak kosong, cetak isi linked list
    else {
        Mahasiswa* current = head;
        while (current != nullptr) {
            cout << current->nim << "\t" << current->nama << "\t" << current->jenisKelamin << endl;
            current = current->next;
        }
    }
}

// deklarasi fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "Menu:" << endl;
    cout << "1. Tambah data mahasiswa" << endl;
    cout << "2. Cetak data mahasiswa" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilihan Anda: ";
}

int main() {
    // deklarasi head linked list
    Mahasiswa* head = nullptr;

    // deklarasi variabel untuk menu
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                // minta input data dari pengguna
                string nim, nama, jenisKelamin;
                cout << "Masukkan NIM mahasiswa: ";
                cin >> nim;
                cout << "Masukkan nama lengkap mahasiswa: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan jenis kelamin mahasiswa (L/P): ";
                cin >> jenisKelamin;
                tambahNode(&head, nim, nama, jenisKelamin);
                break;
            }
            case 2: {
                // cetak isi linked list
                cetakList(head);
                break;
            }
            case 3:
                // keluar dari program
                cout << "Terima kasih!" << endl;
                break;
            default:
                // pilihan tidak valid
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (pilihan != 3);

    return 0;
}

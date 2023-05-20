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
    newNode->next = NULL;

    // jika linked list kosong, maka node baru menjadi head
    if (*head == NULL) {
        *head = newNode;
    }
    // jika linked list tidak kosong, tambahkan node baru ke akhir linked list
    else {
        Mahasiswa* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// deklarasi fungsi untuk mencetak isi linked list
void cetakList(Mahasiswa* head) {
    // jika linked list kosong, tidak ada yang dicetak
    if (head == NULL) {
        cout << "Linked list kosong" << endl;
    }
    // jika linked list tidak kosong, cetak isi linked list
    else {
        Mahasiswa* current = head;
        while (current != NULL) {
            cout << current->nim << "\t" << current->nama << "\t" << current->jenisKelamin << endl;
            current = current->next;
        }
    }
}

int main() {
    // deklarasi head linked list
    Mahasiswa* head = NULL;

    // minta input data dari pengguna
    string nim, nama, jenisKelamin;
    int n;
    cout << "Masukkan jumlah mahasiswa yang ingin dimasukkan: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Masukkan NIM mahasiswa ke-" << i+1 << ": ";
        cin >> nim;
        cout << "Masukkan nama lengkap mahasiswa ke-" << i+1 << ": ";
        cin.ignore();
        getline(cin, nama);
        cout << "Masukkan jenis kelamin mahasiswa ke-" << i+1 << " (L/P): ";
        cin >> jenisKelamin;
        tambahNode(&head, nim, nama, jenisKelamin);
    }

    // cetak isi linked list
    cetakList(head);

    return 0;
}

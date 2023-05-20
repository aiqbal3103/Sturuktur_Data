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

int main() {
    // deklarasi head linked list
    Mahasiswa* head = nullptr;

    // tambahkan node baru ke linked list
    tambahNode(&head, "123456789", "John Doe", "Laki-laki");

    // cetak isi linked list
    cetakList(head);

    return 0;
}

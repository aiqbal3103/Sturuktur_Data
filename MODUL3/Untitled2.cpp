#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct Node {
  string data;
  Node* next;
  Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

void tambah_awal_list() {
  Node* baru = new Node();
  cout << "Masukkan Data: ";
  cin >> baru->data;
  baru->next = NULL;
  baru->prev = NULL;
  if (head == NULL) {
    head = baru;
    tail = baru;
  } else {
    baru->next = head;
    head->prev = baru;
    head = baru;
  }
}

void menambah_node_di_akhir() {
  Node* baru = new Node();
  cout << "Masukkan Data: ";
  cin >> baru->data;
  baru->next = NULL;
  if (head == NULL) {
    head = baru;
    tail = baru;
  } else {
    tail->next = baru;
    baru->prev = tail;
    tail = baru;
  }
}

void Hapus_tengah_list() {
  int banyakdata, posisi_hapus, poshapus;
  Node* hapus, * bantu, * bantu2;
  if (head != NULL) {
    cout << "Dihapus pada data ke: ";
    cin >> posisi_hapus;
    banyakdata = 1;
    bantu = head;
    while (bantu->next != NULL) {
      bantu = bantu->next;
      banyakdata++;
    }
    if ((posisi_hapus < 1) || (posisi_hapus > banyakdata)) {
      cout << "Belum ada data!\n";
    } else {
      bantu = head;
      poshapus = 1;
      while (poshapus < (posisi_hapus - 1)) {
        bantu = bantu->next;
        poshapus++;
      }
      hapus = bantu->next;
      bantu2 = hapus->next;
      bantu->next = hapus->next;
      if (hapus == tail) {
        tail = bantu;
      } else {
        bantu2->prev = bantu;
      }
      delete hapus;
    }
  } else {
    cout << "Data masih kosong, tidak bisa hapus data dari tengah!\n";
  }
  getch();
}

void display_list() {
  Node* temp = head;
  cout << endl;
  cout << "Data yang dimasukkan = ";
  if (temp == NULL) {
    cout << "List kosong!\n";
  } else {
    while (temp != NULL) {
      cout << temp->data << ",";
      if (temp == tail) {
        cout << " ";
      }
      temp = temp->next;
    }
    cout << endl;
  }
  getch();
}

int main() {
  int option;
  do {
    system("cls");
    cout << "      MENU UTAMA  :    " << endl;
    cout << "_______________________" << endl;
    cout << " 1. Tambah awal list   " << endl;
    cout << " 2. Tambah akhir list  " << endl;
    cout << " 3. Hapus list  " << endl;
    cout << " 4. Cetak Data         " << endl;
    cout << " 5. Keluar             " << endl;
    cout << endl << " Pilihan : ";
    cin >> option;
    switch (option) {
      case 1:
//        system("cls");
        tambah_awal_list();
        break;
      case 2:
        system("cls");
        menambah_node_di_akhir();
        break;
      case 3:
        system("cls");
        Hapus_tengah_list();
        break;
      case 4:
        display_list();
        getch();
        break;
    }
  } while (option != 5);
  return 5;
}





#include <iostream>
#include <string>

using namespace std;

struct Data {
  string nama;
  string nim;
};

struct Node {
  Data data;
  Node* next;
};

Node* head;
Node* tail;
Node* curr;
Node* del;
Node* entry;

void inisialisasi() {
  head = NULL;
  tail = NULL;
}

void inputhead(Data new_data) {
  entry = new Node();
  entry->data = new_data;
  entry->next = NULL;
  if (head == NULL) {
    head = entry;
    tail = head;
  } else {
    entry->next = head;
    head = entry;
  }
}

void inputtail(Data new_data) {
  entry = new Node();
  entry->data = new_data;
  entry->next = NULL;
  if (head == NULL) {
    head = entry;
    tail = head;
  } else {
    tail->next = entry;
    tail = entry;
  }
}

void hapushead() {
  Data data;
  if (head == NULL) {
    cout << "\nlinked list kosong, penghapusan tidak bisa dilakukan" << endl;
  } else {
    data = head->data;
    del = head;
    head = head->next;
    delete del;

    cout << "\ndata yang dihapus adalah " << data.nim << endl;
  }
}

void hapustail() {
  Data data;
  if (head == NULL) {
    cout << "\nlinked list kosong, penghapusan tidak bisa dilakukan" << endl;
  } else {
    data = tail->data;
    del = head;
    while (del->next != tail) del = del->next;
    tail = del;
    del = tail->next;
    tail->next = NULL;
    delete del;

    cout << "\ndata yang dihapus adalah " << data.nim << endl;
  }
}

void cetak() {
  curr = head;
  if (head == NULL)
    cout << "\ntidak ada data dalam linked list" << endl;
  else {
    cout << "\nData yang ada dalam linked list adalah" << endl;

    while (curr != NULL) {
      cout << "Nama :" << curr->data.nama << "  Nim :";
      cout << curr->data.nim << "->";
      cout << "    ";
      curr = curr->next;
    }
    cout << "NULL";
    cout << endl;
  }
}

void menu() {
  char pilih, ulang;
  Data data;

  do {
    system("cls");
    cout << "\n \n";
    cout << "==========MENU UTAMA==========" << endl;
    cout << "------------------------------" << endl;
    cout << "Menu : " << endl;
    cout << "1. Input data Belakang	" << endl;
    cout << "2. Input data Depan 	" << endl;
    cout << "3. Hapus data Depan / Head		" << endl;
    cout << "4. Hapus data Belakng / tail		" << endl;
    cout << "5. Cetak Data			" << endl;
    cout << "6. Exit				" << endl;
    cout << "Masukkan pilihan Anda : ";
    cin >> pilih;
    cin.ignore();
    switch (pilih) {
      case '1':
        cout << "\nMasukkan nama  : ";
        getline(cin, data.nama);
        cout << "Masukkan NIM   : ";
        getline(cin, data.nim);
        inputtail(data);
        break;
      case '2':
        cout << "\nMasukkan nama  : ";
        getline(cin, data.nama);
        cout << "Masukkan NIM   : ";
        getline(cin, data.nim);
        inputhead(data);
        break;
      case '3':
        hapushead();
        break;
      case '4':
        hapustail();
        break;
      case '5':
        cetak();
        break;
      case '6':
        exit(0);
        break;
      default:
        cout << "\nPilih ulang" << endl;
    }
    cout << "\nKembali ke menu?(y/n)";
    cin >> ulang;
  } while (ulang == 'y' || ulang == 'Y');
}

int main() {
  inisialisasi();
  menu();

  return 0;
  
}
  
  
  
  
  
  

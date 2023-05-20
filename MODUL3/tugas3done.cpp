#include <iostream>
#include <string>

using namespace std;

struct Node {
  int data;
  Node* head;
  Node* tail;
};

void tambahDepan(Node** head, int data) {
  Node* newNode = new Node;
  newNode->data = datadepan;
  newNode->headdepan = nullptr;
  newNode->taildepan = *head;
  if (*head != nullptr) {
    (*head)->headdepan = newNode;
  }
  *head = newNode;
  cout <<"DATA Berhasil ditambah !!" << endl;
}

void tambahBelakang(Node** head, int data) {
  Node* newNode = new Node;
  newNode->datablkng = data;
  newNode->headblkng = nullptr;
  newNode->tailbelakang = nullptr;
  if (*head == nullptr) {
    *head = newNode;
    return;
    cout <<"DATA Berhasil ditambah !!" << endl;
  }
  Node* last = *head;
  while (last->tailbelakang != nullptr) {
    last = last->tailbelakang;
  }
  last->tailbelakang = newNode;
  newNode->headbelakang = last;
}

void hapus(Node** head, Node* hapus) {
  if (*head == nullptr || hapus == nullptr) {
    return;
  }
  if (*head == hapus) {
    *head = hapus->tailbelakang;
  }
  if (hapus->tailbelakang != nullptr) {
    hapus->tailbelakang->head = hapus->headbelakang;
  }
  if (hapus->headdepan != nullptr) {
    hapus->headdepan->tail = hapus->taildepan;
  }
  delete hapus;
}

void tampilList(Node** head, Node* tail) {
  cout << "Maju" << endl;
  while (head != nullptr) {
    cout << (*head)->datadepan << " ";
    tail = *head;
    *head = (*head)->taildepan;
  }
  cout << endl << "Mundur" << endl;
  while (tail != nullptr) {
    cout << tail->databelakang << " ";
    *tail = (*tail)->headbelakang;
  }
  cout << endl;
}

int main() {
  Node* head = nullptr;
  Node* tail = nullptr;
  Node* hapusNode = head;
  int pilihan, data, i;
  bool keluar = false;
  while (!keluar) {
    cout << "Menu:" << endl;
    cout << "1. Tambah data dari depan" << endl;
    cout << "2. Tambah data dari belakang" << endl;
    cout << "3. Hapus data dari tengah" << endl;
    cout << "4. Tampilkan data" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;
    system("cls");
    switch (pilihan) {
      case 1:
        cout << "Masukkan data: ";
        cin >> data;
        tambahDepan(&head, data);
        break;
      case 2:
        cout << "Masukkan data: ";
        cin >> data;
        tambahBelakang(&head, data);
        break;
      case 3:
        if (head == nullptr) {
          cout << "List kosong" << endl;
          break;
        }
        cout << "Masukkan data yang akan dihapus: ";
        cin >> data;
        hapusNode = head;
        while (hapusNode != nullptr && hapusNode->data != data) {
          hapusNode = hapusNode->tail;
        }
        hapus(&head, hapusNode);
        break;
      case 4:
        tampilList(&head, tail);
        break;
      case 5:
        keluar = true;
        cout << "Keluar" << endl;
        break;
      default:
        cout << "Pilihan tidak valid" << endl;
    }
  }
}
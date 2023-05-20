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
    newNode->data = data;
    newNode->head = nullptr;
    newNode->tail = *head;
    if (*head != nullptr) {
        (*head)->head = newNode;
    }
    *head = newNode;
}

void tambahBelakang(Node** head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->head = nullptr;
    newNode->tail = nullptr;
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->tail != nullptr) {
        last = last->tail;
    }
    last->tail = newNode;
    newNode->head = last;
}

void hapus(Node** head, Node* hapus) {
    if (*head == nullptr || hapus == nullptr) {
        return;
    }
    if (*head == hapus) {
        *head = hapus->tail;
    }
    if (hapus->tail != nullptr) {
        hapus->tail->head = hapus->head;
    }
    if (hapus->head != nullptr) {
        hapus->head->tail = hapus->tail;
    }
    delete hapus;
}

void tampilList(Node* head,Node* tail) {
    cout << "Maju" << endl;
    while (head != nullptr) {
        cout << head->data << " ";
        tail = head;
        head = head->tail;
    }
    cout << endl << "Mundur" << endl;
    while (tail != nullptr) {
        cout << tail->data << " ";
        tail = tail->head;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int pilihan, data,i;
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
                Node* hapusNode = head;
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
                break;
        }
    }
}

    



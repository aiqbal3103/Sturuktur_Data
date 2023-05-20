#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void tambahDepan() {
    int datadepan;
    cout << "Masukkan datandepan: ";
    cin >> datadepan;

    Node* newNode = new Node;
    newNode->data = datadepan;
    newNode->next = head;
    head = newNode;

    cout << "Data berhasil ditambahkan di depan" << endl;
}

void tambahBelakang() {
    int databelakang;
    cout << "Masukkan data belakang: ";
    cin >> databelakang;

    Node* newNode = new Node;
    newNode->data = databelakang;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    cout << "Data berhasil ditambahkan di belakang" << endl;
}

void hapusDepan() {
    if (head == nullptr) {
        cout << "Linked list kosong" << endl;
    } else {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Data berhasil dihapus dari depan" << endl;
    }
}

void hapusBelakang() {
    if (head == nullptr) {
        cout << "Linked list kosong" << endl;
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Data berhasil dihapus dari belakang" << endl;
    } else {
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
        cout << "Data berhasil dihapus dari belakang" << endl;
    }
}

void tampilkanData() {
    if (head == nullptr) {
        cout << "Linked list kosong" << endl;
    } else {
        cout << "Isi linked list:" << endl;
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

int main() {
    int pilihan;
    bool keluar = false;
    while (!keluar) {
        cout << endl << "Menu:" << endl;
        cout << "1. Tambah data dari depan" << endl;
        cout << "2. Tambah data dari belakang" << endl;
        cout << "3. Hapus data dari depan" << endl;
        cout << "4. Hapus data dari belakang" << endl;
        cout << "5. Tampilkan seluruh data" << endl;
        cout << "6. Keluar" << endl;

        cout << "Pilihan: ";
        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Input tidak valid" << endl;
        } else {
            system("cls"); 
            switch (pilihan) {
                case 1:
                tambahDepan();
                break;
            case 2:
                tambahBelakang();
                break;
            case 3:
                hapusDepan();
                break;
            case 4:
                hapusBelakang();
                break;
            case 5:
                tampilkanData();
                break;
            case 6:
                keluar = true;
                cout << "Terima Kasih" << endl;
                break;
            default:
                cout << "Menu tidak tersedia !!" << endl;
                break;
        }
    }
}
}

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

struct Buku{
    string nama;
    string penulis;
    int tterbit;
};

struct Node{
    Buku data;
    Node* prev;
    Node* next;
};
Node* head = NULL;
Node* tail = NULL;

//----------------------ADD----------------------//
void addBuku(){               
    Buku newBuku;
    cout << " Nama Buku : ";
    cin.ignore();
    getline(cin, newBuku.nama);
    cout << " Nama Penulis: ";
    getline(cin, newBuku.penulis);
    cout << " Tahun Terbit: ";
    cin >> newBuku.tterbit;

    Node *newNode = new Node;
    newNode->data = newBuku;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        newNode->prev = NULL;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    cout << " Data berhasil ditambahkan " << endl;
    getch();
}

//-------------------------HAPUS---------------------------//
void dellBuku(){
    if (head == NULL){
        cout << "Data Kosong " << endl;
        return;
    }

    string namaBuku;
    cout << "Masukan nama buku yang ingin dihapus : ";
    cin.ignore();
    getline(cin, namaBuku);

    Node* current = head;
    while (current != NULL){
        if (current -> data.nama == namaBuku){
            if (current == head && current == tail){
                head = NULL;
                tail = NULL;
            }
            else if (current == head){
                head = head -> next;
                head -> prev = NULL;
            }
            else if (current == tail){
                tail = tail -> prev;
                tail -> next = NULL;
            }
            else{
                current -> prev -> next = current -> next;
                current -> next -> prev = current -> prev;
            }
            delete current;
            cout << "BUKU berhasil dihapus " << endl;
            return;
        }
        current = current -> next;
    }
    cout << "Buku tidak ditemukan " << endl;
}
//------------------------EDIT----------------------//
void editBuku(){
    if (head == NULL){
        cout << " Data Kosong " << endl;
        return;
    }

    string namaBuku;
    cout << " Masukan nama buku yang ingin di edit : ";
    cin.ignore();
    getline(cin, namaBuku);

    Node* current = head;
    while (current != NULL){
        if (current -> data.nama == namaBuku){
            cout << "Masukan nama buku yang baru            :";
            getline(cin, current -> data.nama);
            cout << "Masukan nama penults yang baru         :";
            getline(cin, current -> data.penulis);
            cout << "Masukan tahun terbit buku yang baru   :";
            cin >> current -> data.tterbit;
            cout << "Data berhasil diperbarui" << endl;
            return;
        }
        current = current -> next;
    }
    cout << " Buku tidak ditemukan" << endl;
}

//----------------------SHOW------------------------//
void showBuku(){
    if (head == NULL){
        cout << "Data Kosong" << endl;
        return;
    }
    else{
        Node* current = head;
        while(current != NULL){
            cout << " Nama Buku :" << current -> data.nama << endl;
            cout << " Penulis   :" << current -> data.penulis << endl;
            cout << " Tahun Terbit  :" << current -> data.tterbit << endl;
            current = current -> next;
        }
    }
}

void bubbleSortNama(bool Asc_Dsc){
    if (head == NULL){
        cout << "Data Kosong" << endl;
        return;
    }

    Node *a, *b;
    Buku tempData;
    a = head;

    while (a != NULL){
        b = a -> next;
        while(b != NULL){
            if(Asc_Dsc){
                if (a -> data.nama > b -> data.nama){
                    tempData = a -> data;
                    a -> data = b -> data;
                    b -> data = tempData;
                }
            }else{
                if (a -> data.nama < b -> data.nama){
                    tempData = a -> data;
                    a -> data = b -> data;
                    b -> data = tempData;
                }
            }
            b = b -> next;
        }
        a = a -> next;
    }
}

void selectionSortNama(bool Asc_Dsc){
if (head == NULL){
    cout << " The Game List Is Empty!" << endl;
    return;
}

Node *a, *b, *minNode;
Buku tempData;

a = head;
while (a != NULL)
{
    minNode = a;
    b = a->next;
    while (b != NULL) {
        if ((Asc_Dsc && b->data.nama < minNode->data.nama) || (!Asc_Dsc && b->data.nama > minNode->data.nama))
        {
            minNode = b;
        }
        b = b->next;
    }
    if (minNode != a)
    {
        tempData = a->data;
        a->data = minNode->data;
        minNode->data = tempData;
    }
    a = a->next;
}
}

//-------------------FIFO/LIFO-------------------//
void deq(){
    if (head == NULL){
        cout << "Data Kosong" << endl;
        return;
    }
    Node* current =head;
    head = head -> next;
    if (head == NULL){
        tail == NULL;
    }else {
        head -> prev = NULL;
    }
    cout << "Buku : (" << current-> data.nama << ") Data telah dihapus" << endl;
    delete current;
}

void pop(){
    if (head == NULL)
    {
        cout << " The Game List Is Empty!" << endl;
        return;
    }
    Node *current = tail;
    tail = current->prev;
    if (tail == NULL)
    {
        head = NULL;
    }
    else
    {
        tail->next = NULL;
    }
    cout << " Game : (" << current->data.nama << ") Data telah dihapus" << endl;
    delete current;
}

//-----------------------------SEARCH-------------------------------------------------
void searchName()
{
    if (head == NULL)
    {
        cout << "Data Kosong" << endl;
        return;
    }
    string searchName;
    bool found = false;

    cout << " Masukan nama buku yang mau dicari : ";
    cin >> searchName;

    Node *current = head;

    while (current != NULL)
    {
        if (current->data.nama == searchName)
        {
        cout << "|Name   : " << current->data.nama << endl;
        cout << "|Genre  : " << current->data.penulis << endl;
        cout << "|Year   : " << current->data.tterbit << endl;
        found = true;
        }
        current = current->next;
    }
    if (!found)
    {
        cout << " Buku tidak ditemukan." << endl;
    }
}



int main(){
    int menu,mh;
    do{
        menu = 0;
        system("cls");
        cout << "[1] Tambah data" << endl;
        cout << "[2] Hapus data" << endl;
        cout << "[3] Edit data" << endl;
        cout << "[4] Tampilkan data" << endl;
        cout << "[5] EXIT" << endl;
        cout << "Masukan Pilihan: ";
        cin >> menu;
        cout << endl;
        switch (menu){
            case 1:{
                addBuku();
                break;
                };
            case 2:{
                int mhapus;
                mhapus = 0;
                showBuku();
                cout << "1. Dequeue " << endl;
                cout << "2. Enqueue " << endl;
                cout << "3. EXIT" << endl;
                cout << "Masukan Piliahan: ";
                cin >> mhapus;
                cout << endl;
                switch (mhapus){
                    case 1:{
                        deq();
                        break;
                    }
                    case 2:{
                        pop();
                        break;
                    }
                    case 3:{
                        break;
                    }
                    default:
                    cout << "Pilihan tidak ada" << endl;
                }getch();
                break;
                };
            case 3:{
                editBuku();
                getch();
                break;
            }
            case 4:{
                    int mSearch;
                    do{
                    system("cls");
                    showBuku();
                    cout << "[1] Bubble Short" << endl;
                    cout << "[2] Selection Short" << endl;
                    cout << "[3] Searching" << endl;
                    cout << "[4] Exit" << endl;
                    cout << "Masukan Pilihan :";
                    cin >> mSearch;
                    cout << endl;
                    switch(mSearch){
                        case 1:{
                            bubbleSortNama(true);
                            getch();
                            break;
                        }
                        case 2:{
                            selectionSortNama(true);
                            getch();
                            break;
                        }
                        case 3:{
                            searchName();
                            break;
                        }
                        case 4:{
                            break;
                        }
                        default:
                        cout << "Pilihan tidak ada" << endl;
                    }
                    getch();
                }while(mSearch!=4);
            }
            case 5:{
                break;
            }
            default:
            cout << "Pilihan tidak ada" << endl;
            }
            getch();
        }while (menu != 5);
    }




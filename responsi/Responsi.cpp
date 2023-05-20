#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

struct barang
{
    string namaPembeli, namaBarang, totalHarga, id;
};

struct Node
{
    barang data;
    Node *next, *prev;
};

Node *front, *rear;

Node *getNode(Node *head, int index)
{
    Node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp;
}

struct Node *newNode = new Node;

void inisiasi()
{
    front = NULL;
    rear = NULL;
}

void displayAll()
{
    Node *print;
    cout << "" << endl;
    cout << "Data Transaksi Saat Ini : " << endl;
    if (front == NULL)
    {
        cout << "Data Kosong!" << endl;
    }
    else
    {
        print = front;
        while (print != NULL)
        {
            cout << "ID           : " << print->data.id << endl;
            cout << "Nama Pembeli : " << print->data.namaPembeli << endl;
            cout << "Nama Barang  : " << print->data.namaBarang << endl;
            cout << "Total Harga  : " << print->data.totalHarga << endl
                 << endl;
            print = print->next;
        }
    }
}

void inputFirst(barang data)
{
    Node *input;
    input = new Node;
    if (front == NULL)
    {
        front = input;
        input->prev = NULL;
        input->data = data;
        input->next = NULL;
        rear = input;
    }
    else
    {
        input->next = front;
        input->data = data;
        input->prev = NULL;
        front->prev = input;
        front = input;
    }
    cout << "Data berhasil ditambahkan!" << endl;
}

string generateID()
{
    string id = "";
    srand(time(NULL)); // initialize the random seed
    for (int i = 0; i < 5; i++)
    {                             // generate a 5-character ID
        int random = rand() % 36; // generate a random number between 0 and 35
        if (random < 10)
        {
            stringstream ss;
            ss << random;
            id += ss.str(); // add a number (0-9)
        }
        else
        {
            id += char(random - 10 + 'A'); // add a letter (A-Z)
        }
    }
    return id;
}

void inputLast(barang data)
{
    Node *input;
    input = new Node;
    if (front == NULL)
    {
        front = input;
        input->prev = NULL;
        input->data = data;
        input->next = NULL;
        rear = input;
    }
    else
    {
        input->prev = rear;
        input->data = data;
        input->next = NULL;
        rear->next = input;
        rear = input;
    }
    cout << "Data berhasil ditambahkan!" << endl;
}

void hapusData()
{
    string input;
    cout << "Masukkan Id atau Nama Pembeli Yang Ingin Dihapus : ";
    cin >> input;
    Node *curr = front;
    while (curr != NULL)
    {
        if (curr->data.id == input || curr->data.namaBarang == input || curr->data.namaPembeli == input)
        {
            Node *hapus = curr;
            if (curr == front && curr == rear)
            { // jika node adalah satu-satunya node dalam list
                front = NULL;
                rear = NULL;
            }
            else if (curr == front)
            { // jika node adalah front node
                front = curr->next;
                front->prev = NULL;
            }
            else if (curr == rear)
            { // jika node adalah rear node
                rear = curr->prev;
                rear->next = NULL;
            }
            else
            { // jika node adalah node di tengah list
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            }
            delete hapus;
            cout << "Data dengan id atau nama pembeli '" << input << "' berhasil dihapus." << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "Data dengan id atau nama pembeli '" << input << "' tidak ditemukan." << endl;
}

void shellSort(Node *head, int count)
{
    for (int gap = count / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < count; i++)
        {
            Node *temp = getNode(head, i);
            for (int j = i; j >= gap; j -= gap)
            {
                Node *prev = getNode(head, j - gap);
                if (prev->data.id < temp->data.id)
                {
                    swap(prev->data, temp->data);
                    temp = prev;
                }
                else
                {
                    break;
                }
            }
        }
    }
}

void search(string pola)
{
    Node *curr = front;
    int i = 1;
    while (curr != NULL)
    {
        if (curr->data.namaPembeli.find(pola) != string::npos ||
            curr->data.totalHarga.find(pola) != string::npos ||
            curr->data.id.find(pola) != string::npos ||
            curr->data.namaBarang.find(pola) != string::npos)
        {
            cout << "Data Transaksi Ditemukan : " << endl;
            cout << "Id Transaksi : " << curr->data.id << endl;
            cout << "Nama Pembeli : " << curr->data.namaPembeli << endl;
            cout << "Nama Barang  : " << curr->data.namaBarang << endl;
            cout << "Total Harga  : " << curr->data.totalHarga << endl;
        }
        curr = curr->next;
    }
}

void edit(string update)
{
    cout << "Cari Data Yang Ingin Di Update : ";
    cin >> update;

    Node *curr = front;
    bool found = false;
    while (curr != NULL)
    {
        if (curr->data.id == update || curr->data.namaPembeli == update || curr-> data.totalHarga == update)
        {
            found = true;
            cout << "Data ditemukan. Masukkan data baru:" << endl;
            cout << "Nama Pembeli : ";
            cin >> curr->data.namaPembeli;
            cout << "Nama Barang  : ";
            cin >> curr->data.namaBarang;
            cout << "Total Harga  : ";
            cin >> curr->data.totalHarga;
            break;
        }
        curr = curr->next;
    }
    if (!found)
    {
        cout << "Data tidak ditemukan" << endl;
    }
}

int main()
{
    inisiasi();
    int choice, count = 0;
    string pola, update;
    do
    {
        system("cls");
        cout << "==========================================" << endl;
        cout << "           TOKO SEMBAKO GEMILANG          " << endl;
        cout << "==========================================" << endl;
        cout << "1. Input Front\n2. Input Rear \n3. Tampilkan Data Transaksi\n4. Cari Data Transaksi\n5. Update Data Transaksi\n6. Sorting Data Transaski\n7. Hapus Data Transaksi\n8. Keluar" << endl;
        cout << "==========================================" << endl;
        cout << "Pilihan Anda : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            barang input;
            cout << "Masukkan Nama Pembeli : ";
            cin >> input.namaPembeli;
            cout << "Masukkan Nama Barang  : ";
            cin >> input.namaBarang;
            cout << "Masukkan Total Harga  : ";
            cin >> input.totalHarga;
            input.id = generateID();
            inputFirst(input);
            count++;
            cout << "Tekan Enter Untuk Lanjut..." << endl;
            getch();
            break;
        }
        case 2:
        {
            barang input;
            cout << "Masukkan Nama Pembeli : ";
            cin >> input.namaPembeli;
            cout << "Masukkan Nama Barang  : ";
            cin >> input.namaBarang;
            cout << "Masukkan Total Harga  : ";
            cin >> input.totalHarga;
            input.id = generateID();
            inputLast(input);
            count++;
            cout << "Tekan Enter Untuk Lanjut..." << endl;
            getch();
            break;
        }
        case 3:
        {
            displayAll();
            cout << "Tekan Enter Untuk Lanjut..." << endl;
            getch();
            break;
        }
        case 4:
        {
            cout << "Pencarian Data Transaksi" << endl;
            cout << "Masukkan Id Transaksi/Nama Pembeli: ";
            cin >> pola;
            search(pola);
            cout << "Tekan Enter Untuk Lanjut..." << endl;
            getch();
            break;
        }
        case 5:
        {
            edit(update);
            cout << "Tekan Enter Untuk Lanjut..." << endl;
            getch();
            break;
        }
        case 6:
        {
            if (count > 0)
            {
                shellSort(front, count);
                cout << "Data berhasil diurutkan berdasarkan ID." << endl;
                displayAll();
            }
            else
            {
                cout << "Data masih kosong." << endl;
            }
            cout << "Tekan Enter Untuk Lanjut..." << endl;
            getch();
            break;
        }
        case 7:
        {
            hapusData();
            count--;
            cout << "Tekan Enter Untuk Lanjut..." << endl;
            getch();
            break;
        }
        case 8:
        {
            cout << "Terima kasih!" << endl;
            break;
        }
        default:
        {
            cout << "Input salah, silakan coba lagi." << endl;
            cout << "Tekan Enter Untuk Lanjut..." << endl;
            getch();
            main();
            break;
        }
        }
    } while (choice != 8);
    return 0;
}

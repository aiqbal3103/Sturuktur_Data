#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip> // untuk manipulator output std::fixed dan std::setprecision (untuk mencetak bilangan pecahan)
using namespace std;

struct Mytoko {
    string id;
    string nama_pembeli;
    string tanggal_pembelian;
    float jumlah_pembelian; 
    Mytoko *prev;
    Mytoko *next;
};

Mytoko *head = NULL;
Mytoko *tail = NULL;


// Fungsi untuk membuat ID acak dengan karakter alfanumerik
string generateRandomID(int length) {
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

void addMytoko() {
    Mytoko *newMytoko = new Mytoko;
    newMytoko->prev = NULL;
    newMytoko->next = NULL;

    // Memanggil fungsi generateRandomID untuk membuat ID acak
    newMytoko->id = generateRandomID(4);

    // menambahkan data pembeli
    cout << "Masukkan Nama Pembeli: ";
    cin.ignore();
    getline(cin, newMytoko->nama_pembeli);
    cout << "Masukkan Tanggal Pembelian: ";
    getline(cin, newMytoko->tanggal_pembelian);
    cout << "Masukkan Jumlah Pembelian: ";
    cin >> newMytoko->jumlah_pembelian;
    if (head == NULL) {
        head = newMytoko;
        tail = newMytoko;
    } else {
        tail->next = newMytoko;
        newMytoko->prev = tail;
        tail = newMytoko;
    }
    cout << "Data pembeli berhasil ditambahkan!" << endl;
}


// Fungsi untuk menghapus data
void deleteMytoko() {
string idOrnamaOrTanggal;
cout << "Masukkan ID, Nama Pembeli, atau Tanggal Pembelian yang akan dihapus: ";
cin.ignore();
getline(cin, idOrnamaOrTanggal);
Mytoko *current = head;
bool found = false;
        while (current != NULL) {
            //membandingkan inputan apakah sama dengan data 
        if (current->id == idOrnamaOrTanggal || current->nama_pembeli == idOrnamaOrTanggal || current->tanggal_pembelian == idOrnamaOrTanggal) {
        found = true;
        if (current == head && current == tail) {
        head = NULL;
        tail = NULL;
        } else if (current == head) {
        head = current->next;
        head->prev = NULL;
        } else if (current == tail) {
        tail = current->prev;
        tail->next = NULL;
        } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        }
    delete current;
    cout << "Data Pembeli berhasil dihapus!" << endl;
    break;
    }
    current = current->next;
    }
    if (!found) {
    cout << "Data Pembeli dengan ID, Nama, atau Tanggal Pembelian " << idOrnamaOrTanggal << " tidak ditemukan!" << endl;
    }
}

// Fungsi untuk mengupdate data
void updateMytoko() {
    string id;
    cout << "Masukkan ID Pembeli yang akan diupdate: ";
    cin >> id;
    Mytoko *current = head;
    while (current != NULL) {
        if (current->id == id) {
            cout << "Masukkan Nama Pembeli Baru: ";
            cin.ignore();
            getline(cin, current->nama_pembeli);
            cout << "Masukkan Tanggal Pembelian Baru: ";
            getline(cin, current->tanggal_pembelian);
            cout << "Masukkan Jumlah Pembelian: ";
            cin >> current->jumlah_pembelian;
            cout << "Data Pembeli berhasil diupdate!" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Data Pembeli dengan ID " << id << " tidak ditemukan!" << endl;
}

// Fungsi untuk menampilkan data
void displayMytokos() {
if (head == NULL) {
cout << "Tidak ada data Pembeli!" << endl;
return;
}
cout << "Daftar Pembeli:" << endl;
Mytoko *current = head;
while (current != NULL) {
cout << "ID Pembeli: " << current->id << endl;
cout << "Nama Pembeli: " << current->nama_pembeli << endl;
cout << "Tanggal Pembelian: " << current->tanggal_pembelian << endl;
cout << "Jumlah Pembelian: Rp " << fixed << setprecision(3) << current->jumlah_pembelian << endl; 
current = current->next;
cout << endl;
}
}

// Fungsi untuk mencari data
void searchMytoko() {
    int choice;
    cout << "Pilih kategori pencarian:" << endl;
    cout << "1. ID" << endl;
    cout << "2. Nama" << endl;
    cout << "3. Tanggal pembelian" << endl;
    cout << "Pilihan: ";
    cin >> choice;

    switch (choice) {
        case 1: { // Pencarian berdasarkan ID
            string id;
             cout << " " <<endl;
            cout << "Masukkan ID Pembeli yang dicari: ";
            cin >> id;
            Mytoko *current = head;
            bool found = false;
            while (current != NULL) {
                if (current->id == id) {
                    found = true;
                    cout << "ID Pembeli: " << current->id << endl;
                    cout << "Nama Pembeli: " << current->nama_pembeli << endl;
                    cout << "Tanggal Pembelian: " << current->tanggal_pembelian << endl;
                    cout << "Jumlah Pembelian: " << current->jumlah_pembelian << endl;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                cout << "Data Pembeli dengan ID " << id << " tidak ditemukan!" << endl;
            }
            break;
        }
        case 2: { // Pencarian berdasarkan Nama
            string nama_pembeli;
             cout << " " <<endl;
            cout << "Masukkan Nama Pembeli yang dicari: ";
            cin.ignore();
            getline(cin, nama_pembeli);
            Mytoko *current = head;
            bool found = false;
            while (current != NULL) {
                if (current->nama_pembeli == nama_pembeli) {
                    found = true;
                    cout << "ID Pembeli: " << current->id << endl;
                    cout << "Nama Pembeli: " << current->nama_pembeli << endl;
                    cout << "Tanggal Pembelian: " << current->tanggal_pembelian << endl;
                    cout << "Jumlah Pembelian: " << current->jumlah_pembelian << endl;
                    cout << endl;
                }
                current = current->next;
            }
            if (!found) {
                cout << "Data Pembeli dengan Nama " << nama_pembeli << " tidak ditemukan!" << endl;
            }
            break;
        }
        case 3: { // Pencarian berdasarkan Tanggal Pembelian
            string tanggal_pembelian;
             cout << " " <<endl;
            cout << "Masukkan Tanggal Pembelian yang dicari (DD/MM/YYYY): ";
            cin.ignore();
            getline(cin, tanggal_pembelian);
            Mytoko *current = head;
            bool found = false;
            while (current != NULL) {
                if (current->tanggal_pembelian == tanggal_pembelian) {
                    found = true;
                    cout << "ID Pembeli: " << current->id << endl;
                    cout << "Nama Pembeli: " << current->nama_pembeli << endl;
                    cout << "Tanggal Pembelian: " << current->tanggal_pembelian << endl;
                    cout << "Jumlah Pembelian: " << current->jumlah_pembelian << endl;
                    cout << endl;
                }
                current = current->next;
            }
            if (!found) {
                cout << " " <<endl;
                cout << "Data Pembeli dengan Tanggal Pembelian " << tanggal_pembelian << " tidak ditemukan!" << endl;
            }
            break;
        }
    }
}

// Fungsi untuk melakukan sorting shell sort secara descending
void sortMytoko(Mytoko* head)
{
    int size = 0;
    Mytoko* temp = head;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }

    //Pembagaian node menjadi 2 
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            float temp_jumlah = 0;
            string temp_id = "";
            string temp_nama = "";
            string temp_tanggal = "";
            Mytoko* current = head;
            for (int j = 0; j < i - gap; j++)
            {
                current = current->next;
            }
            Mytoko* current_gap = current->next;

//perbandingan untuk nilai dari id bertujuan untuk mengurutkan data 
            if (current->id < current_gap->id)
            {
                temp_jumlah = current->jumlah_pembelian;
                current->jumlah_pembelian = current_gap->jumlah_pembelian;
                current_gap->jumlah_pembelian = temp_jumlah;

                temp_id = current->id;
                current->id = current_gap->id;
                current_gap->id = temp_id;

                temp_nama = current->nama_pembeli;
                current->nama_pembeli = current_gap->nama_pembeli;
                current_gap->nama_pembeli = temp_nama;

                temp_tanggal = current->tanggal_pembelian;
                current->tanggal_pembelian = current_gap->tanggal_pembelian;
                current_gap->tanggal_pembelian = temp_tanggal;

//perulangan untuk membandingkan nilai dari node untuk diurutkan secara descending
                for (int k = i - gap; k >= gap; k -= gap)
                {
                    Mytoko* current2 = head;
                    for (int l = 0; l < k - gap; l++)
                    {
                        current2 = current2->next;
                    }
                    Mytoko* current2_gap = current2->next;
                    if (current2->id < current2_gap->id)
                    {
                        temp_jumlah = current2->jumlah_pembelian;
                        current2->jumlah_pembelian = current2_gap->jumlah_pembelian;
                        current2_gap->jumlah_pembelian = temp_jumlah;

                        temp_id = current2->id;
                        current2->id = current2_gap->id;
                        current2_gap->id = temp_id;

                        temp_nama = current2->nama_pembeli;
                        current2->nama_pembeli = current2_gap->nama_pembeli;
                        current2_gap->nama_pembeli = temp_nama;

                        temp_tanggal = current2->tanggal_pembelian;
                        current2->tanggal_pembelian = current2_gap->tanggal_pembelian;
                        current2_gap->tanggal_pembelian = temp_tanggal;
                    }
                }
            }
        }
    }
    cout << "DATA BERHASIL DIURUTKAN SECARA DESCENDING" <<endl;
}

// Fungsi untuk menampilkan menu
void showMenu() {
int choice;
do {
	cout << "Menu Pengelolaan Data Pembeli" << endl;
	cout << "=============================" << endl;
	cout << "1. Tambah Data" << endl;
	cout << "2. Hapus Data" << endl;
	cout << "3. Update Data" << endl;
	cout << "4. Menampilkan Data" << endl;
	cout << "5. Cari Data" << endl;
	cout << "6. Sorting Data (Shell Sort : Descending)" << endl;
	cout << "7. Keluar" << endl;
	cout << "Pilih menu: ";
	cin >> choice;
	cout << endl;
switch (choice) {
case 1:
    system("cls");
	addMytoko();
	break;
case 2:
	deleteMytoko();
	break;
case 3:
    system("cls");
	updateMytoko();
	break;
case 4:
    system("cls");
	displayMytokos();
	break;
case 5:
	searchMytoko();
	break;
case 6:
    system("cls");
	sortMytoko(head);
	break;
case 7:
	cout << "Terima kasih!" << endl;
	break;
default:
	cout << "Menu yang Anda pilih tidak tersedia!" << endl;
	break;
}
cout << endl;
} while (choice != 7);

}

//MAIN PROGRAM
int main() {
	showMenu();
	
return 0;

}

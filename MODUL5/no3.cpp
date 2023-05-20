#include <iostream>
#include <string>
using namespace std;

struct Data{
	string nim;
	string nama;
};

struct Node{
	Data data;
	Node* next;
};

Node* head;
Node* tail;
Node* curr;
Node* del;
Node* entry;

void inisialisasi(){
	head = NULL;
	tail = NULL;
}

void inputtail (Data new_data){
	entry = new Node();
	entry->data = new_data;
	entry->next = NULL;
	if (head == NULL){
		head = entry;
		tail = head;
	}else{
		tail->next = entry;
		tail=entry;
	}
}

void inputhead (Data new_data){
	entry = new Node();
	entry->data = new_data;
	entry->next = NULL;
	if (head == NULL){
		head= entry;
		tail= head;
	}else{
		entry->next = head;
		head = entry;
	}
}

void hapushead() {
	Data data;
	if(head == NULL){
		cout << "\n Linked list Kosong" <<endl;
	}else{
		data = head->data;
		del = head;
		head = head ->next;
		delete del;	
		cout <<"\n data yang dihapus adalah " <<data.nim<<endl;
	}
}

void hapustail(){
	Data data;
	if (head == NULL){
		cout <<"\n Linked list kosong" <<endl;
	}else{
		data = tail->data;
		del = head;
		while(del->next != tail) del= del->next;
		tail=del;
		del = tail->next;
		tail->next = NULL;
		delete del;
		cout << "\n data yang dihapus adalah " <<data.nim << endl;
	}
}

void cetak(){
	curr = head;
	if(head == NULL){
		cout << "\ndata tidak ada" <<endl;
	}else{
		cout <<"\n Data yang ada dalam lingked list adalah " <<endl;
		while (curr != NULL){
			cout << "Nama : " << curr->data.nama << " Nim : " ;
			cout << curr->data.nim << "-";
			cout <<"    ";
			curr = curr->next;
		}
		cout << "NULL";
		cout << endl;
	}
}

void menu(){
	char pilih,ulang;
	Data data;
	
	do{
		system("cls");
		cout << "\n \n";
		cout <<"======== MENU UTAMA ========="<<endl;
		cout <<"1. input data depan " <<endl;
		cout <<"2. input data belang " <<endl;
		cout <<"3. hapus data depan " <<endl;
		cout <<"4. hapus data belakang" <<endl;
		cout <<"5. cetal data " <<endl;
		cout <<"6. exit" <<endl;
		cout << "Pilih Menu : " ;
		cin >> pilih;
		cin.ignore();
		
		switch (pilih){
			case '2' :
				cout << "\n Masukkan Nama : ";
				getline(cin, data.nama);
				
				cout << "\n Masukkan NIM : ";
				getline(cin, data.nim);
				inputtail(data);
				break;
			case '1' :
				cout << "\n Masukkan Nama : ";
				getline(cin, data.nama);
				
				cout << "\n Masukkan NIM : ";
				getline(cin, data.nim);
				inputhead(data);
				break;
				
			case '3':
				hapushead();
				break;
			case '4' :
				hapustail();
				break;
			
			case '5':
				cetak();
				break;
			case '6':
				exit(0);
				break;
			defaul :
				cout<< "\n Pilih Ulang" <<endl;
		}
		cout << "\n Kembali Kemenu awal (y/n) : ";
		cin >> ulang;
	}while (ulang == 'y' || ulang == 'Y');
}

int main (){
	inisialisasi();
	menu();
	
	return 0;
}













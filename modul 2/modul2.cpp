#include <iostream>
#include <string>

using namespace std;

#define MAX 10

struct Music {
	string judul, penyanyi ;
}music;

struct Stact {
	Music listmusik[MAX];
	int top,bottom;
}stact;

struct Queue {
	Music listmusik[MAX];
	int front,rear,count;
}queue;

void read (Music *m){
	cout << "Judul Lagu : " << m->judul << endl;
	cout << "Nama Penyanyi : " <<m->penyanyi << endl;
}

void enqueu (Queue *q, Music m) {
if (q -> count >= MAX){
	cout << "Antrian Penuh !!!" << endl;
	return;
}else{
	q->listmusik [q->rear] = m;
	q->rear++;
	q->count++;
}
}

void push (Stact *s, Music m){
	if (s->top >= MAX){
		cout << "Antrian Penuh !!!" << endl;
		return;
	}else {
		s->listmusik[s->top] = m;
		s->top++;
	}
}

void dequeue (Queue *q, Music m){
	if (q->count <= 0){
		cout << "Antrian Kosong !!!" <<endl;
		return;
	}else{
		m =q->listmusik[q->front];
		for (int i = q->front; i < q->rear ; i++)
		q->listmusik[i] = q->listmusik[i+1];
	}
	q->rear--;
	q->count--;
}

void pop(Stact *s, Music m){
		if (s->top <= 0){
		cout << "Tumpukan Kosong !!!" <<endl;
		return;
	}else{
		m = s->listmusik[s->top-1];
		s->top--;
	}
}

void input (Queue *q, Stact *s,Music *m ){
	if (q->count >= MAX){
		cout << "Data Sudah Penuh" <<endl;
		return;
	}else{
		cout << "Data Lagu ke-" << q->count +1 << "dari" <<MAX << "lagu" <<endl;
		cout << "Judul lagu" ;
		getline (cin, m->judul);
		cout <<"Nama Penyanyi";
		getline (cin, m->penyanyi);
		enqueu(q, *m);
		push(s,*m);
	}
}

void clear (Queue *q,Stact *s,Music *m){
	if (q->count==0 && s-> top == 0){
		cout << "no" <<endl;
		return;
	}else{
		while (s->top){pop(s,*m);}
		
		while (q->count){dequeue(q,*m);}
		cout <<"Data dihapus\n";
	}
}

void print (Queue *q,Stact *s,Music *m){
	if (q->count==0 && s-> top == 0){
		cout << "no" <<endl;
		return;
	}else{
		cout << "data pada queue " << endl;
		for (int i = 0; i < q->count; i++){
			m = &q ->listmusik[i];
			read (m);
		}
		cout << "=========================="<<endl;
		cout << "data pada stuct " << endl;
		for (int i = 0; i < s->top; i++){
			m = &q ->listmusik[i];
		
	}
}
}
int main() {
  int menu;		
do{
	system("cls");
	cout << "Menu" << endl;
	cout << "1. input data music" <<endl;
	cout << "2. ambil data secara FIFO" <<endl;
	cout << "3. ambil data secara LIFO" <<endl;
	cout << "4. hapus data music" <<endl;
	cout << "5. tampilkan data music" <<endl;
	cout << "6. keluar" <<endl;
	cout << "Pilih Menu : ";
	cin >> menu;
	system("cls");
	
	
	cin.ignore();
	switch (menu){
		case 1:
			input (&queue, &stact ,&music );
			break;
		case 2:
			dequeue (&queue, &music);
			read (&music);
			break;	
		case 3:
			pop(&stact , &music);
			read (&music);
			break;		
		case 4:
			clear (&queue, &stact,&music);
			break;		
		case 5:
			print (&queue, &stact,&music);
			break;		
		case 6:
			cout "terima kasih" <<endl;
			break;			
	}
} while (menu !=6);
}















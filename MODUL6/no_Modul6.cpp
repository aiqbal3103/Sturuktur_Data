#include <iostream>
#include <string>
 
using namespace std;
 
// deklarasi struct node
struct Node {
    int id;
    string data;
    Node* next;
};
 
// fungsi untuk membuat node baru
Node* createNode(int id, string data) {
    Node* newNode = new Node;
    newNode->id = id;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
 
// fungsi untuk menambahkan node baru ke linked list
void addNode(Node** head, int id, string data) {
    Node* newNode = createNode(id, data);
    newNode->next = *head;
    *head = newNode;
}
 
// fungsi untuk mencetak linked list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->id << ": " << node->data << endl;
        node = node->next;
    }
}
 
// fungsi untuk mencari node dengan id tertentu
Node* searchNode(Node* head, int id) {
    while (head != NULL) {
        if (head->id == id) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}
 
// fungsi untuk menukar dua node pada linked list
void swapNodes(Node** head, Node* node1, Node* node2, Node* prevNode1, Node* prevNode2) {
    if (prevNode1 != NULL) {
        prevNode1->next = node2;
    } else {
        *head = node2;
    }
    if (prevNode2 != NULL) {
        prevNode2->next = node1;
    } else {
        *head = node1;
    }
    Node* temp = node2->next;
    node2->next = node1->next;
    node1->next = temp;
}
 
// fungsi untuk melakukan sorting pada linked list berdasarkan id
void sortList(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    Node* currNode = *head;
    Node* prevNode = NULL;
    while (currNode != NULL) {
        Node* minNode = currNode;
        Node* minPrevNode = prevNode;
        Node* tempNode = currNode->next;
        while (tempNode != NULL) {
            if (tempNode->id < minNode->id) {
                minNode = tempNode;
                minPrevNode = currNode;
            }
            tempNode = tempNode->next;
        }
        if (currNode != minNode) {
            swapNodes(head, currNode, minNode, prevNode, minPrevNode);
            currNode = minNode;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}
 
int main() {
    Node* head = NULL;
 
    // input data dari pengguna
    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int id;
        string data;
        cout << "Data ke-" << i+1 << endl;
        cout << "Masukkan id: ";
        cin >> id;
        cout << "Masukkan data: ";
        cin >> data;
        addNode(&head, id, data);
    }
    
    int choice;
  	
	  do {
	  	cout << ""<< endl;
	  	cout << "Data Saat Ini : \n";
		printList(head);
		
	    cout << "Pilih algoritma :" << endl;
	    cout << "1. Sorting  " << endl;
	    cout << "2. Searching" << endl;
	    cout << "Pilihan Menu: ";

    cin >> choice;

    switch (choice) {
      case 1:
       cout << "Linked List sebelum di-sort : \n";
   				 printList(head);
   				 sortList(&head);
       cout << "Linked List setelah di-sort : \n";
    			printList(head); 
    	break;
      case 2:
        int searchId;
		    cout << "Masukan id yang ingin dicari: ";
		    cin >> searchId;
		    
		    Node* foundNode = searchNode (head, searchId);
		    if (foundNode == NULL){
		    	cout << "Node dengan id " <<searchId<< " tidak ditemukan" << endl;
			}else {
				cout << "Node dengan id  " <<searchId<< " ditemukan \n " <<foundNode ->data << endl;}
        break;
      
      adefault:
        cout << "Inputan salah" << endl;
        break;
    }
  } while (choice != 0);

  return 0;
}

    
    

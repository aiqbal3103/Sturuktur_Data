#include <iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

node *createNode(int data) {
    node *newNode = new node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int countNodes(node *root) {
    if (root == NULL) {
        return 0;
    } else {
        int count = 1;
        count += countNodes(root->left);
        count += countNodes(root->right);
        return count;
    }
}

int main() {
    node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int count = countNodes(root);
    cout << "Jumlah node keseluruhan pada pohon biner adalah: " << count << endl;
    return 0;
}

// fungsi countNodes yang akan menghitung jumlah node keseluruhan pada pohon biner. 
// Fungsi ini akan menjelajahi seluruh isi pohon biner dan melakukan penghitungan dengan cara rekursif.
// Jika node yang sedang diproses kosong (NULL), maka fungsi akan mengembalikan nilai 0. 
// Jika tidak, maka fungsi akan menghitung node saat ini dan menambahkan jumlah node dari subtree kiri 
// dan subtree kanan dengan cara melakukan pemanggilan rekursif terhadap fungsi countNodes.

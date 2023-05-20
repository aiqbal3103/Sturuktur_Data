#include <iostream>
using namespace std;

struct node {
    int data;
    node *kiri;
    node *kanan;
};


void tambah (node **root, int databaru){
    if ((*root) == NULL){
        node *baru;
        baru = new node;
        baru -> data = databaru;
        baru ->kiri = NULL;
        baru -> kanan = NULL ;
        (*root) = baru;
        (*root) -> kiri = NULL;
        (*root) -> kanan = NULL;
    } else if (databaru < (*root) -> data) tambah (&(*root) -> kiri, databaru);
        else if (databaru > (*root) ->data) tambah (&(*root)->kanan,databaru);
        else if (databaru == (*root)->data) printf ("DATA SUDAH PENUH !!");
}

int findMinValue(node *root) {
    if (root == NULL) {
        return -1;
    } else {
        int minVal = root->data;
        int kiriMin = findMinValue(root->kiri);
        int rightMin = findMinValue(root->kanan);
        if (kiriMin != -1 && kiriMin < minVal) {
            minVal = kiriMin;
        }
        if (rightMin != -1 && rightMin < minVal) {
            minVal = rightMin;
        }
        return minVal;
    }
}

int main() {
    node *pohon;
    pohon = NULL;
    node *root = createNode(4);
    root->kiri = createNode(2);
    root->kanan = createNode(6);
    root->kiri->kiri = createNode(1);
    root->kiri->kanan = createNode(3);
    root->kanan->kiri = createNode(5);
    root->kanan->kanan = createNode(7);

    int minValue = findMinValue(root);
    if (minValue == -1) {
        cout << "Pohon kosong." << endl;
    } else {
        cout << "Nilai node minimum pada pohon biner adalah: " << minValue << endl;
    }

    return 0;
}

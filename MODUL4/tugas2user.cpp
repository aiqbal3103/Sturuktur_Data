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
    node *root = NULL;
    int n, data;
    
    cout << "Masukkan jumlah node: ";
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cout << "Masukkan data node ke-" << i << ": ";
        cin >> data;
        if (root == NULL) {
            root = createNode(data);
        } else {
            node *current = root;
            while (true) {
                if (data < current->data) {
                    if (current->left == NULL) {
                        current->left = createNode(data);
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == NULL) {
                        current->right = createNode(data);
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }
    
    int count = countNodes(root);
    cout << "Jumlah node keseluruhan pada pohon biner adalah: " << count << endl;
    
    return 0;
}

#include <iostream>
using namespace std;

void bubbleSort(char arr[], char n) {
  bool swapped = true;
  int j = 0;
  int temp;
  while (swapped) {
    swapped = false;
    j++;
    for (int i = 0; i < n - j; i++) {
      if (arr[i] > arr[i + 1]) {
        temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        swapped = true;
      }
    }
  }
}

void selectionSort(char arr[], char n) {
  int i, j, min_idx;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx]) min_idx = j;
    int temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }
}

void insertionSort(char arr[], char n) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void shellSort(char arr[], char n) {
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i += 1) {
      int temp = arr[i];
      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
        arr[j] = arr[j - gap];
      arr[j] = temp;
    }
  }
}

void printArray(char arr[], char n) {
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
}

int main() {
//  int n;
//  cout << "Masukkan jumlah data : ";
//  cin >> n;
//  char arr[n];
//  for (int i = 0; i < n; i++) {
//    cout << "Masukkan data ke-" << i + 1 << " : ";
//    cin >> arr[i];
//  }
  
  string kata;
  cout << "Masukkan kata : ";
  getline(cin,kata);
  int n = kata.length();
  char arr[n];
  for (int i = 0; i<n; i++){
  	arr[i] = kata[i];
  } 
	
  int choice;
  	
  do {
  	cout << ""<< endl;
  	cout << "Data Saat Ini : ";
	printArray(arr, n);
    cout << "Pilih algoritma sorting:" << endl;
    cout << "1. Bubble sort" << endl;
    cout << "2. Selection sort" << endl;
    cout << "3. Insertion sort" << endl;
    cout << "4. Shell sort" << endl;
    cout << "Pilihan Menu: ";

    cin >> choice;

    switch (choice) {
      case 1:
        bubbleSort(arr, n);
        cout << "Bubble sort: ";
        printArray(arr, n);
        break;
      case 2:
        selectionSort(arr, n);
        cout << "Selection sort: ";
        printArray(arr, n);
        break;
      case 3:
        insertionSort(arr, n);
        cout << "Insertion sort: ";
        printArray(arr, n);
        break;
      case 4:
        shellSort(arr, n);
        cout << "Shell sort: ";
        printArray(arr, n);
        break;
      default:
        cout << "Inputan salah" << endl;
        break;
    }
  } while (choice != 0);

  return 0;
}

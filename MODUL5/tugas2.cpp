#include <iostream>
#define max 50

using namespace std;
	int arr[max]; // memindahkan variable dari local ke global

int* fibo(int n){ 
    // int arr[max];
    arr[0] =1;
	arr[1] = 1;
	for (int i = 2; i < n; i++){
		arr[i] = arr[i - 1] + arr[i - 2]; //
	}
	return arr;
}

int main(){
	int num, *ptr; //POINTER dari variabel fibo
	cout << "Banyak deret fibonacci: ";
	cin >> num;
	ptr = fibo(num);
	for (int i = 0; i < num; i++){
		//cout<<(ptr+i)<<" ";  
        cout<<*(ptr+i)<<" "; //menambahkan tanda asterik sebelum ptr+1 untuk mengambil nilai bukan alamat
    }
}


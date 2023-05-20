#include <iostream>
#include <cstring>

using namespace std;

void computeLPSArray(string pattern, int M, int lps[]) {
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while(i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) {
                len = lps[len -1];
            } else {
                lps[i] = len;
                i++;
            }
        }
    }
}

void KMP(string txt, string pattern) {
    int M = pattern.length();
    int N = txt.length();
    int lps[M];
    int j = 0;
    computeLPSArray(pattern, M, lps);
    int i = 0;
    while(i < N) {
        if(pattern[j] == txt[i]) {
            j++;
            i++;
        }
        if(j == M) {
            cout << "Pola Ditemukan Pada Index Ke - " << (i - j) << endl;
            j = lps[j - 1];
        } else if(i < N && pattern[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
}

int main() {
    string txt, pattern1, pattern2;
    cout << "=====================================================" << endl;
    cout << "--------- KNUTH MORRIS PRATT STRING MATCHING --------" << endl;
    cout << "=====================================================" << endl;
    cout << "Masukkan Kalimat : ";
    getline(cin, txt);
    cout << "Masukkan Pola Pertama: ";
    cin >> pattern1;
    cout << "Masukkan Pola Kedua: ";
    cin >> pattern2;
    cout << endl << "Hasil Pencarian:" << endl;
    KMP(txt, pattern1);
    KMP(txt, pattern2);
    return 0;
}

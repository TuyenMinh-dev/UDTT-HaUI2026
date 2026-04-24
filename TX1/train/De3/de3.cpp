#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int A[20];
int n = 20;

// --- SINH MANG NGAU NHIÊN ---
void sinhMang() {
    srand(time(NULL));
    cout << "Mang A (20 phan tu): ";
    for (int i = 0; i < n; i++) {
        // Sinh so tu -50 den 50
        A[i] = rand() % 101 - 50; 
        cout << A[i] << " ";
    }
    cout << "\n\n";
}

// --- 1. CHIeN LuoC ÐE QUY (QUAY LUI/DUYET CAP) ---
int demDeQuy(int i, int j) {
    if (i >= n - 1) return 0; // Ða  duyet het mang
    
    if (j >= n) return demDeQuy(i + 1, i + 2); // Chuyen sang so goc tiep theo
    
    int check = (A[i] > A[j]) ? 1 : 0;
    return check + demDeQuy(i, j + 1); // Ðe quy tim tiep cap voi A[i]
}

// --- 2. CHIEN LUOC CHIA ÐE TRI (DUA TRÊN MERGE SORT) ---
long long mergeAndCount(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    long long count = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            // N?u L[i] > R[j], th? t?t c? ph?n t? c?n l?i trong m?ng L 
            // ð?u l?n hõn R[j] (do L ð? s?p x?p)
            arr[k++] = R[j++];
            count += (n1 - i); 
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    return count;
}

long long countInversions(int arr[], int l, int r) {
    long long count = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        count += countInversions(arr, l, m);      // Chia ð? tr? trái
        count += countInversions(arr, m + 1, r);  // Chia ð? tr? ph?i
        count += mergeAndCount(arr, l, m, r);     // Tr?n và ð?m
    }
    return count;
}

int main() {
    sinhMang();

    // Sao chép mang da dùng cho 2 cách (vi Chia de tri se làm thay doi thu tu mang)
    int tempA[20];
    for(int i=0; i<20; i++) tempA[i] = A[i];

    // Cách 1
    cout << "1. So cap nghich dao (De quy): " << demDeQuy(0, 1) << endl;

    // Cách 2
    cout << "2. So cap nghich dao (Chia de tri): " << countInversions(tempA, 0, n - 1) << endl;

    return 0;
}

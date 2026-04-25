#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct TaiSan {
    string ten;
    string tinhTrang;
    long long giaTri;
};

int n;
int phong[20]; // Luu th? t? tài s?n du?c ch?n
TaiSan d[20];
bool used[20] = {false};
int cach = 0;

// Hàm in ra mot cách sap xep
void soCach() {
    cach++;
    cout << "Cach " << cach << ": ";
    for (int i = 0; i < n; i++) {
        // Gi? s? phong[i] luu v? trí c?a tài s?n trong m?ng d
        cout << "[Phong " << i + 1 << ": " << d[phong[i]].ten << "] ";
    }
    cout << endl;
}

// Thu?t toán Chia d? tr? tìm giá tr? l?n nh?t
long long findMax(int left, int right) {
    if (left == right) {
        return d[left].giaTri;
    }
    int mid = (left + right) / 2;
    long long maxL = findMax(left, mid);
    long long maxR = findMax(mid + 1, right);
    
    return max(maxL, maxR); // Tr? v? giá tr? l?n hon gi?a 2 nhánh
}

// Thu?t toán Quay lui li?t kê hoán v? (các cách x?p tài s?n)
void Try(int k) {
    for (int i = 0; i < n; i++) { // Tài s?n ch?y t? 0 d?n n-1
        if (!used[i]) {
            phong[k] = i; // X?p tài s?n i vào v? trí k
            used[i] = true;
            
            if (k == n - 1) {
                soCach();
            } else {
                Try(k + 1);
            }
            
            // Bu?c quan tr?ng: Quay lui
            used[i] = false;
        }
    }
}

int main() {
    n = 6;
    TaiSan mau[6] = {
        {"May tinh", "Moi", 15000000},
        {"Ban lam viec", "Cu", 2000000},
        {"Ghe xoay", "Moi", 1200000},
        {"Dieu hoa", "Moi", 8000000},
        {"May chieu", "Hong", 5000000},
        {"Tu tai lieu", "Cu", 3000000}
    };

    for (int i = 0; i < n; i++) {
        d[i] = mau[i];
    }

    cout << "Danh sach khoi tao ban dau la: " << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << d[i].ten << " | " << d[i].tinhTrang << " | " << d[i].giaTri << " VND" << endl;
    }
    cout << "-----------------------------------" << endl;

    // 1. Chia d? tr?
    long long giaMax = findMax(0, n - 1);
    cout << "Gia tri tai san lon nhat: " << giaMax << " VND" << endl;
    cout << "-----------------------------------" << endl;

    // 2. Quay lui li?t kê (Luu ý: n=6 s? có 6! = 720 cách in ra)
    cout << "Cac cach sap xep tai san vao phong:" << endl;
    Try(0);
    cout << "Tong so cach xep la: " << cach << endl;

    return 0;
}

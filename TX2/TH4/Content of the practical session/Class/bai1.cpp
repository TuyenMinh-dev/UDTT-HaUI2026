#include<bits/stdc++.h>
using namespace std;

void giamDan(int a[],int n){
	sort(a, a + n, greater<int>());
}

bool coin_changing(int *a, int n, long m, int *c) {
    // Khởi  tạo mảng kết quả
    for (int i = 0; i < n; ++i)
        c[i] = 0;
    int i = 0;
    while (m > 0 && i < n) {
        c[i] = m / a[i];
        m = m % a[i];
        ++i;
    }
    if (m > 0)
        return false;
    return true;
}
void xuatKetQua(int a[], int c[], int n) {
    cout << "\nCach doi tien:\n";
    for (int i = 0; i < n; i++) {
        if (c[i] > 0) {
           cout << a[i] <<" xu "
                 << " : Lay "
                 << c[i]
                 << " dong\n";
        }
    }
}

int main(){
	int a[]={1,2,5,10,20};  
    int n=5;
    long m=86;
	int c[100];
    giamDan(a, n);
    bool ok = coin_changing(a, n, m, c);
    if (ok)
        xuatKetQua(a, c, n);
    else
        cout << "Khong doi duoc!\n";
    return 0;
	
}
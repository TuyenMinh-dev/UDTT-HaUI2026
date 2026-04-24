#include<bits/stdc++.h>
using namespace std;

int n, a[20], ok;

void khoiTao(){
    for(int i = 1; i <= n; i++){
        a[i] = i;
    }
}

void sinh(){
    int i = n - 1;
    // Buoc 1: Tìm vi trí i dau tiên tu phai sang trái sao cho a[i] < a[i+1]
    while(i >= 1 && a[i] > a[i+1]){
        --i;
    }

    if(i == 0){ 
        ok = 0;
    }
    else{
        // Buoc 2: Tìm phan tu a[j] nho nhat o bên phai i sao cho a[j] > a[i]
        int j = n;
        while(a[i] > a[j]) --j;
        
        // Buoc 3: Ðoi cho cho 2 phan tu
        swap(a[i], a[j]);
        
        // Buoc 4: Lat nguoc doan tu i+1 den n
        reverse(a + i + 1, a + n + 1);
    }
}

int main(){
    if (!(cin >> n)) return 0;
    ok = 1;
    khoiTao();
    while(ok){
        for(int i = 1; i <= n; i++){
            cout << a[i];
        }
        cout << endl;
        sinh();
    }
    return 0;
}

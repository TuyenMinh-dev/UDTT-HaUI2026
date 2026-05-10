#include<bits/stdc++.h>
using namespace std;
void tang_dan(int a[],int n){
	sort(a, a + n);
}
bool A2(int *a, int n, long q, int *c) {
   
    for (int i = 0; i < n; ++i)
        c[i] = 0;
    int i = 0;
    while (q > 0 && i < n) {
        c[i] = q / a[i];
        q = q % a[i];
        ++i;
    }
    if (q > 0)
        return false;
    return true;
}
void xuatKetQua(int a[], int c[], int n, long q) {
    cout << "So luong chai nuoc toi da voi binh chua "<<q<<" lit nuoc: \n";
    for (int i = 0; i < n; i++) {
        if (c[i] > 0) {
           cout<<"Lay "<<c[i]<<" chai "<<" co dung tich la "<<a[i]<<" lit";
        }
    }
}
int main(){
	int a[]={5,2,1,3};
	int n=4;
	long q=9;
	tang_dan(a,n);
	int c[100];
	bool ok = A2(a, n, q, c);
    if (ok)
        xuatKetQua(a, c, n,q);
    else
        cout << "Khong doi duoc!\n";
    return 0;
	
}
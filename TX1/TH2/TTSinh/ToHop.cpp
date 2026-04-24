#include<bits/stdc++.h>
using namespace std;
//cac buoc : 1.khoi tao cau hinh dau tien 
//           2.while(khi chua phai cau hinh cuoi cung ){
//           3.    <In ra cau hinh tiep theo >
//           4.    <Sinh ra cau hinh tiep theo>   
//}                 
// bai toan sinh to hop chap k cua n  (cac tap con gom n phan tu cua tap gom k phan tu) 
int n,k,a[100],ok ;
void khoiTao(){//khoi tao cau hinh dau tien 
	for(int i=1;i<=k;i++){
		a[i]=i ;
	} 
} 
void sinh(){
	int i=k ;//bat dau duyet tu bit thu k ve
	//gia tri max cua cac bit tai vi tri thu i la n-k+i  
	while(i>=1 && a[i] == n-k+i ) {
		--i; 
	}
	if(i==0 ) {
		ok=0; // bao hieu cau hinh cuoi cung 
	}
	else{
		a[i]++; 
		for(int j=i+1;j<=k;j++) {
			a[j]=a[j-1]+1; 
		}
	} 
} 
int main(){
	cin>>n>>k; 
	ok=1; 
	khoiTao(); 
	while (ok){
		for(int i=1;i<=k;i++){
			cout<<a[i]; 
		} 
		cout<<endl; 
		sinh(); 
	} 
	return 0; 
} 

#include<bits/stdc++.h>
using namespace std;
//bai toan liet ke cac tap con gom k phan tu cua mot tap gom n phan tu
//yc: phan tu sau phai lon hon phan tu truoc
string sv[6]={"Trang","Cong","Trung","Binh","Hoan","Mai"};
int n,k;
int a[100];
void nhapS(){
	for(int i=0;i<=n;i++){
		a[i]=i+1;
	}
}
int main(){
	cin>>n>>k;
	nhapS();
	for(int i=1;i<n;i++){
		cout<<a[i];
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string sv[6]={"Trang","Cong","Trung","Binh","Hoan","Mai"};
int n,k;
int a[10];
int cach=0;
int x[4];

void soCach(){
	cach++;
	cout<<"Cach "<<cach<<": ";
	for(int i=0;i<n;i++){
		cout<<sv[x[i]];
	}
}

void Try(int m){
	for(int i=0;i<n;i++){
	   
	    	x[m]=i;
	    
	    	if(m== k-1){
	    		soCach();
			}
			else{
				Try(k+1);
			}
		}
	
			}
	


//void nhapMang(){
//	for(int i=0;i<n;i++){
//		a[i]=i+1;
//	}
//}
int main(){
//	cin>>n>>k;
	//nhapMang();	
	Try(0);
	cout<<"Tong so cach lay ra "<<k<<" sinh vien tu "<<n<<" sinh vien la: "<<cach;

	return 0;
}

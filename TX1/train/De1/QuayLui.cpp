#include<bits/stdc++.h>
using namespace std;
int x[4];
int cach=0;
string a[4]={"Tung","Cuc","Truc","Mai"};
string b[3]={"Da Nang","Phu Quoc"," Ha Long"};
int n=4;// so gia tri cua tap ket qua
int m=3;// so gia tri cua tap gan vao ket qua 

void soCach(){
	cach++;
	cout<<"Cach "<<cach<<": ";
	for(int i=0;i<n;i++){
		cout<<" "<<a[i]<<"-"<<b[x[i]]<<"   ";
	}cout<<endl;
} 
void Try(int k,int n){
	for(int i=0;i<m;i++){		
			x[k]=i ;
			if(k== n-1){
				soCach(); 
			} 
			else{
				Try(k+1,n);
			}
					 
	} 
} 
int main(){	
	Try(0,4);
	cout<<"Tong so cach la: "<<cach;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std; 
int n;
int x[10];
char a[2]={'a','b'};
void nhiPhan(){
	for(int i=0;i<n;i++){
		cout<<x[i];
	}cout<<endl;
}
void chuoi(){
	for(int i=0;i<n;i++){
		cout<<a[x[i]];
	}cout<<endl;
}
void Try(int k){
	for(int i=0;i<=1;i++){
		x[k]=i;
		if(k== n-1){
			nhiPhan();
			chuoi();
		}
		else{
			Try(k+1);
		}
	}
}
int main(){
	cin>>n;
	Try(0);
	return 0;
}

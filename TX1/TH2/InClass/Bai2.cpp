#include<bits/stdc++.h>
using namespace std;
string N[6]={"Trang","Cong","Trung","Binh","Hoan","Mai"};
int S[6]={1,2,3,4,5,6};
int x[6];
int cach=0;
bool used[6]={false};
int n=6;
void soCach(){
	cach++;
	cout<<"Cach "<<cach<<": ";
	for(int i=0;i<n;i++){
		cout<<S[i]<<N[x[i]]<<"   ";
	}cout<<endl;
}
void Try(int k){
	for(int i=0;i<n;i++){
		if(!used[i]){
			x[k]=i;
			used[i]=true;
			if(k== n-1){
				soCach();
			}
			else{
				Try(k+1);
			}
			used[i]=false;
		}
	}
}
int main(){
	Try(0);
	return 0;
}

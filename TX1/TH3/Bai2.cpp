#include<bits/stdc++.h>
using namespace std;
char S[7]={'A','B','C','D','E','F','G'};
int cach=0;
int n=7;// tong phan tu cua tap ung vien
int k_lay=6;
int x[6];
bool used[7]={false};
void soCach(){
	cach++;
	cout<<"Cach "<<cach<<": ";
	for(int i=0;i<6;i++){
		cout<<S[x[i]];
	}cout<<endl;
}
void Try(int k, int n){//duyet tap ung vien
	for(int i=0;i<n;i++){
		if(!used[i]){
			x[k]=i;
			used[i]=true;
			if(k==(k_lay-1)){
				soCach();
			}
			else{
				Try(k+1,n);
			}
			used[i]=false;
		}
	}
}
int main(){
	Try(0,6);
	return 0;
}


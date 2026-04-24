#include<bits/stdc++.h>
using namespace std;
	char G[4]={'A','B','C','D'};
	string N[4] ={"Trung","Cuc","Truc","Mai"};
	bool used[4]={false}; 
	int cach=0; 
	int n=4;
	int x[4];
void soCach(){
	cach++;
	cout<<"Cach "<<cach<<": ";
	for(int i=0;i<n;i++){
		cout<<G[i]<<"-"<<N[x[i]]<<" " ;//goi nguoi o vi tri hop le do 
	} 
	cout<<endl; 
	 
} 
void Try(int k, int n){
	for(int i=0;i<n;i++){	
	if(!used[i]){
		x[k]=i;// danh dau vi tri cua nguoi hop le thu k 
		used[i]=true; 
		if(k== (n-1)){
			soCach(); 
		} 
		else{
			Try(k+1,n) ;
		} 
		used[i]=false; 		
	} 	
} 
}
int main(){
	Try(0,4); 
	cout<<"Tong so cach xep la: "<<cach<<endl;
	return 0; 
} 

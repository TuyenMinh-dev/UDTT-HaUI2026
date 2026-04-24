#include<bits/stdc++.h>
using namespace std;
string a[4]={"Tung","Cuc","Truc","Mai"};
string b[3]={"Da Nang","Phu Quoc","Ha Long"};
int cach=0; 
int x[4]={0,0,0,0};//cau hinh dau tien 
int n=4;
int m=3; 
bool con_sinh=true; 
void soCach(){
	cach++;
	cout<<" "<<"Cach"<<cach<<": "; 
	for(int i=0;i<n;i++){
		cout<<a[i]<<"-"<<b[x[i]]<<"   "; 
	} cout<<endl; 
} 
void sinh(){
	int i=n-1;//duyet tu phan tu cuoi cung  
	while(i>=0 && x[i]== m-1){// duyet den bao gio dat duoc gia tri max cua moi vi tri  
		x[i]=0;               // reset so ve 0  
		i--;                  // va lui sang ben trai  
	} 
	if(i==-1){
		con_sinh=false;// cau hinh cuoi cung 
	} 
	else{
		x[i]++; 
	} 
} 
int main(){
	while(con_sinh){
		soCach();// goi ham nay truoc de in cau hinh dau tien ra truoc  
		sinh(); 
	} 
	cout<<"Tong so cach la: "<<cach;
	return 0; 
}

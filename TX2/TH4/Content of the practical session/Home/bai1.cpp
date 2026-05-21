#include<bits/stdc++.h>
using namespace std;
vector<int> greedy(int &n,int &m,int T[]){
	sort(T,T+n,greater<int>());
	int x=0; 
	vector<int> d;//danh sach xe duoc chon 
	int tong_tai =0; 
	cout<<"So xe tai toi thieu de chuyen het "<<m<<" tan la: ";
	for(int i=0;i<n;i++){
		if(tong_tai<m){
			tong_tai +=T[i];
			d.push_back(T[i]); 
			x++ ; 
		} 
		else{
			break; 
		} 
	} 
	if(tong_tai<m){
		cout<<"Khong du xe de van chuyen het hang trong kho"<<endl; 
	} 
	cout<<x<<endl; 
	return d; 
} 
int main(){
	int n=8;
	int m=25;
	int T[]={3,5,4,4,6,7,1,2};
	vector<int> danh_sach = greedy(n,m,T);
	cout<<"Danh sach cac xe duoc chon la: ";
	
	
	for (int i = 0; i < danh_sach.size(); i++) {
    cout << danh_sach[i] << " ";
	}
	return 0; 
	 
} 

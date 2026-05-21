#include<bits/stdc++.h>
using namespace std;
void qhd(int &a,int &n,int m[],int k[]){
	int dp[n+1][a+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a;j++){
			dp[i][j]=dp[i-1][j];
			if(j>=k[i]){
				dp[i][j]=max(dp[i][j],dp[i-1][j-k[i]]+m[i]); 
			} 
		} 
	}
	//truy vet 
	int i=n;
	int j=a;
	int u=0;
	vector<int> v;
	 while(i>0 &&j>0){
	 	if(dp[i][j]!=dp[i-1][j]){
	 		u++;
			v.push_back(k[i]) ;
			j-=k[i]; 
		 } 
		 i--; 
	 } 
	 cout<<"So kien hang duoc xep len xe la: "<<u<<endl;
	 cout<<"Danh sach cac kien hang do la: ";
	 for(int i=0;i<v.size();i++){
	 	cout<<v[i]<<" "; 
	 } 
	
} 
int main(){
	int a=12;
	int n=5;
	int m[]={0,3,5,2,6,4};
	int k[]={0,2,3,2,5,6}; 
	qhd(a,n,m,k);
	return 0; 
	 
} 

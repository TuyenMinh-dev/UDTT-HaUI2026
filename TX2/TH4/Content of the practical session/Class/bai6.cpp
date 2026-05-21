#include<bits/stdc++.h>
using namespace std;
void knapsack(int *V,int *W,int &n,int &m){
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=W[i]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-W[i]]+V[i]);
            }
        }
    }
    int i=n,j=m;
    int u=0;
    vector<int> d;
    //truy vết
    while(i>0 && j>0){
    if(dp[i][j]!=dp[i-1][j]){
        u++;
        j=j-W[i];
        d.push_back(i);
    }
    i--;
}
    reverse(d.begin(),d.end());
    cout<<"So goi hang can xep la: "<<u<<endl;
    cout<<"Danh sach cac goi hang do la:";
    for(int x : d){
      cout<<x<<" ";
    }cout<<endl;
    cout<<"Tong gia tri lon nhat dat duoc la: "<<dp[n][m]<<endl;
}
int main(){
    int n;
    n=5;
    int W[]={0,2,4,3,7,1};
    int V[]={0,5,6,4,5,3};
    int m=12;
    knapsack(V,W,n,m);
    return 0;

}
#include<bits/stdc++.h>
using namespace std;
void knapsack(int *w,int *v,int &n,int &S){
     for(int i=1;i<=n;i++)cin>>w[i];    
     for(int i=1;i<=n;i++)cin>>v[i];
        
     int dp[n+1][S+1];
     memset(dp,0,sizeof(dp));//mọi ô giá trị ban đầu được gán bằng 0
     for(int i=1;i<=n;i++){
        for(int j=1;j<=S;j++){
            //1.không lựa chọn đồ vật thứ i vào trong túi
            dp[i][j]=dp[i-1][j];//ban đầu tự động gán với giá trị của vật thứ (i-1) trước đó
            //2.có thể đưa đồ vật vào trong túi
            if(j>=w[i]){
                dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]]+v[i]); 
            }
        }
     }   
     for(int i=1;i<=n;i++){
        for(int j=1;j<=S;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
     }
     cout<<dp[n][S]<<endl;
}
int main(){
    int n; cin>>n;
    int S; cin>>S;
    int w[n+1],v[n+1];
    knapsack(w,v,n,S);
    return 0;


}
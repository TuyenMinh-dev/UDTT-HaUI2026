#include<bits/stdc++.h>
// dãy con có tổng bằng S 
// tư tưởng: dp[j] là true khi có dãy con có tổng băng j
//dp[j] tồn tại khi dp[j-a[i]] đã tồn tại (xét từ cuối dãy ngược về)
using namespace std;
void subset(int &n,int &S,int *v){
      for(int i=1;i<=n;i++) cin>>v[i];
      vector<bool> dp(S+1,false); //ban đầu chưa có dãy con
      dp[0]=true;// tập có tổng bằng 0 luôn có dãy con
      for(int i=1;i<=n;i++){
        for(int j=S;j>=v[i];j--){// buộc phải duyệt ngược để đảm bảo các phân tử được sử dụng đúng 1 lần 
            if(dp[j-v[i]]== true){
                 dp[j]=true;
            }
        }
      }
      if(dp[S]) cout<<1<<endl;
      else cout<<0<<endl;
}
int main(){
    int n;cin>>n;
    int S;cin>>S;
    int v[n+1];
    subset(n,S,v);
    return 0;
}
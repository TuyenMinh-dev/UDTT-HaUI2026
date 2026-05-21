#include<bits/stdc++.h>
using namespace std;
struct Hang{
    string ten;
    int ton;
    int gia;
};
void qhd(vector<Hang> B,int &n,int &k){
     int dp[n+1][k+1];
     memset(dp,0,sizeof(dp));
     for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=B[i-1].ton){
                dp[i][j]=max(dp[i][j],dp[i-1][j-B[i-1].ton]+B[i-1].gia);
            }
        }
     }
     
     //truy vết
     int i=n;
     int j=k;
     int x=0;
     while(i>0 && j>0){
        if(dp[i][j]!=dp[i-1][j]){
            x++;
            j-=B[i-1].ton;
        }
        i--;
     }
     cout<<"Ket qua QHD: "<<x<<endl;
     cout<<"Max value= "<<dp[n][k]<<endl;
}
bool compare(Hang a,Hang b){
    double x=(double)a.gia/a.ton;
    double y=(double)b.gia/b.ton;
    return x>y;// to hơn đứng trước
}
void Tham_Lam(vector<Hang> B,int &n,int &k){
   sort(B.begin(),B.end(),compare);
   int x=0;
   int kich_thuoc=0;
   int max_value=0;
   for(int i=0;i<n;i++){
        if(kich_thuoc+B[i].ton<=k){
            kich_thuoc+=B[i].ton;
            max_value+=B[i].gia;
            x++;
        }
   }
   cout<<"Ket qua Tham Lam: "<<x<<endl;
   cout<<"Max value= "<<max_value<<endl;
}

int main(){
   int n=7;
   vector<Hang> B ={
       {"AAA",3,6},
       {"BBB",3,5},
       {"CCC",5,5},
       {"ABC",2,7},
       {"ACB",3,8},
       {"ABB",4,9},
       {"ACC",6,6}
   };
   int k=9;//sức chứa của kho
   qhd(B,n,k);
   Tham_Lam(B,n,k);
   return 0;
}
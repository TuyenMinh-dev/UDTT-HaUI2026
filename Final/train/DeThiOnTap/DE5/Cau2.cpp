#include<bits/stdc++.h>
using namespace std;
struct ChuyenXe
{
    string nhaXe;
    int soKhach;
    long long tienVe;
};
struct KQA{
    int u;
    long long p;
};
KQA A(vector<ChuyenXe> d,int m){
    KQA kqA;
    kqA.u=0;
    int tien=0;
    for(int i=0;i<d.size();i++){
        tien+=d[i].tienVe;
        kqA.u++;
        if(tien>=m){
            break;
        }
    }
    kqA.p=tien;
    return kqA; 
}
void inA(KQA kqA,int m){
    if(kqA.u>0 && kqA.p>=m){
        cout<<" u = "<<kqA.u<<endl;
        cout<<" p = "<<kqA.p<<endl;
    }else{
        cout<<"Khong co phuong an"<<endl;
    }
}
struct KQB{
    int q;
    long long t;
};
KQB B(vector<ChuyenXe> d,int n,int k){
    vector<vector<long long>> dp(n+1,vector<long long>(k+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=d[i-1].soKhach){
                dp[i][j]=max(dp[i][j],dp[i-1][j-d[i-1].soKhach]+d[i-1].tienVe);
            }
        }
    }
    KQB kqB;
    kqB.t=dp[n][k];
    kqB.q=0;
    int i=n;
    int j=k;
    while(i>0 && j>0){
        if(dp[i][j]!=dp[i-1][j]){
            kqB.q++;
            j-=d[i-1].soKhach;
        }
        i--;
    }
    return kqB;
}
void inB(KQB kqB){
    if(kqB.q>0){
        cout<<"q = "<<kqB.q<<endl;
        cout<<"t = "<<kqB.t<<endl;
    }else{
        cout<<"Khong co phuong an"<<endl;
    }
}
int main(){
    int n=8; 
    vector<ChuyenXe> d{
        {"A",30,8000},
        {"B",25,7000},
        {"C",25,6500},
        {"D",20,6000},
        {"E",30,5500},
        {"G",35,5000},
        {"H",35,4500},
        {"F",30,4000}    
    };
    long long m=30000;
    KQA kqA = A(d,m);
    inA(kqA,m);
    int k=100;
    KQB kqB = B(d,n,k);
    inB(kqB);
    return 0;
}
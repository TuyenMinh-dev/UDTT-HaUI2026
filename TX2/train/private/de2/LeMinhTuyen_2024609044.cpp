#include<bits/stdc++.h>
using namespace std;
struct MT{
    string ten;
    int gb;
    int gia;
};
struct KQG{
    int u;
    int m;
};
struct KQD{
    int x;
    vector<MT> a;
};
KQG G(int p,int n,vector<MT> d){
    KQG kq;
    kq.u=0;
    kq.m=0;
    bool tim_thay=false;
    for(int i=0;i<n;i++){
        kq.u++;
        kq.m+=d[i].gia;
        if(kq.m>=p){
            tim_thay=true;
            break;
            
        }
    }
    // trong trường hợp chạy hết vòng lặp vẫn m<p 
    if(!tim_thay){
    kq.u=0;
    kq.m=0;
    }
    return kq;
}

KQD D(int y,int n,vector<MT> d){
    int dp[n+1][y+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=y;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=d[i-1].gb){
                dp[i][j]=max(dp[i][j],dp[i-1][j-d[i-1].gb]+d[i-1].gia);
            }
        }
    }
    int i=n;int j=y;
    KQD kq;  
    while(i>0 && j>0){
        if(dp[i][j]!=dp[i-1][j]){
            j-=d[i-1].gb;
            kq.a.push_back(d[i-1]);
        }
        i--;
    } 
    reverse(kq.a.begin(),kq.a.end());
    kq.x=dp[n][y];
    return kq;   
}
void inDS(vector<MT> a){
    for(int i=0;i<a.size();i++){
        cout<<i+1<<". Hang: "<<a[i].ten
            <<" | Dung luong: "<<a[i].gb<<" GB"
            <<" | Gia ban: "<<a[i].gia<<" trieu dong\n";
    }
}
void inKQ(KQG kqG,KQD kqD){
    if(kqG.u>0){
        cout<<"u = "<<kqG.u<<" may"<<endl;
        cout<<"m = "<<kqG.m<<" trieu dong"<<endl;
    }
    else{
        cout<<"Khong co phuong an"<<endl;
    }
    cout<<"-------------------------------------------------"<<endl;
    if(kqD.x>0){
        cout<<"x = "<<kqD.x<<endl;
        cout<<"a: "<<endl;
        inDS(kqD.a);
    }
    else{
        cout<<"Khong co phuong an"<<endl;
    }
}
int main(){  
    vector<MT> d= {
        {"A",2048,38},
        {"B",1024,25},
        {"C",512,14},
        {"D",500,12},
        {"E",256,7},
        {"G",128,5}
    };
    int y=3000;
    int p=80;
    int n=d.size();
    KQG kqG = G(p,n,d);
    KQD kqD = D(y,n,d);
    inKQ(kqG,kqD);
    return 0;
}
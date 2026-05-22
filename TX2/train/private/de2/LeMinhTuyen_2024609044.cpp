#include<bits/stdc++.h>
using namespace std;
struct MT{
    string ten;
    int gb;
    int gia;
};
void G(int &p,int &n,vector<MT> d){
    int slg=0;
    int tien=0;
    bool tim_thay=false;
    for(int i=0;i<n;i++){
        slg++;
        tien+=d[i].gia;
        tim_thay=true;
        if(tien>=p){
            break;
        }
    }
    if(tim_thay){
        cout<<"u = "<<slg<<endl;
        cout<<"m = "<<tien<<endl;
    }
    else{
        cout<<"Khong co phuong an"<<endl;
    }
}
void D(int &y,int &n,vector<MT> d){
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
    vector<string> a;
    while(i>0){
        if(dp[i][j]!=dp[i-1][j]){
            j-=d[i-1].gb;
            a.push_back(d[i-1].ten);
        }
        i--;
    }
    int x=dp[n][y];
    if(x>0){
        cout<<"x = "<<x<<endl;
        for(string y : a){
            cout<<y<<" ";
        }cout<<endl;
    }
    else{
        cout<<"Khong co phuong an!"<<endl;
    }
}
int main(){
    int y=3000;
    int p=80;
    int n=6;
    vector<MT> d= {
        {"A",2048,38},
        {"B",1024,25},
        {"C",512,14},
        {"D",500,12},
        {"E",256,7},
        {"G",128,5}
    };
    G(p,n,d);
    cout<<"------------------------"<<endl;
    D(y,n,d);
    return 0;
}
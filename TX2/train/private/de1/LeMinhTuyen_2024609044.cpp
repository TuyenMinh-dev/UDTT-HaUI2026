#include<bits/stdc++.h>
using namespace std;
struct Tu{
    string ten;
    int kg;
    int lit;
};
void A(int &k,int &n,vector<Tu> d){
    int slg=0;
    int klg=0;
    vector<string> t;
    for(int i=0;i<n;i++){
        if(klg+d[i].kg<=k){
            slg++;
            klg+=d[i].kg;
            t.push_back(d[i].ten);
        }
    }
    if(slg!=0){
        cout<<"v= "<<slg<<endl;
        cout<<"DANH SACH t gom: "<<endl;
        for(string s : t){
            cout<<s<<" ";
        }cout<<endl;
    }
    else{
        cout<<"Khong co phuong an"<<endl;
    }
}
void B(int &w,int &n,vector<Tu> d){
    int dp[n+1][w+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            dp[i][j]=dp[i-1][j];
            if(j >= d[i-1].lit){
                dp[i][j]=max(dp[i][j],dp[i-1][j-d[i-1].lit]+d[i-1].kg);
            }
        }
    }
    int slg=0;
    int i=n;int j=w;
    vector<string> a;
    while(i>0 ){
        if(dp[i][j]!=dp[i-1][j]){
            slg++;
            j-=d[i-1].lit;
            a.push_back(d[i-1].ten);
        }
        i--;
    }
    if(slg>0){
        cout<<"p= "<<slg<<endl;
        cout<<"q= "<<dp[n][w]<<endl;
        for(string x : a){
            cout<<x<<" ";
        }cout<<endl;
    }
    else{
        cout<<"Khong co phuong an"<<endl;
    }
}
int main(){
    int k=18;
    int w=25;
    int n=6;
    vector<Tu> d = {
        {"A",2,3},
        {"B",3,3},
        {"C",3,4},
        {"D",5,6},
        {"E",7,7},
        {"G",9,8}
    };
    A(k,n,d);
    cout<<"---------------------------"<<endl;
    B(w,n,d);
    return 0;
}

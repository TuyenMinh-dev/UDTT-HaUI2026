#include<bits/stdc++.h>
using namespace std;
struct GiaoVien{
    string hoTen;
    int dayHoc;
    long long luong;
};
struct KQG{
    int u;
    long long v;
};
KQG G(vector<GiaoVien>d,long long m){
    KQG kqG;
    kqG.u=0;
    long long tien=0;
    for(int i=0;i<d.size();i++){
        if(tien+d[i].luong<=m){
            kqG.u++;
            tien+=d[i].luong;
        }
    }
    kqG.v=tien;
    return kqG;
}
void inG(KQG kqG){
    if(kqG.u>0){
        cout<<"u = "<<kqG.u<<endl;
        cout<<"v = "<<kqG.v<<" trieu dong "<<endl;
    }else{
        cout<<"Khong co phuong an"<<endl;
    }
}
struct KQD{
    vector<GiaoVien> q;
    int t;
};
KQD D(vector<GiaoVien> d,long long m,int n){
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=d[i-1].luong){
                dp[i][j]=max(dp[i][j],dp[i-1][j-d[i-1].luong]+d[i-1].dayHoc);
            }
        }
    }
    KQD kqD;
    kqD.t=dp[n][m];
    int i=n;int j=m;
   while(i>0 && j>0){
    if(dp[i][j]!=dp[i-1][j]){
        kqD.q.push_back(d[i-1]);
        j-=d[i-1].luong;
    }
    i--;
   } return kqD;
}
void inTT(vector<GiaoVien> d){
    cout<<left<<setw(5)<<"STT"
              <<setw(20)<<"Ten"
              <<setw(10)<<"Dang day"
              <<"Luong"<<endl;
              
    for(int i=0;i<d.size();i++){
        cout<<left<<setw(5)<<i+1
              <<setw(20)<<d[i].hoTen
              <<setw(10)<<d[i].dayHoc
              <<d[i].luong<<" trieu dong"<<endl;
    }          
}
void inD(KQD kqD){
    if(kqD.t>0){
        cout<<" Danh sach q: "<<endl;
        inTT(kqD.q);
        cout<<" t = "<<kqD.t<<endl;
    }else{
        cout<<"Khong co phuong an"<<endl;
    }
}
int main(){
    int n=8;
    vector<GiaoVien> d{
        {"Nguyen Van A",10,50000},
        {"Nguyen Van B",5,45000},
        {"Nguyen Van C",15,45000},
        {"Nguyen Van D",20,40000},
        {"Nguyen Van E",15,35000},
        {"Nguyen Van F",25,30000},
        {"Nguyen Van G",20,20000},
        {"Nguyen Van H",15,15000}
    };
    long long m=150000;
    KQG kqG = G(d,m);
    inG(kqG);
    cout<<"-----------------------------------------"<<endl;
    KQD kqD = D(d,m,n);
    inD(kqD);
    return 0;
}
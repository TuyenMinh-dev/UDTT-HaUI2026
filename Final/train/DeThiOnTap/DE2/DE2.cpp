#include<bits/stdc++.h>
using namespace std;
struct Sach{
    string ten;
    int soTrang;
    string theLoai;
    long long gia;
};
int A1(vector<Sach> d,int p,int i,int &slg){
    if(i==d.size()){
        return slg;
    }else{
        if(d[i].soTrang > p){
            slg++;
            return A1(d,p,i+1,slg);
        }
        else{
             return A1(d,p,i+1,slg);
        }
    }
}
void inA1(int x,int p){
    if(x>0){
        cout<<"So luong sach co so trang lon hon "<<p<<" trang la: "<<x<<endl;
    }else{
        cout<<"Khong tim thay sach nao lon hon "<<p<<" trang" <<endl;
    }
}
void inTT(vector<Sach> d){
    cout<<left<<setw(5)<<"STT"
              <<setw(5)<<"Ten"
              <<setw(8)<<"Trang"
              <<setw(10)<<"The loai"
              <<"Gia"<<endl;
    for(int i=0;i<d.size();i++){
        cout<<left<<setw(5)<<i+1
                  <<setw(5)<<d[i].ten
                  <<setw(8)<<d[i].soTrang
                  <<setw(10)<<d[i].theLoai
                  <<d[i].gia<<" nghin dong"<<endl;
    }
}
Sach A2(vector<Sach> d,int left,int right){
    if(left==right){
        return d[left];
    }
    else
    {
        int mid=(left+right)/2;
        Sach MLeft=A2(d,left,mid);
        Sach MRight=A2(d,mid+1,right);
        return (MLeft.gia >= MRight.gia) ? MLeft : MRight;
    }
}
void inA2(Sach y,vector<Sach> d){
    vector<Sach> a;
    a.push_back(y);
    cout<<"Thong tin cua cuon sach co gia bia cao nhat la: "<<endl;
    inTT(a);
}
struct KQB{
    int u;
    vector<Sach> t;
};
struct KQC{
    int v;
    int w;
};
KQB B(vector<Sach> d,int k){
    KQB kqB;
    kqB.u=0;   
    int trang=0; 
    for(int i=0;i<d.size();i++){
        if(trang + d[i].soTrang<=k){
            trang+=d[i].soTrang;
            kqB.u++;
            kqB.t.push_back(d[i]);
        }
    }return kqB;
}
void inB(KQB kqB){
    if(kqB.u>0){
        cout<<" u = "<<kqB.u<<endl;
        cout<<" t: "<<endl;
        inTT(kqB.t);
    }
    else{
        cout<<"Khong co phuong an"<<endl;
    }
}
KQC C(vector<Sach> d,int n,int m){
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=d[i-1].gia){
                dp[i][j]=max(dp[i][j],dp[i-1][j-d[i-1].gia]+d[i-1].soTrang);
            }
        }
    }
    int i=n;
    int j=m;
    KQC kqC;
    kqC.w=dp[n][m];
    kqC.v=0;
    while(i>0 && j>0){
        if(dp[i][j]!=dp[i-1][j]){
            kqC.v++;
            j-=d[i-1].gia;
           
        }
        i--;
    }
    return kqC;
}
void inC(KQC kqC){
    if(kqC.v>0){
        cout<<"v: "<<kqC.v<<endl;
        cout<<"w: "<<kqC.w<<endl;
    }else{
        cout<<"Khong co phuong an"<<endl;
    }
}
int main(){
    int n=7;
    vector<Sach> d{
        {"A",50,"Hoat hinh",30},
        {"B",60,"Hai",25},
        {"C",70,"Kich",30},
        {"D",80,"Tho",70},
        {"E",90,"Van ",50},
        {"F",100,"Toan",90},
        {"G",150,"Tieng Anh",100}
    };
    int p=95;
    int slg=0;
    int x=A1(d,p,0,slg);
    inA1(x,p);
    cout<<"----------------------------------"<<endl;
    Sach y=A2(d,0,d.size()-1);
    inA2(y,d);
     cout<<"----------------------------------"<<endl;
    int k=300;
    KQB kqB = B(d,k);
    inB(kqB);
    cout<<"----------------------------------"<<endl;
    long long m=100;
    KQC kqC = C(d,n,m);
    inC(kqC);
    return 0;
}
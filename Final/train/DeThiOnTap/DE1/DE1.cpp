#include<bits/stdc++.h>
using namespace std;
struct KQA{
    double tong;
    int soLuong;
};
KQA A(double &tong,double a[],int i,int k,int dem,int b){
    if(i == b){
        KQA kqA;
        kqA.tong=tong;
        kqA.soLuong=dem;
        return kqA;
    }else{
        if(a[i]<k){
            tong+=a[i];
            dem++;
            return A(tong,a,i+1,k,dem,b);
        }else{
            return A(tong,a,i+1,k,dem,b);
        }
    }
}
void inKQA(KQA kqA,int k){
    if(kqA.soLuong==0){
        cout<<"Khong co so nao nho hon so "<<k<<endl;
    }else{
        double TBC = (double)kqA.tong/kqA.soLuong;
        cout<<"Trung binh cong cua cac so nho hon "<<k<<" la: "<<TBC<<endl;
    }
}
struct PM{
    int soHieu;
    int soLuong;
    string quanLy;
    long long gia;
};
struct KQG{
    int u;
    vector<PM> p;
};
struct KQD{
    int q;
    int t;
};
void inDS(vector<PM> d){
    cout<<left<<setw(5)<<"STT"
              <<setw(5)<<"ID"
              <<setw(10)<<"SLMT"
              <<setw(20)<<"QL"
              <<"Gia"<<endl;
    for(int i=0;i<d.size();i++){
        cout<<left<<setw(5)<<i+1
                  <<setw(5)<<d[i].soHieu
                  <<setw(10)<<d[i].soLuong
                  <<setw(20)<<d[i].quanLy
                  <<d[i].gia<<endl;
    }  
}
KQG G(vector<PM> d,long long m){
    KQG kqG;
    kqG.u=0;
    long long tien=0;
    
    for(int i=0;i<d.size();i++){
        //xét theo giá trị của từng phòng = 1 máy * số lượng 
        //trước đây là xét theo gái trị của từng máy
        long long tongTien=d[i].gia*d[i].soLuong;
        if(tien+tongTien<=m){
            kqG.u++;
            tien+=tongTien;
            kqG.p.push_back(d[i]);
        }
    }
    return kqG;
}
void inkqG(KQG kqG){
    if(kqG.u>0){
        cout<<"u = "<<kqG.u<<endl;
        bool find=false;
        vector<PM> NVHQLy;
        for(auto& a : kqG.p){
            if(a.quanLy=="Nguyen Van Hoang"){
                NVHQLy.push_back(a);
            }
        }
        if(!NVHQLy.empty()){
            cout<<"Cac phong may do NVH quan ly la: "<<endl;
            inDS(NVHQLy);
        }
        else{
            cout<<"Khong co phong nao do NVH quan ly"<<endl;
        }
        
    }
    else{
        cout<<"Khong co phuong an"<<endl;
    }
}
KQD D(int n,long long m,vector<PM> d){
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        long long tongTien = d[i-1].soLuong * d[i-1].gia;
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=tongTien){
                dp[i][j]=max(dp[i][j],dp[i-1][j-tongTien]+d[i-1].soLuong);
            }
        }
    }
    
    int i=n;
    int j=m;
    KQD kqD;
    kqD.t=dp[n][m];
    kqD.q=0;
    while(i>0 && j>0){
        long long tongTien = d[i-1].soLuong * d[i-1].gia;
        if(dp[i][j]!=dp[i-1][j]){
            kqD.q++;
            j-=tongTien;
        }
        i--;
    }
    return kqD;
    
}
void inkqD(KQD kqD){
    if(kqD.t>0){
        cout<<"q = "<<kqD.q<<endl;
        cout<<"t = "<<kqD.t<<endl;
    }else{
        cout<<"Khong co phuong an"<<endl;
    }
}
int main(){
    double a[]={2,3,1,6,8,9,12,19,28,10,12,15};
    int b=12;
    int k=15;
    double tong=0;
    int dem=0;
    KQA kqA = A(tong,a,0,k,dem,b);
    inKQA(kqA,k);
    int n=6;
    long long m=500;
    vector<PM> d{
        {01,5,"Nguyen Van Hoang",30},
        {02,5,"Nguyen Van Hai",35},
        {03,8,"Nguyen Van A",40},
        {04,9,"Nguyen Van B",45},
        {05,12,"Nguyen Van C",50},
        {06,15,"Nguyen Van D",60}
    };
    KQD kqD = D(n,m,d);
    KQG kqG = G(d,m);
    inkqG(kqG);
    cout<<"---------------------------------------"<<endl;
    inkqD(kqD);
    return 0;
}
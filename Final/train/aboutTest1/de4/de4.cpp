#include<bits/stdc++.h>
using namespace std;
struct MayIn{
    string tenHang;
    string loaiMay;
    long long gia;
    int phamTram;
};
void inTT(vector<MayIn> d){
    cout<<left<<setw(5)<<"STT"
              <<setw(10)<<"Ten"
              <<setw(10)<<"Loai"
              <<setw(10)<<"Gia"
              <<"Giam gia"<<endl;
    for(int i=0;i<d.size();i++){
        cout<<left<<setw(5)<<i+1
              <<setw(10)<<d[i].tenHang
              <<setw(10)<<d[i].loaiMay
              <<setw(10)<<d[i].gia
              <<d[i].phamTram<<endl;
    }          
}
void A1(vector<MayIn> d,int i){
    if(i==0){
        cout<<left<<setw(5)<<"STT"
              <<setw(10)<<"Ten"
              <<setw(10)<<"Loai"
              <<setw(10)<<"Gia"
              <<"Giam gia"<<endl;
    }
    if(i==d.size()){
        return;
    }else{
        cout<<left<<setw(5)<<i+1
              <<setw(10)<<d[i].tenHang
              <<setw(10)<<d[i].loaiMay
              <<setw(10)<<d[i].gia
              <<d[i].phamTram<<endl;
               A1(d,i+1);
    }
}
int A2(vector<MayIn> d,int left,int right){
    if(left==right){
        // tra ve chi so
        return (d[left].loaiMay=="mau" && d[left].phamTram==0)? left:-1;
    }else{
        int mid=(left+right)/2;
        int findL=A2(d,left,mid);  
        int findR=A2(d,mid+1,right);
        if(findL!=-1) return findL;
        return findR;  
    }
}
void inA2(int vt,vector<MayIn> d){
    if(vt!=-1){
        inTT(vector<MayIn>{d[vt]});
    }else{
        cout<<"Khong tim thay may in thoa man nhu tren"<<endl;
    }
}
void soCach(int &cach,vector<MayIn> d,int res[],int n){
    cach++;
    cout<<"Phuong an "<<cach<<" : "<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<" - "<<d[res[i]].tenHang<<endl;
    }cout<<endl;
}
void A3(int k,vector<MayIn> d,int &cach,int res[],int n,bool used[]){
    for(int i=0;i<n;i++){
        if(!used[i]){
            res[k]=i;
            used[i]=true;
            if(k==n-1){
                soCach(cach,d,res,n);
            }else{
                A3(k+1,d,cach,res,n,used);
            }
            used[i]=false;
        }
    }
}
int main(){
    int n=7;
    vector<MayIn> d{
        {"A","mau",300,0},
        {"B","trang",500,10},
        {"C","den",200,20},
        {"D","xanh",400,0},
        {"E","do",200,40},
        {"F","tim",300,50},
        {"G","vang",500,45},
    };
    A1(d,0);
    int cach=0;
    int res[n];
    bool used[n];
    used[n]={false};
    A3(0,d,cach,res,n,used);
    int vt=A2(d,0,d.size()-1);
    inA2(vt,d);
    return 0;
    
}
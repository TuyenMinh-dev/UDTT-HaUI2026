#include<bits/stdc++.h>
using namespace std;
struct MT{
    string tenHang;
    double manHinh;
    long long gia;
};
long long A1(vector<MT> d, int i,int &tong){
    if(i==d.size()){
        return tong;
    }
    else{
        tong+=d[i].gia;
        return A1(d,i+1,tong);
    }
}
int A2(vector<MT> d,int left,int right){
    if(left==right){
        return (d[left].manHinh >= 15.6)? 1:0;
    }
    else{
        int mid=(left+right)/2;
        int countLeft=A2(d,left,mid);
        int countRight=A2(d,mid+1,right);
        return countLeft+countRight;
    }
}
void soCach(int &cach,int n,vector<int> viTri,vector<MT> d){
    cach++;
    cout<<"Phuong an "<<cach<<" : "<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<" - "<<d[viTri[i]].tenHang<<endl;
    }cout<<endl;

}
void A3(int k,int n,vector<MT> d,vector<bool> used,vector<int> viTri,int &cach){
    for(int i=0;i<n;i++){
        if(!used[i]){
            used[i]=true;
            viTri[k]=i;
            if(k==n-1){
                soCach(cach,n,viTri,d);
            }
            else{
                A3(k+1,n,d,used,viTri,cach);
            }
            used[i]=false;
        }
    }
}
int main(){
    int n=6;
    vector<MT> d{
        {"Lenovo",15.6,21000000},
        {"Dell",13.4,12000000},
        {"HP",15,10000000},
        {"Asus",10,8000000},
        {"Sony",12,19000000},
        {"LG",15.5,2000000}
    };
    int tong=0;
    cout<<"Gia ban cua cac may tinh la: "<<A1(d,0,tong)<<endl;
    cout<<"So luong may co man hinh >= 15.6 inch la: "<<A2(d,0,d.size()-1)<<endl;
    int cach=0;
    vector<bool> used(n,false);
    vector<int> viTri(n);
    A3(0,n,d,used,viTri,cach);
    return 0;
}
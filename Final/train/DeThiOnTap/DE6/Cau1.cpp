#include<bits/stdc++.h>
using namespace std;
int A(int a[],int left,int right,int k){
    if(left==right){
        return (a[left]%k ==0)? 1:0;
    }
    else{
        int mid=(left+right)/2;
        int countLeft=A(a,left,mid,k);
        int countRight=A(a,mid+1,right,k);
        return countLeft+countRight;
    }
}
void testK1(int x){
    if(x>0){
        cout<<"So luong cac so trong a chia het cho k1 la: "<<x<<endl;
    }else{
        cout<<"Khong co so nao chia het cho k1 trong mang"<<endl;
    }
}
void testK2(int y,int n){
    int res=n-y;
    if(res>0){
        cout<<"So luong cac so trong a khong chia het cho k2 la: "<<res<<endl;
    }else{
        cout<<"Khong co so nao khong chia het cho k2 trong mang"<<endl;
    }
}
int main(){
    int n=12;
    int a[]={1,2,5,4,3,6,7,8,9,10,12,11};
    int k1=2;
    int k2=3;
    int x=A(a,0,n-1,k1);
    int y=A(a,0,n-1,k2);
    testK1(x);
    testK2(y,n);
    return 0;
}
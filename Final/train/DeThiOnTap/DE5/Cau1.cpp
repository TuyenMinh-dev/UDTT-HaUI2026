#include<bits/stdc++.h>
using namespace std;
int chiaDeTri(double a[],double k,int left,int right){
    if(left==right){
        if(a[left]==k) return left;
        else return -1;
    }else{
        int mid=(left+right)/2;
        int inL=chiaDeTri(a,k,left,mid);
        int inR=chiaDeTri(a,k,mid+1,right);
        if(inL!=-1){
            return inL;
        }if(inR!=-1){
            return inR;
        }
        return -1;
    }
}
void inC1(int vitri,int k){
    if(vitri!=-1){
        cout<<"Tim thay "<<k<<" tai vi tri thu "<<vitri<<" trong mang a"<<endl;
    }
    else{
        cout<<"Khong tim thay "<<k<<" trong mang"<<endl;
    }
}
int main(){
    int n=13;
    double a[]={2,4,3,5,6,12,10,9,7,1,8,11,15};
    double k=10;
    int vitri=chiaDeTri(a,k,0,n-1);
    inC1(vitri,k);
    
}    
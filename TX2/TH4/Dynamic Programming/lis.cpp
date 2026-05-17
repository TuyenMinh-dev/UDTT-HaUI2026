#include<bits/stdc++.h>
using namespace std;
//L[i] là độ dài của dãy con tăng dài nhất kết thúc ở chỉ số i
//L[i] = max (L[i],L[j]+1) với j thuộc [0,i-1] và ai > aj

void lis(int a[],vector<int> &L,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<= i-1;j++){
            if(a[i]>a[j]){
                L[i]= max(L[i],L[j]+1);
            }
        }
    }
    cout<<"Do dai cua day con tang dai nhat la: ";
    cout<<*max_element(L.begin(),L.end())<<endl;// cú pháp tìm ra phần tử lớn nhất trong dãy  
 
}
int main(){
   int a[]={128, 104, 53, 876, 660, 961, 754, 775, 290, 231, 224, 915, 392, 994};
   int n=14;
   vector<int> L(n,1);// trường hợp cơ sở: tất cả các phần tử trong mảng ban đầu đều có L[i] max = 1
   lis(a,L,n);
   return 0;
   

}
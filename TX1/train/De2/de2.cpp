#include<bits/stdc++.h>
using namespace std;

int A[15]; 
int n=15;
int dem1;
int dem2;

void sinhMang(){
	cout<<" Chuoi ngau nhien 15 so nguyen: ";
	for(int i=0;i<n;i++){
		A[i] =rand() % 151;
		cout<< A[i]<<" " ;
	} 
	cout<<"\n\n"; 
} 
void Try(int k, int start , int sum){

	for(int i=start ;i<n;i++){
		if(k==1){
			if(sum +A[i]>100){
				dem1++;
			} 
		} 
		else{
			Try(k+1,i+1,A[i]);
		}
	} 
} 
int chiaDeTri(){	
    dem2=0;
    sort(A,A+15);
    int left=0;
    int right=n-1;
    while(left < right){
	
    if(A[left]+A[right]>100){
    	dem2+=(right-left);
    	right--;
	}
	else{
		left++;
	}
	
}
    return dem2;
}
int main(){
	sinhMang();	
	dem1=0;
	//bat dau chon so thu 1(k=0) , duyet tu vi tri 0 , tong ban dau la 0
	Try(0,0,0);
	cout<<"So cap co tong >100 (theo quay lui) : "<<dem1<<endl;
	cout<<"So cap co tong >100 (theo chia de tri): "<<chiaDeTri();
	return 0;
}

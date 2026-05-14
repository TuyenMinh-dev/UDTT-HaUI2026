#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
int main(){
	priority_queue<int, vector<int>, greater<int> > Q ;//min_heap
	int n; cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		Q.push(x); 
	} 
	int ans=0;
	while(Q.size()>1){// lap den chung nao con chua noi xong day  
		//chon 2 soi day co chieu dai nho nhat
		 int x=Q.top(); //soi day ngan nhat 
		 Q.pop();//xoa no khoi quece 
		 int y=Q.top(); //soi day ngan nhat tiep theo 
		 Q.pop(); 
		 ans+= x+y; 
		 Q.push(x+y); 
	} 
	cout<<ans<<endl; 
	return 0; 
} 

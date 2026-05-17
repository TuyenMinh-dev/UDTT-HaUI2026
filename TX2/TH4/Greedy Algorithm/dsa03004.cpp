#include<bits/stdc++.h>
using namespace std;
//tư tưởng : để tách ra 2 số sao cho tổng bé nhất thì sẽ chọn ra 2 số nhỏ nhất ở mỗi lần tách
void solve(){
    int n;
    cout<<"Nhap do dai mang A: ";
    cin>>n;
    int A[n]; 
    priority_queue<int,vector<int>, greater<int>> Q;//min heep
    
    for(int i=0;i<n;i++){
        cin>>A[i];
        Q.push(A[i]);
    }
    long long num1 = 0;
    long long num2 = 0;
    
    while(Q.size() > 0){
        int min1 = Q.top(); Q.pop();
        num1 = num1 * 10 + min1; //  cách dịch số
        
        // Phải kiểm tra xem còn phần tử nào cho min2 không (phòng th N lẻ)
        if (!Q.empty()) {
            int min2 = Q.top(); Q.pop();
            num2 = num2 * 10 + min2; //  cách dịch số
        }
    }
    long long ans = num1 + num2; // Đưa ra ngoài vòng lặp
    cout << ans << endl;

}
int main(){
    
    int n;
    cout<<"Nhap so luong bo test: ";
    cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
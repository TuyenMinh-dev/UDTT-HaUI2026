#include<bits/stdc++.h>
using namespace std;
void solve(){
    int k;
    cout<<"Nhap k: ";
    cin>>k;
    string s;
    cout<<"Nhap chuoi: ";
    cin>>s;
     //dem so lan xuat hien
    map<char,int> freq;
     for(char c:s){
        freq[c]++;
     }
     priority_queue<int> q;
     for (auto it : freq) {
        q.push(it.second);//first la ki tu , second la so lan xuat hiencua moi ki ty
    }
    // Bước 3: Thực hiện loại bỏ k ký tự
    while (k > 0 && !q.empty()) {
        //chon tan so cua ki tu co so lan xuat hien nhieu nhat
        int top = q.top();
        q.pop();
        if (top > 0) {// kiểm tra số đầu , phòng th k> số kí tự của dãy 
            top--;
            k--;
        }
        q.push(top);
    }

    // Bước 4: Tính tổng bình phương kết quả
    long long ans = 0;
    while (!q.empty()) {
        long long val = q.top();
        q.pop();
        ans += val * val;
    }
    cout << ans << endl;
    //luôn bỏ đi 1 đơn vị cho một kí tự có lần xuất hiện nhiều nhất ở mỗi lần lặp

}

int main(){
 
    int n;
    cout<<"Nhap so luong bo test T: ";
    if (!(cin >> n)) return 0;
    while (n--) {
        solve();
    }
    return 0;

}

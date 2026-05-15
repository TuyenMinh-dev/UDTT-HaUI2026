#include <iostream>
#include <vector>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

int main() {
    // 1. Thêm 2 dòng này để đồng bộ luồng nhập xuất (quan trọng)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> Q;
    int n; 
    if (!(cin >> n)) return 0;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Q.push(x);
    }

    long long ans = 0; // 2. Phải là long long để không bị sai kết quả
    while(Q.size() > 1) {
        int x = Q.top(); Q.pop();
        int y = Q.top(); Q.pop();
        ans += (long long)x + y;
        Q.push(x + y);
    }

    cout << ans << endl;
    return 0;
}

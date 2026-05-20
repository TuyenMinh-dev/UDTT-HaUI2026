#include <bits/stdc++.h>
using namespace std;
void knapsack(int *X, int *Y, int &n, int &k)
{
    int INF = 1e9;
    int dp[n + 1][k + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0; // điều kiện cơ sở
    for (int i = 1; i <= n; i++)
    { // i là tượng trưng cho dãy các đồ vật
        for (int j = 0; j <= k; j++)
        {                            // j là tượng trưng cho dãy các kích thước , max là kích thước của túi
            dp[i][j] = dp[i - 1][j]; // tự động gán với phần tử ở hàng trên trước
            if (j >= Y[i])
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - Y[i]] + X[i]);
            }
        }
    }
    // tuy nhiên do đây la bìa toán tìm min nên kết quả tối ưu nhất chưa chắc nằm ở ô cuối
    int p = INF;
    int pos_min = 0; // lưu lại vị trí cột mang kết quả min
    for (int j = 1; j <= k; j++)
    {
        if (dp[n][j] < p)
        { // duyệt từ hàng n về để đánh dấu vị trí truy vết
            p = dp[n][j];
            pos_min = j; // đây là vị trí mà tại đó có giá trị min
        }
    }
    if (p == INF)
    {
        cout << "Khong co phuong an hop le" << endl;
        return;
    }
    else
    {
        cout << "p= " << p << endl;
    }

    // truy vết
    vector<int> d;
    int i = n;
    int j = pos_min;
    cout << "Cac goi hang duoc chon la: ";
    while (i > 0 && j >= 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        { // nếu ô hiện tại mà khác ô hàng trên , nghĩa là đã chọn gói hàng thứ i
            d.push_back(i);

            j = j - Y[i];
        }
        i--;
    }
    reverse(d.begin(), d.end());
    cout << "d= ";
    for (int x : d)
    {
        cout << x << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int X[n + 1];
    int Y[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> X[i];
    for (int i = 1; i <= n; i++)
        cin >> Y[i];
    knapsack(X, Y, n, k);
    return 0;
}

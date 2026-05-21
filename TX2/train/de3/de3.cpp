#include <bits/stdc++.h>
using namespace std;
struct Hang
{
    int id;
    int w;
    int v;
};
bool compare(Hang a, Hang b)
{
    return a.v > b.v;
}
void qhd(int &n, int &M, vector<Hang> &d)
{
    int dp[n + 1][M + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= d[i - 1].w)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - d[i - 1].w] + d[i - 1].v);
            }
        }
    }
    cout << "Quy hoach dong: " << endl;
    cout << "GTLN: " << dp[n][M] << endl;
    int i = n;
    int j = M;
    vector<int> a;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            a.push_back(d[i - 1].id);
            j -= d[i - 1].w;
        }
        i--;
    }
    reverse(a.begin(), a.end());
    for (int x : a)
    {
        cout << x << " ";
    }
    cout << endl;
}
void greedy(int &n, int &M, vector<Hang> d)
{
    sort(d.begin(), d.end(), compare);
    vector<int> dsach;
    int tongGiaTri = 0;
    int suc_Chua = M;
    for (int i = 0; i < n; i++)
    {
        if (suc_Chua >= d[i].w)
        {
            tongGiaTri += d[i].v;
            suc_Chua -= d[i].w;
            dsach.push_back(d[i].id);
        }
    }
    sort(dsach.begin(), dsach.end());
    cout << "Tham lam: ";
    cout << "GTLN= " << tongGiaTri << endl;
    for (int x : dsach)
    {
        cout << x << " ";
    }
    cout << endl;
}
int main()
{
    int n = 6;
    int M = 12;
    vector<Hang> d = {
        {1, 3, 10},
        {2, 4, 15},
        {3, 2, 7},
        {4, 1, 4},
        {5, 5, 11},
        {6, 6, 14}};
    qhd(n, M, d);
    greedy(n, M, d);
    return 0;
}
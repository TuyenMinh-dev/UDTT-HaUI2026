#include <bits/stdc++.h>
using namespace std;
struct Tu
{
    string ten;
    int kg;
    int lit;
};
struct KetQuaA
{
    int v;
    vector<Tu> t;
};
struct KetQuaB
{
    int p;
    int q;
    vector<Tu> ds;
};
KetQuaA A(int k, int n, vector<Tu> d)
{
    KetQuaA kq;
    kq.v = 0; // giá trị sẽ trả về sau cùng
    int klg = 0;
    for (int i = 0; i < n; i++)
    {
        if (klg + d[i].kg <= k)
        {
            kq.v++;
            klg += d[i].kg;
            kq.t.push_back(d[i]);
        }
        else
        {
            break;
        }
    }
    return kq; // trả về struct chứa v và t
}
KetQuaB B(int w, int n, vector<Tu> d)
{
    int dp[n + 1][w + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= d[i - 1].lit)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - d[i - 1].lit] + d[i - 1].kg);
            }
        }
    }
    int i = n;
    int j = w;
    KetQuaB kq;
    kq.q = dp[n][w];
    kq.p = 0;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            kq.p++;
            j -= d[i - 1].lit;
            kq.ds.push_back(d[i - 1]);
        }
        i--;
    }
    reverse(kq.ds.begin(), kq.ds.end());
    return kq;
}
void inDS(vector<Tu> ds)
{
    for (int i = 0; i < ds.size(); i++)
    {
        cout << " " << i + 1 << ". Ten: " << ds[i].ten
             << " | Khoi luong: " << ds[i].kg << " kg"
             << " | Dung tich: " << ds[i].lit << " lit\n";
    }
}
void inKQ(KetQuaA &kqA, KetQuaB &kqB)
{
    if (kqA.v > 0)
    {
        cout << "v = " << kqA.v << endl;
        cout << "t: " << endl;
        inDS(kqA.t);
    }
    else
    {
        cout << "Khong co ket qua" << endl;
    }
    cout << "-------------------------------------------------------" << endl;
    if (kqB.p > 0 && kqB.q > 0)
    {
        cout << "p = " << kqB.p << endl;
        cout << "q = " << kqB.q << endl;
        inDS(kqB.ds);
    }
    else
    {
        cout << "Khong co phuong an" << endl;
    }
}
int main()
{
    vector<Tu> d = {
        {"A", 2, 3},
        {"B", 3, 3},
        {"C", 3, 4},
        {"D", 5, 6},
        {"E", 7, 7},
        {"G", 9, 8}};
    int k = 18;
    int w = 25;
    int n = d.size();
    KetQuaA kqA = A(k, n, d);
    KetQuaB kqB = B(w, n, d);
    inKQ(kqA, kqB);
    return 0;
}

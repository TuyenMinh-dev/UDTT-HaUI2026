#include <bits/stdc++.h>
using namespace std;
struct MonAn
{
    string tenMon;
    string tenNhaHang;
    int khoiLuong;
    long long gia;
};
void inTT(vector<MonAn> d)
{
    cout << left << setw(5) << "STT"
         << setw(15) << "Ten mon"
         << setw(15) << "Nha hang"
         << setw(15) << "Khoi luong"
         << "Gia tien" << endl;
    for (int i = 0; i < d.size(); i++)
    {
        cout << left << setw(5) << i + 1
             << setw(15) << d[i].tenMon
             << setw(15) << d[i].tenNhaHang
             << setw(15) << d[i].khoiLuong
             << d[i].gia << " nghin dong" << endl;
    }
}
void A1(vector<MonAn> d, int i)
{
    if (i == 0)
    {
        cout << left << setw(5) << "STT"
             << setw(15) << "Ten mon"
             << setw(15) << "Nha hang"
             << setw(15) << "Khoi luong"
             << "Gia tien" << endl;
    }
    if (i == d.size())
    {
        return;
    }
    else
    {
        cout << left << setw(5) << i + 1
             << setw(15) << d[i].tenMon
             << setw(15) << d[i].tenNhaHang
             << setw(15) << d[i].khoiLuong
             << d[i].gia << " nghin dong" << endl;
        A1(d, i + 1);
    }
}
int A2(vector<MonAn> d, int g, int left, int right)
{
    if (left == right)
    {
        return (d[left].gia <= g);
    }
    else
    {
        int mid = (left + right) / 2;
        int countLeft = A2(d, g, left, mid);
        int countRight = A2(d, g, mid + 1, right);
        return countLeft + countRight;
    }
}
void inA2(int x, int k)
{
    if (x > 0)
    {
        cout << "So mon an co gia <= " << k << " nghin dong la: " << x << endl;
    }
    else
    {
        cout << "Khong co mon nao co gia <= " << k << " nghin dong " << endl;
    }
}
struct KQB
{
    int u;
    vector<MonAn> t;
};
KQB B(vector<MonAn> d, int m)
{
    KQB kqB;
    kqB.u = 0;
    int tien = 0;
    for (int i = 0; i < d.size(); i++)
    {
        if (tien + d[i].gia <= m)
        {
            kqB.u++;
            tien += d[i].gia;
            kqB.t.push_back(d[i]);
        }
    }
    return kqB;
}
void inB(KQB kqB)
{
    if (kqB.u > 0)
    {
        cout << "u = " << kqB.u << endl;
        bool find = false;
        vector<MonAn> pho;
        for (auto &a : kqB.t)
        {
            if (a.tenNhaHang == "Pho 24")
            {
                pho.push_back(a);
                find = true;
            }
        }
        if (!find)
        {
            cout << "Khong co mon an nao thuoc nha hang Pho 24 trong danh sach" << endl;
        }
        else
        {
            cout << "TT mon an thuoc nha hang Pho 24 la: " << endl;
            inTT(pho);
        }
    }
    else
    {
        cout << "Khong co phuong an" << endl;
    }
}
struct KQC
{
    int v;
    int w;
};
KQC C(vector<MonAn> d, int m, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= d[i - 1].gia)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - d[i - 1].gia] + d[i - 1].khoiLuong);
            }
        }
    }
    int i = n;
    int j = m;
    KQC kqC;
    kqC.v = 0;
    kqC.w = dp[n][m];
    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            kqC.v++;
            j -= d[i - 1].gia;
        }
        i--;
    }
    return kqC;
}
void inC(KQC kqC)
{
    if (kqC.w > 0)
    {
        cout << "v = " << kqC.v << endl;
        cout << "w = " << kqC.w << " gram " << endl;
    }
    else
    {
        cout << "Khong co phuong an" << endl;
    }
};
int main()
{
    int n = 7;
    vector<MonAn> d{
        {"Com ga", "A", 300, 20},
        {"Com trung", "B", 500, 25},
        {"Com rang", "Pho 24", 250, 30},
        {"Bun bo", "D", 300, 35},
        {"Com tam", "E", 700, 45},
        {"Nem chua ran", "G", 500, 50},
        {"Thit rang", "H", 300, 60}};
    A1(d, 0);
    int g = 45;
    int x = A2(d, g, 0, d.size() - 1);
    inA2(x, g);
    cout << "------------------------------------------" << endl;
    int m = 150;
    KQB kqB = B(d, m);
    inB(kqB);
    cout << "------------------------------------------" << endl;
    KQC kqC = C(d, m, n);
    inC(kqC);
    return 0;
}
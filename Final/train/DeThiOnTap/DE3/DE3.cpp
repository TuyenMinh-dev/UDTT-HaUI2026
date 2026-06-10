#include <bits/stdc++.h>
using namespace std;
struct ChuyenBay
{
    string ten;
    string diemDen;
    int TGBay;
    long long gia;
};
struct KQA1
{
    long long giaVe;
    int soLg;
};
KQA1 A1(vector<ChuyenBay> d, int n, int t, int i, int &solg, long long &gia)
{
    if (i == d.size())
    {
        KQA1 kqA1;
        kqA1.giaVe = gia;
        kqA1.soLg = solg;
        return kqA1;
    }
    else
    {
        if (d[i].TGBay < t)
        {
            solg++;
            gia += d[i].gia;
            return A1(d, n, t, i + 1, solg, gia);
        }
        else
        {
            return A1(d, n, t, i + 1, solg, gia);
        }
    }
}
void inA1(KQA1 kqA1)
{
    if (kqA1.soLg > 0)
    {
        cout << "TBC gia ve cua cac chuyen bay la: " << endl;
        cout << (double)kqA1.giaVe / kqA1.soLg << " nghin dong " << endl;
    }
    else
    {
        cout << "Khong co phuonog an thoa man" << endl;
    }
}
void socach(int &cach, vector<ChuyenBay> d, int res[], int chon)
{
    cach++;
    cout << "Cach " << cach << " : " << endl;
    for (int i = 0; i < chon; i++)
    {
        cout << i + 1 << " . " << d[res[i]].ten << " " << endl;
    }
    cout << endl;
}
void A2(int k, int start, int n, int res[], vector<ChuyenBay> d, int &cach, int chon)
{
    for (int i = start; i < n; i++)
    {
        res[k] = i;
        if (k == chon - 1)
        {
            socach(cach, d, res, chon);
        }
        else
        {
            A2(k + 1, i + 1, n, res, d, cach, chon);
        }
    }
}
void inTT(vector<ChuyenBay> d)
{
    cout << left << setw(5) << "STT"
         << setw(20) << "Ten"
         << setw(15) << "Diem den"
         << setw(10) << "TGBay"
         << "Gia" << endl;
    for (int i = 0; i < d.size(); i++)
    {
        cout << left << setw(5) << i + 1
             << setw(20) << d[i].ten
             << setw(15) << d[i].diemDen
             << setw(10) << d[i].TGBay
             << d[i].gia << endl;
    }
}
struct KQB
{
    int u;
    vector<ChuyenBay> p;
};
KQB B(vector<ChuyenBay> d, int n, int k)
{
    KQB kqB;
    kqB.u = 0;
    int tg = 0;
    for (int i = 0; i < d.size(); i++)
    {
        if (tg + d[i].TGBay <= k)
        {
            kqB.u++;
            tg += d[i].TGBay;
            kqB.p.push_back(d[i]);
        }
    }
    return kqB;
}
void inB(KQB kqB)
{
    if (kqB.u > 0)
    {
        cout << "u = " << kqB.u << endl;
        vector<ChuyenBay> air;
        bool find = false;
        for (auto &a : kqB.p)
        {
            if (a.ten == "Vietnam Airlines")
            {
                air.push_back(a);
                find = true;
            }
        }
        if (!find)
        {
            cout << "khong co chuyen bay nao thuoc hang VietNam Airlines trong danh sach duoc chon" << endl;
        }
        else
        {
            cout << "TT ve chuyen bay hang Vietnam Airlines" << endl;
            inTT(air);
            cout << "------------------------------------" << endl;
        }
    }
    else
    {
        cout << "khong co phuong an" << endl;
    }
}
struct KQC
{
    int q;
    int r;
};
KQC C(vector<ChuyenBay> d, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= d[i - 1].gia)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - d[i - 1].gia] + d[i - 1].TGBay);
            }
        }
    }
    int i = n;
    int j = m;
    KQC kqC;
    kqC.r = dp[n][m];
    kqC.q = 0;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            kqC.q++;
            j -= d[i - 1].gia;
        }
        i--;
    }
    return kqC;
}
void inC(KQC kqC)
{
    if (kqC.q > 0)
    {
        cout << "q = " << kqC.q << endl;
        cout << "r = " << kqC.r << endl;
    }
    else
    {
        cout << "Khong co phuong an" << endl;
    }
}
int main()
{
    int n = 7;
    vector<ChuyenBay> d{
        {"Vietnam Airlines", "TP Ho Chi Minh", 60, 10000},
        {"Rong Vang", "Da Nang", 65, 15000},
        {"Sao Vang", "Ha Noi", 75, 18000},
        {"VIETNAM", "Phu Quoc", 80, 12000},
        {"Que huong", "Nha Trang", 90, 18000},
        {"To Quoc", "TP Ho Chi Minh", 95, 14000},
        {"Dat Nuoc", "Can Tho", 100, 18000}};
    int t = 85;
    long long gia = 0;
    int solg = 0;
    KQA1 kqA1 = A1(d, n, t, 0, solg, gia);
    inA1(kqA1);
    int chon = 3;
    int start = 0;
    int res[chon];
    int cach = 0;
    A2(0, 0, n, res, d, cach, chon);
    cout << "Co tat ca la " << cach << " cach chon" << endl;
    cout << "---------------------------------------" << endl;
    int k = 250;
    KQB kqB = B(d, n, k);
    inB(kqB);
    int m = 80000;
    KQC kqC = C(d, n, m);
    inC(kqC);
    return 0;
}
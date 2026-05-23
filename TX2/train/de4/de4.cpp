#include <bits/stdc++.h>
using namespace std;
struct Tham
{
    string ten;
    int dienTich;
    int giaTri;
    string mau;
};
struct KQA
{
    int soTham;
    vector<Tham> ds;
};
struct KQB
{
    vector<Tham> ds;
};
void inDS(vector<Tham> ds)
{
    for (int i = 0; i < ds.size(); i++)
    {
        cout << i + 1 << " . Ten hang: " << ds[i].ten
             << " | Dien tich: " << ds[i].dienTich << " met vuong"
             << " | Gia tri: " << ds[i].giaTri << " trieu VND"
             << " | Mau: " << ds[i].mau << endl;
    }
}
KQA A(int m, int n, vector<Tham> d)
{
    KQA kq;
    kq.soTham = 0;
    for (int i = 0; i < n; i++)
    {
        if (m >=d[i].giaTri)
        {
            kq.soTham++;
            m -= d[i].giaTri;
            kq.ds.push_back(d[i]);
            if( m==0){
                break;
            }
        }
    }
    if(m>0){
        kq.soTham=0;
        kq.ds.clear();
    }
    return kq;
}
KQB B(int s, int n, vector<Tham> d)
{
    int dp[n + 1][s + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= d[i - 1].dienTich)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - d[i - 1].dienTich] + d[i - 1].giaTri);
            }
        }
    }
    int i = n;
    int j = s;
    KQB kq;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            kq.ds.push_back(d[i - 1]);
            j -= d[i - 1].dienTich;
        }
        i--;
    }
    reverse(kq.ds.begin(),kq.ds.end());
    return kq;
}
void inKQA(KQA kqA)
{
    if (kqA.soTham > 0)
    {
        cout << "Dap an thuat toan A :" << endl;
        cout << "Co the mua duoc nhieu nhat " << kqA.soTham << endl;
        cout << "Danh sach cac tham duoc mua : " << endl;
        inDS(kqA.ds);
        int S = 0;
        for (int i = 0; i < kqA.ds.size(); i++)
        {
            S += kqA.ds[i].dienTich;
        }
        cout << "Tong dien tich cac tam tham mua duoc: " << S <<" met vuong " <<endl;
    }
    else
    {
        cout << "Khong tim duoc phuong an" << endl;
    }
}
void inKQB(KQB kqB)
{
    if (kqB.ds.size() > 0)
    {
        cout << "Dap an thuat toan B: " << endl;
        cout << "So luong tam tham can mua: " << kqB.ds.size()<<endl;
        cout << "Thong tin ve cac tam tham: " << endl;
        inDS(kqB.ds);
        int xanh=0;
        for (int i = 0; i < kqB.ds.size(); i++)
        {
            if (kqB.ds[i].mau == "xanh")
            {
                xanh++;
            }
        }
        cout << "So luong tam tham mau xanh la: " << xanh << endl;
    }
    else
    {
        cout << "Khong tim duoc phuong an" << endl;
    }
}

int main()
{
    vector<Tham> d = {
        {"A", 1, 1, "xanh"},
        {"B", 2, 2, "cam"},
        {"C", 4, 3, "nau"},
        {"E", 5, 4, "xanh"},
        {"G", 7, 6, "do"},
        {"H", 9, 9, "hong"}};
    int m = 16;
    int n = d.size();
    int s = 21;
    KQA kqA = A(m, n, d);
    KQB kqB = B(s, n, d);
    inKQA(kqA);
    cout<<"----------------------------------------"<<endl;
    inKQB(kqB);
    return 0;
}
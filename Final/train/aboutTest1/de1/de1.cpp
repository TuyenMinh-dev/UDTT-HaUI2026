#include <bits/stdc++.h>
using namespace std;
struct CauThu
{
    string hoTen;
    int namSinh;
    long long luongThang;
    int namThiDau;
};
void A1(vector<CauThu> d, int i)
{
    if (i == d.size())
    {
        return;
    }
    else
    {
        cout << left << setw(5) << i + 1
             << setw(15) << d[i].hoTen
             << setw(5) << d[i].namSinh
             << setw(10) << d[i].luongThang
             << d[i].namThiDau << endl;
        A1(d, i + 1);
    }
}
int A2(vector<CauThu> d, int left, int right)
{
    if (left == right)
    {
        return (d[left].namThiDau == 0) ? 1 : 0;
    }
    int mid = (right + left) / 2;
    int TLeft = A2(d, left, mid);
    int TRight = A2(d, mid + 1, right);
    return TLeft + TRight;
}
void soPAN(int &PAn, int n, vector<CauThu> &d, vector<int> viTri)
{
    PAn++;
    cout << "Phuong an " << PAn << ": " << endl;
    ;
    for (int i = 0; i < n; i++)
    {
        cout << "Vi tri " << i + 1 << " : " << d[viTri[i]].hoTen << endl;
    }
}
void A3(int k, int n, vector<bool> used, vector<int> viTri, int &PAn, vector<CauThu> d)
{
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            viTri[k] = i;
            used[i] = true;
            if (k == n - 1)
            {
                soPAN(PAn, n, d, viTri);
            }
            else
            {
                A3(k + 1, n, used, viTri, PAn, d);
            }
            used[i] = false;
        }
    }
}

int main()
{
    int n = 7;
    vector<CauThu> d{
        {"Ronaldo", 1985, 10000000, 2002},
        {"Messi", 1987, 10000000, 2004},
        {"Neymar", 1992, 6000000, 2009},
        {"Mbappe", 1998, 5000000, 2016},
        {"Nguyen Van A", 2007, 0, 0},
        {"Nguyen Van B", 2010, 0, 0},
        {"Bellingham", 2003, 3000000, 2020},
    };
    cout << "Danh sach cac cau thu: " << endl;
    cout << left << setw(5) << "STT"
         << setw(15) << "Name"
         << setw(5) << "Born"
         << setw(10) << "Salary"
         << "Started" << endl;
    A1(d, 0);
    cout << "So luong cau thu chua thi dau chuyen nghiep la: " << A2(d, 0, d.size() - 1);
    vector<int> viTri(n);
    vector<bool> used(n, false);
    int PAn = 0;
    A3(0, n, used, viTri, PAn, d);
    return 0;
}

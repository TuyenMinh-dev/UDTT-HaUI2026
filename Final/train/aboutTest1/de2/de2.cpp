#include <bits/stdc++.h>
using namespace std;
struct HocSinh
{
    string hoTen;
    double diemTK;
    string daoDuc;
    long long tienThuong;
};
long long A4(vector<HocSinh> d, int i, long long &tong)
{
    if (i == d.size())
    {
        return tong;
    }
    else
    {
        tong += d[i].tienThuong;
        return A4(d, i + 1, tong);
    }
}
int A5(vector<HocSinh> d, int left, int right)
{
    if (left == right)
    {
        return (d[left].diemTK >= 7.0) ? 1 : 0;
    }
    else
    {
        int mid = (left + right) / 2;
        int countLeft = A5(d, left, mid);
        int countRight = A5(d, mid + 1, right);
        return countLeft + countRight;
    }
}
void soCach(int &cach, int chon, vector<int> res, vector<HocSinh> d)
{
    cach++;
    cout << "Phuong an " << cach << ": " << endl;
    for (int i = 0; i < chon; i++)
    {
        cout << d[res[i]].hoTen << " - " << d[res[i]].daoDuc << endl;
    }
    cout << endl;
}
void A6(int k, int start, int n, vector<HocSinh> d, vector<int> res, int chon, int &cach)
{
    for (int i = start; i < n; i++)
    {
        res[k] = i;
        if (k == chon-1 )
        {
            soCach(cach, chon, res, d);
        }
        else
        {
            A6(k + 1, i + 1, n, d, res, chon, cach);
        }
    }
}
int main()
{
    int n = 7;
    vector<HocSinh> d{
        {"Quang Hai", 8, "Tot", 350000},
        {"Cong Phuong", 8.5, "Tot", 300000},
        {"Van Duc", 7, "Kha", 250000},
        {"Van Hai", 6, "Kha", 20000},
        {"Hai Long", 7.5, "Kha", 100000},
        {"Duc Long", 8, "Trung binh", 45000},
        {"Viet Ha", 5, "Trung binh", 50000}};
    long long tong = 0;
    cout << "Tong tien thuong cua cac hoc sinh la: " << A4(d, 0, tong) << endl;
    cout << "Co tat ca " << A5(d, 0, d.size() - 1) << " hoc sinh co diem tong ket lon hon 7.0" << endl;
    int chon = 6;
    vector<int> res(chon);
    int cach = 0;
    int start = 0;
    A6(0, 0, n, d, res, chon, cach);
    return 0;
}
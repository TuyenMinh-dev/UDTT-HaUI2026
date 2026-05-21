#include <bits/stdc++.h>
using namespace std;
struct Hang
{
	int ma;
	string diaChi;
	int khoiLuong;
	int giaTri;
};
bool compare(Hang a, Hang b)
{
	return a.giaTri > b.giaTri;
}
void ThamLam(vector<Hang> d, int &m)
{
	sort(d.begin(), d.end(), compare); // sap xep giam dan
	int p = 0;
	int u = 0;
	vector<int> danhSachLay;
	for (int i = 0; i < d.size(); i++)
	{
			u++;
			p += d[i].giaTri;
			danhSachLay.push_back(d[i].ma);
			if(p>m){
				break;
			}
		
	}
	cout << "Ket qua tham lam: " << endl;
	if (p > m)
	{
		cout << "u= " << u << endl;
		cout << "p= " << p << endl;
		cout << "Danh sach lay la: ";
		for (int x : danhSachLay)
		{
			cout << x << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "Khong lay duoc" << endl;
	}
}
void dynamic(vector<Hang> d, int &v, int &n)
{
	int dp[n + 1][v + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= d[i - 1].khoiLuong)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - d[i - 1].khoiLuong] + d[i - 1].giaTri);
			}
		}
	}
	// truy vet
	int i = n;
	int j = v;
	int q = 0;
	while (i > 0 && j > 0)
	{
		if (dp[i][j] != dp[i - 1][j])
		{
			q++;
			j -= d[i - 1].khoiLuong;
		}
		i--;
	}
	cout << "Ket qua QHD: " << endl;
	cout << "q= " << q << endl;
	cout << "t= " << dp[n][v] << endl;
}
int main()
{
	int n = 6;
	vector<Hang> d = {
		{1, "Cong ty Phuong Nam", 3, 10},
		{2, "Cong ty Phuong Tay", 4, 15},
		{3, "Cong ty Phuong Dong", 2, 7},
		{4, "Cong ty Phuong Bac", 1, 4},
		{5, "Cong ty Phuong Tay Nam", 5, 11},
		{6, "Cong ty Phuong Tay Bac", 6, 14}};
	int m = 30;
	int v = 12;
	ThamLam(d, m);
	dynamic(d, v, n);
	return 0;
}

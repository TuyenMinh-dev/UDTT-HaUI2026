#include <bits/stdc++.h>
using namespace std;
// tư tưởng: nghiệm của phương trình 4a+7b=n , để số mau mắn đó min thì b phải max(do số càng ngắn càng bé)
//  số các số 7 càng nhiều càng tốt, sau đó in các số 4 đứng trước
//  4a+7b=0 => nghiệm của a và b phải >=0 nên => b thuộc [0,n/7](do b min=0 , b max ->a min , a min=0)
void solve()
{
    int n;
    cout << "Nhap gia tri bo test: ";
    cin >> n;
    bool ok = 0;
    int b_final ;
    int a=-1 ;
    // duyệt từ max của b về để đảm bảo được
    for (int b=n/7; b >= 0; b--)
    {   
        int con_lai=n-7*b;//cap nhat lai phan con lai sau moi lan xet bien b
        if ((con_lai) % 4 == 0)
        {   b_final=b;
            ok = 1;
            a=con_lai/4;
            break;
        }
    }
    if (!ok)
    {
        cout << "-1";
    }
    else
    {
        for (int i = 0; i < a; i++)
        {
            cout << "4";
        }
        for (int i = 0; i < b_final; i++)
        {
            cout << "7";
        }cout<<endl;
    }
}
int main()
{
    int n;
    cout << "\n Nhap so luong bo test: ";
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}
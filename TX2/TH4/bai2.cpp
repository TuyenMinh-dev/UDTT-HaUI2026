#include <bits/stdc++.h>
using namespace std;

void tang_dan(int a[], int n)
{
    sort(a, a + n);
}
int A2(int *a, int n, long q)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (q >= a[i])
        { // kiem lai phan con lai truoc moi lan tru
            q -= a[i];
            ans++; // chi cong khi so nuoc con lai du de lap day chai nuoc dang xet
        }
        else
        {
            break;
        }
    }
    return ans;
}

int main()
{
    int a[] = {5, 2, 1, 3};
    int n = 4;
    long q = 10;
    tang_dan(a, n);
    cout << "Co toi da " << A2(a, n, q) << " chai nuoc duoc do day";
    return 0;
}
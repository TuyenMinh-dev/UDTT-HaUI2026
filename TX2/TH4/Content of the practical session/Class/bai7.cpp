#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void lis(int &n, int *a, vector<int> L)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                L[i] = max(L[i], L[j] + 1);
            }
        }
    }
    int x = *max_element(L.begin(), L.end());
    cout << "Do dai cua day con tang dai nhat la: " << x << endl;
    int pos_max = 0;
    int max = L[0];
    for (int i = 0; i < n; i++)
    {
        if (L[i] > max)
        {
            max = L[i];
            pos_max = i;
        }
    }
    cout << "Day con tang don dieu cu the la: " << endl;
    for (int i = pos_max - x + 1; i <= pos_max; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n = 6;
    int a[] = {3, 4, 1, 2, 4, 7};
    vector<int> L(n, 1);
    lis(n, a, L);
    return 0;
}

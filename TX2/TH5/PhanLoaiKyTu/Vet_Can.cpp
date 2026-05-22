#include <bits/stdc++.h>
using namespace std;
int indexOf(char *s, char key, int m)// s là xâu đang xét, key là kí tự đang xét , m là để lưu sô ký tự KHÁC NHAU
{
    for (int index = 0; index < m; index++)
    {
        if (s[index] == key)
            return index;
    }
    return -1;
}
void solve(char *s, char *t, int *c, int &m)// t là mảng chứa các ký tự khác nhua
                                            // c là mảng chứa số lần xuát hiện của từng phần tử tương ứng
{
    m = 0;//ban đầu chưa có ký tự nào
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        int index = indexOf(t, s[i], m);
        if (index == -1)//kí tự chưa tồn tại
        {
            t[m] = s[i];//đẩy s[i] vào mảng t
            c[m] = 1;
            m++;//tăng số lượng số phân tửu khác nhau
        }
        else
        {
            c[index]++;
        }
    }
}
int main()
{
    char s[] = "aabcabdc";
    char t[100];
    int c[100];
    int m;

    solve(s, t, c, m);

    for (int i = 0; i < m; i++)
    {
        cout << t[i] << " : " << c[i] << endl;
    }

    return 0;
}

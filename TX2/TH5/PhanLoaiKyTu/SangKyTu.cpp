#include <bits/stdc++.h>
using namespace std;

void sang_ky_tu(char *s, int *sang)
{
    for (int i = 0; i < strlen(s); i++)
    {
        sang[s[i]]++;//máy tính tự đổi kí tụ s[i] này thành một số mang giá trị là index của s
    }
}

int main()
{
    char s[] = "aabcabdc";

    int sang[256] = {0};

    sang_ky_tu(s, sang);

    for (int i = 0; i < 256; i++)//duyệt mảng sàng
    {
        if (sang[i] > 0)
        {
            cout << char(i) << " : " << sang[i] << endl;
        }       //char(i) đổi từ số sang chữ
                // ép cái i đấy sang kiểu char
    }

    return 0;
}
/*
把字符串用数字表示

https://pan.baidu.com/pfile/video?path=%2F2+%E8%80%83%E7%A0%94%E8%B5%84%E6%96%99%2F24%E5%A4%8D%E8%AF%95-%E6%9D%AD%E7%94%B5%2F%E7%AE%97%E6%B3%95%E5%9F%BA%E7%A1%80%E8%AF%BE%2F%E7%AC%AC%E4%BA%8C%E7%AB%A0+%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%2F%E7%AC%AC%E4%BA%8C%E7%AB%A0+%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%EF%BC%88%E4%B8%89%EF%BC%89.mp4

01:06:47 之后再看，先看 STL模版
*/

#include <iostream>
using namespace std;

typedef unsigned long long ULL;

const int N = 100010,
          P = 131; // p进制， 约定俗成，冲突的概率最低,或者 13331

int n, m;
char str[N];
ULL h[N], // 数字过大 会自动 mod 2^64
    p[N]; // 保存 p的幂次， 方便 h[i] * p^i

ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    scanf("%d%d%s", &n, &m, str + 1);

    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }
    while (m--)
    {
        int l1, r1, l2, r2;
        cin >> l1, r1, l2, r2;

        if (get(l1, r1) == get(l2, r2))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
/*

8 3
aabbaabb
1 3 5 7
1 3 6 8
1 2 1 2


*/
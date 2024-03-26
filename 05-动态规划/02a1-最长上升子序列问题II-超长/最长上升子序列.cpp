/*
给定一个长度为N的数列，求数值严格单调递增的子序列的长度最长是多少。

输入格式

第一行包含整数N。
第二行包含N个整数,表示完整序列。

输出格式

输出一个整数，表示最大长度。

数据范围

1<N<1000
-109<数列中的数<109

*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <localCheck.h>
using namespace std;

const int N = 1010, INF = 1e9;

int n, m;

int a[N];
// 保存路径最大值
int f[N];

int main()
{
    FREOPEN
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        f[i] = 1; // 只有a[i] 一个数
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, f[i]);
    cout << res << endl;
    CHECK
    return 0;
}
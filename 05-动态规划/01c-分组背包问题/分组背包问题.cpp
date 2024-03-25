/*
有N种物品和一个容量是V 的背包。
第i 种物品最多有 si件，每件体积是 vi，价值是 Wi。


*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <localCheck.h>
using namespace std;

const int N = 2010;

// n 个数，m 背包容量
int n, m;

// v 体积 ，w 价值 , s 每个组的个数
int v[N][N], w[N][N], s[N];

int f[N];

int main()
{
    FREOPEN
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for (int j = 0; j <= s[i]; j++)
            cin >> v[i][j] >> w[i][j];
    }

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 0; j--)
            for (int k = 0; k < s[i]; k++)
                if (v[i][k] <= j)
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);

    cout << f[m] << endl;
    CHECK
    return 0;
}
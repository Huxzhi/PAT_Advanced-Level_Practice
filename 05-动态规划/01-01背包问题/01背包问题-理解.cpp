/*
有 N 件物品和一个容量是 V的背包。每件物品只能使用一次。
第i件物品的体积是v,,价值是w;。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

输入格式
第一行两个整数, N, V,用空格隔开,分别表示物品数量和背包容积。
接下来有N行,每行两个整数vi,w,,用空格隔开,分别表示第;件物品的体积和价值。

输出格式
输出一个整数，表示最大价值。

数据范围
0<N,V <=1000
0<W <=1000

*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <localCheck.h>
using namespace std;

const int N = 1010;

// n 个数，m 背包容量
int n, m;

// v 体积 ，w 价值
int v[N], w[N];

// dp[i][j] 表示从下标为[0-i]的物品里任意取，放进容量为j的背包，价值总和最大是多少
int f[N][N];

// x 表示没有用到
const int x = 99;
void display()
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << f[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    FREOPEN
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
        cin >> v[i] >> w[i];

    // f[0][0~m] =0 // 已经初始化

    // i 表示 能放入 i 个物品

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            //  dp[i][j] 表示从下标为[0-i]的物品里任意取，放进容量为j的背包，价值总和最大是多少

            // 可以放入第i件东西，但是 不放放东西
            f[i][j] = f[i - 1][j];

            // v[i] 表示 上一状态 放入背包的体积
            // j 表示 这次状态的背包容量，如果v[i] 大于j 是放不进背包的
            if (j >= v[i])
                // 此时的 f[i][j] = f[i - 1][j];
                // j++,导致可能可以放入更多的东西
                // j-v[i]  ，因为 j 表示背包的容量，刚好对应不放东西的时候 f[i][0]=0
                f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);

            cout << i << '-' << j << ":" << endl;
            display(); // 看一下步骤
        }

    cout << f[n][m] << endl;
    CHECK
    return 0;
}
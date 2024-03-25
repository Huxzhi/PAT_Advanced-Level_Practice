/*
有N种物品和一个容量是V的背包,每种物品都有无限件可用。
第i种物品的体积是vi,价值是Wi。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值很大。
输出最大价值。
输入格式
第一行两个整数, N, V,用空格隔开,分别表示物品种数和背包容积。
接下来有N行,每行两个整数0i,wi,用空格隔开,分别表示第i种物品的体积和价值。
输出格式
输出一个整数,表示最大价值。
数据范围
 0<N,V<1000
 0 < υι, ωι < 1000
 I

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
int f[N];

int main()
{
    FREOPEN
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    // f[0][0~m] =0 // 已经初始化

    for (int i = 1; i <= n; i++)
        // 和 01背包问题区别，是从大到小,要正向枚举，可以覆盖
        for (int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;
    CHECK
    return 0;
}
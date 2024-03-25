/*
有N种物品和一个容量是V 的背包。
第i 种物品最多有 si件，每件体积是 vi，价值是 Wi。
求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。
输入格式
第一行两个整数, N, V,用空格隔开,分别表示物品种数和背包容积。
接下来有N行,每行三个整数vi,Wi, Si,用空格隔开,分别表示第i种物品的体积、价值和数量。
输出格式
输出一个整数，表示最大价值。
数据范围
 0<N,V<100
 0<υ, ω, Si < 100

*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <localCheck.h>
using namespace std;

const int N = 110;

// n 个数，m 背包容量
int n, m;

// v 体积 ，w 价值
int v[N], w[N], s[N];

// dp[i][j] 表示从下标为[0-i]的物品里任意取，放进容量为j的背包，价值总和最大是多少
int f[N][N];

int main()
{
    FREOPEN
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> s[i];

    // f[0][0~m] =0 // 已经初始化

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            // 状态计算的时候，要算拿掉 0，1，2... k 个 物品后背包的大小
            for (int k = 0; k <= s[i] && k * v[i] <= j; k++)

                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);

    cout << f[n][m] << endl;
    CHECK
    return 0;
}
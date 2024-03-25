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
 0<N,V<2000
 0<υ, ω, Si < 1000

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

// v 体积 ，w 价值
int v[N], w[N];

int f[N];

int main()
{
    FREOPEN
    cin >> n >> m;

    int cnt = 0; // 在读取物品数据的时候就 打包好
    for (int i = 0; i < n; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1; // 1,2,4,8 ... 2^k <=s 为止
        while (k <= s)
        {
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        if (s > 0)
        {
            cnt++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }

    n = cnt;
    // 此时已经变成了 01背包问题，写上优化后的代码
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;
    CHECK
    return 0;
}
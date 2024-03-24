#include <iostream>
#include <algorithm>
#include <localCheck.h>
#include <unordered_map>

using namespace std;

/*
给定n组ai,bi, pi,对于每组数据,求出a mod pi的值。

输入格式
第一行包含整数n。
接下来n行,每行包含三个整数a_i,b_i,p_i

输出格式
对于每组数据,输出一个结果,表示amod pi的值。
每个结果占一行。

数据范围
1<n<100000,
1<ai, bi,pi <2*10^9

*/

typedef long long LL;

const int N = 1e6 + 10;
int primes[N], cnt;
int phi[N];
bool st[N];

// 快速幂 a^k % p
LL qmi(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        // 依次取出 k 的 二进制位
        if (k & 1)
            // a = a * a % p
            res = (LL)res * a % p;
        k >>= 1;
        // a^4 % p = a^2 * a^2 % p
        a = (LL)a * a % p;
    }
    return res;
}

int n;

int main()
{
    FREOPEN

    cin >> n;
    while (n--)
    {
        int a, k, p;
        cin >> a >> k >> p;
        cout << qmi(a, k, p) << endl;
    }

    CHECK
    return 0;
}
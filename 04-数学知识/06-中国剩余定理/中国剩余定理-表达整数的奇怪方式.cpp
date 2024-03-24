#include <iostream>
#include <algorithm>
#include <localCheck.h>
#include <unordered_map>

using namespace std;

/*
给定2n个整数a1, a2,..., an和m1,m2,...,mn,求一个最小的整数x,满足Vi e [1, n],x= mi(mod ai)

输入格式
第1行包含整数n。
第2..n行：每i+1行包含两个整数a;和m,数之间用空格隔开。

输出格式
输出整数x,如果x不存在，则输出-1。

数据范围
1<αι < 231 – 1,
0<m; < αi


*/

typedef long long LL;

const int N = 1e6 + 10;
int primes[N], cnt;
int phi[N];
bool st[N];

// 快速幂 a^k % p
int n;
int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    FREOPEN
    int res;
    cin >> n;
    while (n--)
    {
        int a, b, m;
        cin >> a >> b >> m;
        int x, y;
        int d = exgcd(a, m, x, y);
        if (b % d)
            cout << "impossible" << endl;
        else
            cout << (LL)x * (b / d) % m << endl;
    }

    CHECK
    return 0;
}
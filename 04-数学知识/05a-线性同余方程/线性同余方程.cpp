#include <iostream>
#include <algorithm>
#include <localCheck.h>
#include <unordered_map>

using namespace std;

/*
给定n组数据ai，bi，mi，对于每组数求出一个xi，使其满足ai * xi = bi(mod mi），如果无解则输出impossible
输入格式

第一行包含整数n。
接下来n行,每行包含一组数据ai,bi,mi


输出格式
输出共n行,每组数据输出一个整数表示一个满足条件的x;,如果无解则输出impossible。
每组数据结果占一行，结果可能不唯一，输出任意一个满足条件的结果均可。
输出答案必须在int范围之内。

数据范围
1<n<105,
1<ai,bi,mi <2*109

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
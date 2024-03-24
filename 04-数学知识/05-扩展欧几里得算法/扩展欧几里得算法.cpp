#include <iostream>
#include <algorithm>
#include <localCheck.h>
#include <unordered_map>

using namespace std;

/*
 给定n对正整数ai,b;,对于每对数,求出一组xi,yi,使其满足a; *ay+ b; *y; = gcd(ai,bi)。
输入格式
第一行包含整数n。
接下来n行,每行包含两个整数ai,bi。
输出格式
输出共n行，对于每组ai，bi，求出一组满足条件的xi，yi，每组结果占一行。
本题答案不唯一，输出任意满足条件的xi,yi均可。
数据范围
 1<n<105,
 1<ai,bi <2* 109

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
        int a, b, x, y;
        cin >> a >> b;
        exgcd(a, b, x, y);
        cout << x << " " << y << endl;
    }

    CHECK
    return 0;
}
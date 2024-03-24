#include <iostream>
#include <algorithm>
#include <localCheck.h>
#include <unordered_map>

using namespace std;

/*
给定n组ai,pi,其中p;是质数,求a;模p;的乘法逆元,若逆元不存在则输出impossible
乘法逆元的定义
若整数b，m互质，并且bla，则存在一个整数x，使得a/b = a * x(mod m)，则称x为b的模m乘法逆元，
 记为b-1(mod m)。
b存在乘法逆元的充要条件是b与模数m互质。当模数m为质数时,bm-2即为b的乘法逆元。
输入格式
第一行包含整数n。
接下来n行,每行包含一个数组ai,pi,数据保证p;是质数。
输出格式
输出共n行，每组数据输出一个结果，每个结果占一行。
若a;模p;的乘法逆元存在，则输出一个整数，表示逆元，否则输出impossible。
数据范围
1<n<105,
1 < ai,pi <2* 109


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
    int res;
    cin >> n;
    while (n--)
    {
        int a, p;
        cin >> a >> p;
        res = qmi(a, p - 2, p);
        if (a % p)
            cout << res << endl;
        else
            cout << "impossible" << endl;
    }

    CHECK
    return 0;
}
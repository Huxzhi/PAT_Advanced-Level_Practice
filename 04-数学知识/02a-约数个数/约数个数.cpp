#include <iostream>
#include <algorithm>
#include <localCheck.h>
#include <unordered_map>

using namespace std;

/*
给定n个正整数ai,请你输出这些数的乘积的约数个数,答案对10^9 +7取模。


输入格式
第一行包含整数n。
接下来n行,每行包含一个整数ai。


输出格式
输出一个整数，表示所给正整数的乘积的约数个数，答案需对10^9 +7取模。


数据范围
1<n<100,
1<α<2* 10^9

*/

int n;

typedef long long LL;
const int mod = 10e+7;

int main()
{
    FREOPEN

    cin >> n;

    // 保存对应的 质数 和 指数
    unordered_map<int, int> primes;
    while (n--)
    {
        int x;
        cin >> x;
        for (int i = 2; i < x / i; i++)
            // 把所有的质因子 和 指数加起来就可以了
            while (x % i == 0)
            {
                x /= i;
                primes[i]++;
            }

        if (x > 1)
            primes[x]++;
    }

    LL res = 1;
    for (auto prime : primes)
    {
        res *= (prime.second + 1) % mod;
    }
    cout << res << endl;
    CHECK
    return 0;
}
#include <iostream>
#include <algorithm>
#include <localCheck.h>
using namespace std;
/*
给定一个正整数n，请你求出1~n中质数的个数。
输入格式
共一行，包含整数n。
输出格式
共一行，包含一个整数，表示1~n中质数的个数。
数据范围
 1<n<10^6

*/

const int N = 1e7 + 10;
// 质数表
int primes[N], cnt, n;
bool st[N];

// 埃氏筛法
void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        // 优化 算法 是 一个埃及人发明的，所以叫 埃氏筛法
        if (!st[i])
        {
            primes[cnt++] = i; // 添加到质数表中

            // 只需要把 质数的倍数筛掉即可
            for (int j = i + i; j <= n; j += i)
                st[j] = true;
        }
    }
}
// 线性筛法
void get_primes2(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[cnt++] = i; // 添加到质数表中

        // n 只会被自己最小的质因子筛掉
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;

            if (i % primes[j] == 0) // primes[j] 一定是 i 的最小质因子
                break;
        }
    }
}
int main()
{
    FREOPEN

    cin >> n;
    get_primes2(n);
    cout << cnt << endl;

    CHECK
    return 0;
}
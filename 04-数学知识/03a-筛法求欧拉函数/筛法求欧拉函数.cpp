#include <iostream>
#include <algorithm>
#include <localCheck.h>
#include <unordered_map>

using namespace std;

/*
给定一个正整数n，求1~n中每个数的欧拉函数之和。
输入格式
共一行，包含一个整数n。
输出格式
共一行，包含一个整数，表示1~n中每个数的欧拉函数之和。
数据范围
 1<n<106



*/

typedef long long LL;

const int N = 1e6 + 10;
int primes[N], cnt;
int phi[N];
bool st[N];

// 线性筛法
LL get_eulers(int n)
{

    for (int i = 2; i <= n; i++)
    {
        phi[1] = 1;
        if (!st[i])
        {
            primes[cnt++] = i;
            // 质数的欧拉函数 phi(x) 的值 为 x-1
            phi[i] = i - 1;
        }

        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            // pj为最小质因子
            if (i % primes[j] == 0)
            {
                // 由公式推导出来的
                phi[primes[j] * i] = primes[j] * phi[i];
                break;
            }
            else
                // 也是公式推导
                phi[primes[j] * i] = (primes[j] - 1) * phi[i];
        }
    }
    LL res = 0;
    for (int i = 1; i <= n; i++)
        res += phi[i];
    return res;
}

int n;

int main()
{
    FREOPEN

    cin >> n;
    cout << get_eulers(n) << endl;

    CHECK
    return 0;
}
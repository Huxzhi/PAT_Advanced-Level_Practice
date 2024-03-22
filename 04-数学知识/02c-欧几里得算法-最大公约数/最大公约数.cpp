#include <iostream>
#include <algorithm>
#include <localCheck.h>
#include <unordered_map>

using namespace std;

/*
给定n对正整数Sa_i,b_is,请你求出每对数的最大公约数。
输入格式
第一行包含整数n。
接下来n行,每行包含一个整数对$a_i,b_is。
输出格式
输出共n行,每行输出一个整数对的最大公约数。
数据范围

$1 \le n \le 10^5$,
$1 \le a_i, b_i \le 2*10^9$

*/

int n;

typedef long long LL;
const int mod = 10e+7;

// 一行代码
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    FREOPEN

    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }

    CHECK
    return 0;
}
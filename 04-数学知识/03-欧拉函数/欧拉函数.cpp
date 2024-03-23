#include <iostream>
#include <algorithm>
#include <localCheck.h>
#include <unordered_map>

using namespace std;

/*
给定n个正整数ai,请你求出每个数的欧拉函数。

欧拉函数的定义

$N=p_1^{a_1}p_2^{a_2}\cdots p_k^{a_k}$
$\phi(N)=N(1-\frac{1}{p_1})(1-\frac{1}{p_2}) \cdots (1-\frac{1}{p_k})$


输入格式
第一行包含整数n。
接下来n行,每行包含一个正整数ai。


输出格式
输出共n行,每行输出一个正整数a,的欧拉函数。


*/
// 欧拉函数，使用公式进行计算，过程由公式推导的

// $N=p_1^{a_1}p_2^{a_2}\cdots p_k^{a_k}$
// $\phi(N)=N(1-\frac{1}{p_1})(1-\frac{1}{p_2}) \cdots (1-\frac{1}{p_k})$
int get_euler(int x)
{
    int res = x;
    for (int i = 2; i <= x / i; i++)

        // 求出所有质因子
        if (x % i == 0)
        {
            // 公式
            res = res / i * (i - 1);

            // 不在意 质因子的指数
            while (x % i == 0)
                x /= i;
        }

    // 还有一个较大的质因子
    if (x > 1)
        res = res / x * (x - 1);

    return res;
}

int n;

int main()
{
    FREOPEN

    cin >> n;
    int x;
    while (n--)
    {

        cin >> x;
        cout << get_euler(x) << endl;
    }

    CHECK
    return 0;
}
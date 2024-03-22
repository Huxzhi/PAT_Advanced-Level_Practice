#include <iostream>
#include <algorithm>
#include <localCheck.h>
#include <vector>

using namespace std;

/*
给定n个正整数a_i，对于每个整数a_i,请你按照从小到大的顺序输出它的所有约数。
输入格式
第一行包含整数n。
接下来n行,每行包含一个整数a_i。

输出格式
输出共n行,其中第i行输出第i个整数az的所有约数。

数据范围
1<n<100,
2<α;<2*10^9
*/

// 试除法
vector<int> get_divisors(int n)
{
    vector<int> res;
    for (int i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (i != n / i)
                res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}
int n;
int main()
{
    FREOPEN

    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        auto res = get_divisors(x);

        for (auto r : res)
            cout << r << " ";

        cout << endl;
    }

    CHECK
}
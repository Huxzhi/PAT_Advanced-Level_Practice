#include <iostream>
#include <algorithm>
#include <localCheck.h>
using namespace std;
/*

给定n个正整数a,，对于每个整数a,请你按照从小到大的顺序输出它的所有约数。
输入格式
第一行包含整数n。
接下来n行，每行包含一个整数ai。
输出格式
输出共n行,其中第i行输出第i个整数ag的所有约数。
数据范围
 1<n<100,
 2<α <2 * 109
*/
void divide(int n)
{
    // n中最多只包含一个大于 sqrt(n)的质因子
    for (int i = 2; i <= n / i; i++)
        if (n % i == 0)
        {
            int s = 0;
            while (n % i == 0)
            {
                n /= i;
                s++;
            }
            // 底数 和 次数
            cout << i << " " << s << endl;
        }

    if (n > 1)
        cout << n << " " << 1 << endl
             << endl;
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
        divide(x);
    }

    CHECK
    return 0;
}
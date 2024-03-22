#include <iostream>
#include <algorithm>
#include <localCheck.h>
using namespace std;

bool is_prime(int n)

{
    if (n < 2)
        return false;
    // 不推荐 i <= sqrt(n) slow
    // 也不推荐 i * i <= n 溢出风险
    for (int i = 2; i <= n / i; i++)
        if (n % i == 0)
            return false;
    return true;
}
int n;
int main()
{
    FREOPEN

    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        if (is_prime(a))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    CHECK
}
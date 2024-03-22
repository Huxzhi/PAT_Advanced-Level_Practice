#include <iostream>
using namespace std;

int main()
{
    double x;
    cin >> x;

    double l = -1000, r = 1000;
    // 一般要比 要求的精度+2
    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x)
            r = mid;
        else
            l = mid;
    }
    cout << l << endl;
    return 0;
}
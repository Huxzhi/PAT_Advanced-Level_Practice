#include <iostream>
#define MAX(i, j) (((i) > (j)) ? (i) : (j))
using namespace std;
int main()
{
    double x;
    cin >> x;

    double l = 0, r = MAX(x, 1);
    // 一般要比 要求的精度+2
    // for 循环100次也可以
    while (r - l > 1e-6)
    {
        double mid = (l + r) / 2;
        if (mid * mid >= x)
            r = mid;
        else
            l = mid;
    }
    cout << l << endl;
    return 0;
}
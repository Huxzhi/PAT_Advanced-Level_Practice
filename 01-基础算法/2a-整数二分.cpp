#include <iostream>
using namespace std;
const int n = 6;
int q[n] = {1, 2, 3, 3, 4, 5};
int x = 3;
// q 为单调不递减数列，输入 3， 找到3的最前面的下标和最后的下标
int main()
{
    int l = 0, r = n - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (q[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }

    if (q[l] != x)
        cout << "-1 -1" << endl;
    else
    {
        cout << l << " ";
        while (l < r)
        {
            int mid = l + r + 1 >> 2;
            if (q[mid] <= x)
                l = mid;
            else
                r = mid - 1;
        }
        cout << l << endl;
    }

    return 0;
}
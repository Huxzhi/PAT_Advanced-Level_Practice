#include <iostream>
#include <string.h>
using namespace std;

/*
给定两个 升序排序 的有序数组A和B,以及一个目标值x。数组下标从0开始。
请你求出满足A[i] + B[j] = x 的数对(i, j)。

数据保证有唯一解。 才能用双指针优化

暴力做法  O(n^2)
双重循环 i j， A[i] + B[j] = x

找到 i 和 j 的关系 O(n+m)
初始化 i=0 ， j=m ,
 当 A[i] + B[i] >= x ,j--

当 i 增大，j必然减小



4 5 6
1 2 4 7
3 4 6 8 9

*/

const int N = 1e6 + 10;

int a[N], b[N];
int n, m, k;

int main()
{
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    for (int i = 0, j = m - 1; i < n; i++)
    {
        // j 有单调性，可以优化
        while (j >= 0 && (a[i] + b[j]) > k)
            j--;

        if ((a[i] + b[j]) == k)
        {
            cout << i << " " << j;
            break;
        }
    }

    return 0;
}
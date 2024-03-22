/**
 * @file 5a-双指针算法.cpp
 * @author Huxzhi
 * @brief
 * @version 0.1
 * @date 2024-03-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <string.h>
using namespace std;

// 朴素做法: O(n^2)
// for (int i = 0; i < n; i++)
//     for (int j = 0; j <= i; j++)
//         if (check(j, i))
//             res = max(res, j - i + 1);

const int N = 1e6 + 10;
int n;
int a[N], s[N];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        // i 在前， j在后
        s[a[i]]++;
        while (s[a[i]] > 1)
        {
            s[a[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}
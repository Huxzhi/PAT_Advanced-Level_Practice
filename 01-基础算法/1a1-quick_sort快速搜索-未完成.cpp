#include <iostream>
#include <algorithm>
using namespace std;

/**
用快速搜索 找到 某一个值 的最小的下标
 *
 */

int n;
// int q[100001];

// 从小到大
// 确定数组分界的下标
void quick_sort(int q[], int l, int r)
{

    if (l >= r)
        return;
    int x = q[l], // 确定分界点 x
        i = l - 1, j = r + 1;
    while (i < j)
    {

        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
        {
            swap(q[i], q[j]);
        }
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

bool Compare(int x, int y) // 降序排序
{
    return x > y;
}

int main()
{
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++)
    // scanf("%d", &q[i]);
    int q[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    n = 9;
    quick_sort(q, 0, n - 1);
    // sort(q, q + n);
    // sort(q, q + n, ompare);

    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
}
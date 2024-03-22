#include <iostream>
using namespace std;

typedef long long LL;

const int N = 6;
int q[N] = {2, 3, 4, 5, 6, 1};

int tmp[N];
LL m = 0; // 逆序数的结果 可能会很大

// 从小到大
// 确定数组分界的下标
/**
 *  一共有3种可能
 *
 * 1. 在左半边内部的逆序对数量 0
 * 2. 在右边内部的逆序对数量 0
 * 3. 一个在左边，一个在右边  res = mid - i +1
 */

void merge_sort(int q[], int l, int r)
{

    if (l >= r)
        return;
    int mid = (l + r) >> 1; // 等价于 除二
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);

    // 处理合并
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else
        {
            tmp[k++] = q[j++];
            m += mid - i + 1; // 在此处统计逆序数的个数
        }

    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];

    // 放回原处，
    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
}

int main()
{
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++)
    // scanf("%d", &q[i]);

    merge_sort(q, 0, N - 1);

    for (int i = 0; i < N; i++)
        printf("%d ", q[i]);

    cout << m;
}
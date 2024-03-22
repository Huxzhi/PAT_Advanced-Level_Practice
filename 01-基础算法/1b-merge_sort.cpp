#include <iostream>
using namespace std;

int q[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
const int n = 9;
int tmp[n];
// int q[100001];

// 从小到大
// 确定数组分界的下标
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
            tmp[k++] = q[j++];
    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];

    // 放回原处
    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
}

int main()
{
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++)
    // scanf("%d", &q[i]);

    merge_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
}
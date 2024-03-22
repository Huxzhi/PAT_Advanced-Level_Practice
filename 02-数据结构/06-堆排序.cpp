// 不是 STL 的堆， 手写一个堆
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;

int heap[N], sizes;
int n, m;
// 递归的过程
void down(int u)
{
    int t = u;
    if (u * 2 <= sizes && heap[u * 2] < heap[t])
        t = u * 2;
    if (u * 2 + 1 <= sizes && heap[u * 2 + 1] < heap[t])
        t = u * 2 + 1;
    if (u != t) // 满足上面两个条件
    {
        swap(heap[t], heap[u]);
        return down(t);
    }
}

void up(int u)
{
    while (u / 2 && heap[u / 2] > heap[u])
    {
        swap(heap[u], heap[u / 2]);
        u /= 2;
    }
}

void removeTop()
{
    heap[1] = heap[sizes--];
    down(1);
}

int getTop()
{
    return heap[1];
}

// 建堆 O(n) ，比 insert O(nlogn)
void initHeap(int heap[], int n)
{
    for (int i = n / 2; i; i--)
        down(i);
}

int main()
{
    cin >> n >> m;
    sizes = n;
    for (int i = 1; i <= n; i++)
        cin >> heap[i];

    initHeap(heap, n);

    // for (int i = 1; i <= n; i++)
    //     cout << heap[i] << " ";
    // puts("");

    while (m--)
    {
        cout << getTop() << ' ';
        removeTop();
    }
    return 0;
}

/*
5 3
2 3 5 1 2

1 2 2
*/
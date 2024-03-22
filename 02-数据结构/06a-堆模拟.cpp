// 不是 STL 的堆， 手写一个堆
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
/*

维护一个集合，初始时集合为空，支持如下几种操作：

1."Ix”，插入一个数 x;
2."PM"，输出当前集合中的最小值；
3.“DM”，删除当前集合中的最小值（当最小值不唯一时，删除最早插入的最小值）；
4.“D k”，删除第 k 个插入的数；
5."C k x"，修改第 k 个插入的数，将其变为x;

现在要进行N次操作，对于所有第2个操作，输出当前集合的最小值。


*/
int heap[N], sizes;

// 额外保存一些信息 pointer heap
int ph[N]; // 保存第 i 个插入的元素，保存在哪里 ph[j]=k;
int hp[N]; // heap下标对应的元素为第几个插入 hp[k]=j;

void heap_swap(int a, int b)
{
    swap(heap[a], heap[b]);
    // 额外进行两步操作
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
}

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
        heap_swap(t, u);
        return down(t);
    }
}

void up(int u)
{
    while (u / 2 && heap[u / 2] > heap[u])
    {
        heap_swap(u, u / 2);
        u /= 2;
    }
}

void insert(int x, int &m)
{
    sizes++;
    m++;
    ph[m] = sizes, hp[sizes] = m;
    heap[sizes] = x;
    up(sizes);
}

void removeTop()
{
    heap_swap(1, sizes);
    sizes--;
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
    int n;
    cin >> n;
    while (n--)
    {
        char op[10];
        int k, x;
        cin >> op;
        if (!strcmp(op, "I"))
        {
            cin >> x;
            insert(x, m);
        }
        else if (!strcmp(op, "PM"))
            cout << getTop();
        else if (!strcmp(op, "DM"))
            removeTop();
        else if (!strcmp(op, "D"))
        {
            cin >> k;
            k = ph[k];
            heap_swap(k, sizes);
            sizes--;
            down(k), up(k);
        }
        else
        {
            cin >> k, x;
            k = ph[k];
            heap[k] = x;
            down(k), up(k);
        }
    }

    return 0;
}

/*
5 3
2 3 5 1 2

1 2 2
*/
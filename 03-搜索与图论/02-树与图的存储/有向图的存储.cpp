#include <iostream>
#include <algorithm>
#include <cstring>
#define LOCAL
using namespace std;

const int N = 1e5 + 10, M = N * 2;

// 结点队列
int h[N];

// 静态链表，效率最高，比 vector 高
int e[M], ne[M], idx;

void add(int a, int b)
{
    // 头插法
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    memset(h, -1, sizeof h);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
}
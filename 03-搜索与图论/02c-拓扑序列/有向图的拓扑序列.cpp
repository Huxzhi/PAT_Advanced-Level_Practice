/*
给定一个n个点m条边的有向图，图中可能存在重边和自环。

请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出-1。

若一个由图中所有点构成的序列A满足:对于图中的每条边(x,y),x在A中都出现在y之前,则称A是该图的一个拓扑序列。


*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <localCheck.h>
using namespace std;

const int N = 1e5 + 10, M = N * 2;

int n, m;
// 结点队列
int h[N];

// 静态链表，效率最高，比 vector 高
int e[M], ne[M], idx;

// d 表示 入度，q 静态队列
int d[N], q[N];

void add(int a, int b)
{
    // 头插法
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool topsort()
{
    int hh = 0, tt = -1; // 自己实现一个队列
    q[0] = 1;

    // 所有入度为0的点进入队列
    for (int i = 1; i <= n; i++)
    {
        if (!d[i])
            q[++tt] = i;
    }

    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j]--;
            if (d[j] == 0)
                q[++tt] = j;
        }
    }
    return tt == n - 1;
}

int main()
{
    FREOPEN
    cin >> n >> m;
    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++; // 入度+1
    }

    if (topsort())
    {
        for (int i = 0; i < n; i++)
            cout << q[i] << ' ';
    }
    else
        cout << "-1" << endl;

    CHECK
    return 0;
}
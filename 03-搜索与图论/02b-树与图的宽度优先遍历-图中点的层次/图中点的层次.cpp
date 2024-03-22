/*
给定一个n个点m条边的有向图，图中可能存在重边和自环。

所有边的长度都是1,点的编号为1~n。
 todo 说明可以用 宽搜


请你求出1号点到n号点的最短距离,如果从1号点无法走到n号点,输出-1。


输入格式

第一行包含两个整数n和m。
接下来m行,每行包含两个整数a和b,表示存在一条从a走到b的长度为1的边。


输出格式

输出一个整数，表示1号点到n号点的最短距离。


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

int d[N], q[N];

void add(int a, int b)
{
    // 头插法
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int bfs()
{
    int hh = 0, tt = 0; // 自己实现一个队列
    q[0] = 1;

    memset(d, -1, sizeof d); // 没有走过

    d[1] = 0;
    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (d[j] == -1)
            {
                d[j] = d[t] + 1;
                q[++tt] = j; // 数组模拟队列的一种写法
            }
        }
    }
    return d[n];
}

int main()
{
    FREOPEN

    cin >> n >> m;
    memset(h, -1, sizeof h);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    cout << bfs << endl;

    CHECK
    return 0;
}
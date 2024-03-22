#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <localCheck.h>
using namespace std;

/*
给定一个n个点m条边的有向图，图中可能存在重边和自环，所有边权均为正值。
请你求出1号点到n号点的最短距离,如果无法从1号点走到n号点,则输出-1。

输入格式

第一行包含整数n和m。

接下来m行每行包含三个整数x, y,z,表示点x和点y之间存在一条有向边,边长为z。


输出格式

输出一个整数，表示1号点到n号点的最短距离。
如果路径不存在，则输出-1。


数据范围

1<=n<=500,
1<=m<=10^5,
图中涉及边长均不超过10000。

*/
const int N = 500 + 10;
int n, m;
int g[N][N];
int dist[N]; // 从源点到目标点的距离
bool st[N];  // 是否已经是最短路径

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n; i++)
    {
        int t = -1;

        // 找到没有确定，且距离最近的点，如果用堆实现 O(1)
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        st[t] = true;

        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}

int main()
{
    FREOPEN
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // 可能存在重边
        g[a][b] = min(g[a][b], c);
    }

    int t = dijkstra();

    cout << t;

    CHECK
    return 0;
}
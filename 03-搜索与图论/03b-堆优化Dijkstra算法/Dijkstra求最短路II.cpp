#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <localCheck.h>
#include <queue>
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
const int N = 1e5 + 10;
int n, m;
// int g[N][N];

// w 权重
int h[N], e[N], w[N], ne[N], idx;
int dist[N]; // 从源点到目标点的距离
bool st[N];  // 是否已经是最短路径

// 用堆保存，编号和距离之间的关系
typedef pair<int, int> PII;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;

    // 距离是 0 ，编号是 1；
    heap.push({0, 1});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        // 会有冗余，过滤掉就好了
        if (st[ver])
            continue;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}

int main()
{
    FREOPEN
    cin >> n >> m;
    memset(h, -1, sizeof h);

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // 可能存在重边
        add(a, b, c);
    }

    int t = dijkstra();

    cout << t;

    CHECK
    return 0;
}
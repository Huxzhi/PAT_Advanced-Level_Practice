#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <localCheck.h>
#include <queue>
using namespace std;

/*
给定一个n个点m条边的有向图，图中可能存在重边和自环，边权可能为负数。

请你求出从1号点到n号点的最多经过k条边的最短距离,如果无法从1号点走到n号点,输出impossible。

注意：图中可能 存在负权回路。


输入格式
第一行包含三个整数n, m, k。
接下来m行，每行包含三个整数x, y, z,表示点x和点y之间存在一条有向边,边长为z。


输出格式
输出一个整数，表示从1号点到n号点的最多经过k条边的最短距离。
如果不存在满足条件的路径，则输出“impossible”。


数据范围
 1<n, k<500,
 1<m< 10000,
任意边长的绝对值不超过10000


*/
const int N = 500 + 10, M = 10000 + 10;
int n, m, k;

int dist[N], backup[N];

struct Edge
{
    int a, b, w;
} edges[M];

int bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; i++)
    {
        // 会发生串联，解决，只用上一次的迭代结果
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j++)
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            // 使用上一次的迭代结果
            dist[b] = min(dist[b], backup[a] + w);
        }
    }

    //  两个从源点不能到达的边可能会发生更新，但是最多减少 结点的最大值 * 结点的个数(本题为 1000 * 500 )，所以。。。
    if (dist[n] > 0x3f3f3f3f / 2)
        return -1;
    return dist[n];
}

int main()
{
    FREOPEN
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
    }

    int t = bellman_ford();

    if (t == -1)
        cout << "impossible";
    else
        cout << t;

    CHECK;
    return 0;
}
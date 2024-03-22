#include <iostream>
#include <cstring>
#include <localCheck.h>
#include <queue>
#include <algorithm>
using namespace std;

/*
给定一个n个点m条边的无向图，图中可能存在重边和自环，边权可能为负数。

求最小生成树的树边权重之和,如果最小生成树不存在则输出impossible。

给定一张边带权的无向图G=(V， E)，其中V表示图中点的集合，E表示图中边的 集合，n=|VI，m=|E|。

由V中的全部n个顶点和E中n-1条边构成的无向连通子图被称为G的一棵生成树，其中边的权值之和最小的生成树
被称为无向图G的最小生成树。


输入格式
第一行包含两个整数n和m。
接下来m行，每行包含三个整数u，v,w，表示点u和点v之间存在一条权值为w的边。


输出格式
共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出


数据范围

1<n<500,
1<m<10^5,
图中涉及边的边权的绝对值均不超过10000。

*/
const int N = 500 + 10, INF = 0x3f3f3f3f;
int n, m;
int g[N][N];
int dist[N]; // 点到集合的距离
bool st[N];

int prim()
{
    // 先假设全部都不连通
    memset(dist, 0x3f, sizeof dist);

    int res = 0;

    // 更新 n 个 点
    for (int i = 0; i < n; i++)
    {
        int t = -1;

        // 找到集合外的，且距离最近的一点
        for (int j = 1; j <= n; j++)
            // 总要找到一个点，但是不知道这个点的大小，先默认第一个比较的为最小值
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        // 即 图是不连通的
        if (i && dist[t] == INF)
            return INF;

        // 除了第一个点
        if (i)
            res += dist[t];

        // todo 注意 如果有负权自环，会出现问题，所以要先保存值，再更新
        // 更新 t 点到 集合的距离，目前集合外的点都是 +∞
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);

        st[t] = true;
    }
    return res;
}

int main()
{

    FREOPEN
    cin >> n >> m;

    memset(g, 0x3f, sizeof g);

    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;

        g[a][b] = min(g[a][b], w);
    }

    int t = prim();

    if (t == INF)
        cout << "impossible" << endl;
    else
        cout << t << endl;

    CHECK;
    return 0;
}
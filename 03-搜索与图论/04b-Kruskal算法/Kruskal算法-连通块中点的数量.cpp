#include <iostream>
#include <cstring>
#include <localCheck.h>
#include <queue>
#include <algorithm>
using namespace std;

/*
给定一个n个点m条边的无向图，图中可能存在重边和自环，边权可能为负数。

求最小生成树的树边权重之和,如果最小生成树不存在则输出impossible


数据范围

1<n<500,
1<m<10^5,
图中涉及边的边权的绝对值均不超过10000。

*/
const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int n, m;
int p[N]; // 保存 并查集

struct Edge
{
    int a, b, w;

    bool operator<(const Edge &W) const
    {
        return w < W.w;
    }
} edges[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]); // 顺带路径优化
    return p[x];
}

int Kruskal()
{
    //  对 边进行排序
    sort(edges, edges + m);

    // 并查集 初始化
    for (int i = 1; i <= m; i++)
        p[i] = i;

    // 添加最小边到集合里面
    int res = 0, cnt = 0;
    // 从小到大依次枚举每条边
    for (int i = 0; i < m; i++)
    {

        // 一条边的 两个顶点 和 权重
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);
        if (a != b)
        {
            p[a] = b; // 合并
            res += w;
            cnt++; // 统计边数
        }
    }

    if (cnt < n - 1)
        return -1;

    return res;
}

int main()
{

    FREOPEN
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;

        edges[i] = {a, b, w};
    }

    int t = Kruskal();

    if (t == -1)
        cout << "impossible" << endl;
    else
        cout << t << endl;

    CHECK;
    return 0;
}
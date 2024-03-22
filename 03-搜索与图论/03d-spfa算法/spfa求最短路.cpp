#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <localCheck.h>
#include <queue>
using namespace std;

/*
给定一个n个点m条边的有向图，图中可能存在重边和自环，边权可能为负数。
请你求出1号点到n号点的最短距离,如果无法从1号点走到n号点,则输出impossible。

数据保证不存在负权回路。


输入格式

第一行包含整数n和m。
接下来m行每行包含三个整数x, y, z,表示点x和点y之间存在一条有向边,边长为z。


输出格式

输出一个整数,表示1号点到n号点的最短距离。
如果路径不存在，则输出"impossible"。


数据范围

 1<n,m<10^5,
图中涉及边长绝对值均不超过10000
*/
const int N = 1e5 + 10;
int n, m;

int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        // 更新所有邻边
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                // 添加到更新队列里
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
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
        add(a, b, c);
    }

    int t = spfa();

    if (t == -1)
        cout << "impossible";
    else
        cout << t;

    CHECK;
    return 0;
}
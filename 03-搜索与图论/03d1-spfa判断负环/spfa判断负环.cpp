#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <localCheck.h>
#include <queue>
using namespace std;

/*
给定一个n个点m条边的有向图，图中可能存在重边和自环，**边权可能为负数**
请你判断图中是否存在负权回路。


输入格式

第一行包含整数n和m。
接下来m行每行包含三个整数x, y, z,表示点x和点y之间存在一条有向边,边长为z。


输出格式

如果图中存在负权回路，则输出“Yes”，否则输出“No”。

数据范围

1<n<2000,
1<m< 10000,
图中涉及边长绝对值均不超过10000。
*/
const int N = 1e5 + 10;
int n, m;

int h[N], w[N], e[N], ne[N], idx;
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa()
{
    // memset(dist, 0x3f, sizeof dist);
    // dist[1] = 0;

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
        st[i] = true;
    }

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
                cnt[j] = cnt[t] + 1;

                if (cnt[j] >= n)
                    return true;

                // 添加到更新队列里
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
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

    if (spfa())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    CHECK;
    return 0;
}
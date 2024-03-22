#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <localCheck.h>

using namespace std;

/*
给定一个n个点m条边的无向图，图中可能存在重边和自环。
请你判断这个图是否是二分图。
输入格式
第一行包含两个整数n和m。
接下来m行,每行包含两个整数u和v,表示虎u和点v之间存在一条边。


输出格式

如果给定图是二分图，则输出“Yes"，否则输出"No"。


数据范围

1<n,m< 10^5
*/

const int N = 1e5 + 10, M = N * 2;
int n, m;
// 结点队列
int h[N];

// 静态链表，效率最高，比 vector 高
int e[M], ne[M], idx;

int color[N];

void add(int a, int b)
{
    // 头插法
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 以 u 为根的子树中点的数量
bool dfs(int u, int c)
{
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!color[j]) // 没有染色
        {
            if (!dfs(j, 3 - c)) // 染色失败
                return false;
        }
        else if (color[j] == c) // 染色发生冲突
            return false;
    }

    return true;
}

int main()
{

    FREOPEN
    cin >> n >> m;
    memset(h, -1, sizeof h);

    // 树的 结点个数= 边数+1
    while (m--)

    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    bool flag = true;
    for (int i = 1; i <= n; i++)
        if (!color[i])
        {
            if (!dfs(i, 1)) // 染色
            {
                flag = false;
                break;
            }
        }

    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    CHECK
    return 0;
}
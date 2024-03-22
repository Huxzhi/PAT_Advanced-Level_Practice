#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <localCheck.h>

using namespace std;

/*
给定一个二分图，其中左半部包含n1个点（编号1~n1），右半部包含n2个点（编号1~n2），二分图共包含m条
边。

数据保证任意一条边的两个端点都不可能在同一部分中。

请你求出二分图的最大匹配数。

给定一个二分图G，在G的一个子图M中， M的边集(E)中的任意两条边都不依附于同一个顶点，则称M是一个匹配。

所有匹配中包含边数最多的一组匹配被称为二分图的最大匹配,其边数即为最大匹配数。


输入格式
第一行包含两个整数n和m。
接下来m行,每行包含两个整数u和v,表示左边部点集中的点u和右半部点集中的点v之间存在一条边。


输出格式
输出一个整数,表示二分图的最大匹配数。
数据范围

1 < n1, n2 < 500,
1 < v <= n_1,
1 < v <= n_2,
1 < m < 10^5

*/

const int N = 1e5 + 10, M = N * 2;
int n1, n2, m;
// 结点队列
int h[N];

// 静态链表，效率最高，比 vector 高
int e[M], ne[M], idx;

int match[N]; // 右边对应的点
bool st[N];   // 判重
void add(int a, int b)
{
    // 头插法
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool find(int x)
{
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            st[j] = true;
            // 女生没有匹配男生，或者女生匹配的男生有下家
            if (match[j] == 0 || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
// 以 u 为根的子树中点的数量
int Hungarian()
{
    int res = 0;
    for (int i = 0; i <= n1; i++)
    {
        memset(st, false, sizeof st);
        if (find(i))
            res++;
    }

    return res;
}

int main()
{

    FREOPEN
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof h);

    // 树的 结点个数= 边数+1
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b); // 只需 单向即可
    }

    cout << Hungarian() << endl;
    CHECK
    return 0;
}
/*
给定一个n*m的二维整数数组，用来表示一个迷宫，数组中只包含0或1，其中0表示可以走的路，1表示不可通过的墙壁。
最初，有一个人位于左上角(1，1)处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。
请问，该人从左上角移动至右下角(n, m)处，至少需要移动多少次。
数据保证(1，1)处和(n, m)处的数字为0，且一定至少存在一条通路。


input

5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0


*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;
const int N = 110;

int n, m;
int g[N][N]; // 图
int d[N][N]; // 存储距离
PII q[N * N], prevs[N][N];

int bfs()
{
    int hh = 0, tt = 0; // 自己实现一个队列
    q[0] = {0, 0};
    memset(d, -1, sizeof d); // 没有走过
    d[0][0] = 0;             // 表示走过了

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; // 用向量表示4个方向

    while (hh <= tt) // 队列不空
    {
        auto t = q[hh++]; // 取出队头元素

        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];

            // 在边界内，且 可以通过，还 没有走过
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                // 保存路径
                prevs[x][y] = t;
                q[++tt] = {x, y};
            }
        }
    }

    int x = n - 1, y = m - 1;
    while (x || y)
    {
        cout << x << ' ' << y << endl;
        auto t = prevs[x][y];
        x = t.first, y = t.second;
    }

    // 返回 右下角的距离
    return d[n - 1][m - 1];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    cout << bfs() << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << d[i][j] << " ";
        cout << endl;
    }
    return 0;
}
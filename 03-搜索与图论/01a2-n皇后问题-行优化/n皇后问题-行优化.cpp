/*
n-皇后问题是指将 n个皇后放在 nen 的国际象棋棋盘上,使得皇后不能相互攻击到,

即任意两个皇后都不能处于同一行、同一列或同—斜线上。

输出格式

每个解决方案占n行，每行输出一个长度为n的字符串，用来表示完整的棋盘状态。
其中"."表示某一个位置的方格状态为空，"Q"表示某一个位置的方格上摆着皇后。置
每个方案输出完成后，输出一个空行。


思路

也就是全排列的问题

*/
#include <iostream>
using namespace std;
const int N = 10;
char g[N][N];
int n;
int num;
int path[N]; // 保存输出的数据

// 列 主对角线，副对角线
bool col[N], dg[2 * N - 1], udg[2 * N - 1]; // 保存那些数字用过了

void dfs(int u)
{
    // u的值 表示处于第几 层
    if (u == n) // 判断叶子结点
    {
        cout << ++num << ": " << endl;
        for (int i = 0; i < n; i++)
            puts(g[i]);
        puts("");
        // 第一反应，这里也可以回复现场，不过，在进入下一层的后面也可以恢复现场
        return;
    }
    for (int i = 0; i < n; i++)
        // 主对角线 y = x + b , b = y -x ,副对角线同理
        if (!col[i] && !dg[u + i] && !udg[n - u + i])
        {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1); // 进入下一层
                        // 回复现场
            g[u][i] = '.';
            col[i] = dg[u + i] = udg[n - u + i] = false;
        }
}

// 全排列 顺序！
int main()
{
    // cin >> n;
    n = 4;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';
    dfs(0);
}

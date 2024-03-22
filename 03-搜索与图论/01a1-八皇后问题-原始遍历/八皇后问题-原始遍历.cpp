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

// 行，列，主对角线，副对角线
bool row[N], col[N], dg[2 * N - 1], udg[2 * N - 1]; // 保存那些数字用过了

// 从左下角开始搜，记录几个皇后，每个格子都有两个分支，放和不放
void dfs(int x, int y, int s)
{
    // 回到下一行的开始
    if (y == n)
        y = 0, x++;

    if (x == n)
    {
        if (s == n) // 满足条件
        {
            cout << ++num << ": " << endl;
            for (int i = 0; i < n; i++)
                puts(g[i]);
        }
        return;
    }

    // 不放皇后
    dfs(x, y + 1, s);

    // 放皇后
    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
    {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;

        // 进入下一层
        dfs(x, y + 1, s + 1);

        // 回复现场
        g[x][y] = '.';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
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

    dfs(0, 0, 0);
}

// 给定一个整数n，将数字1~n排成一排，将会有很多种排列方法。
// 现在，请你按照字典序将所有的排列方法输出。
// 输入格式
// 共一行，包含一个整数n。
// 输出格式
// 按字典序输出所有排列方案,每个方案占一行。
// 数据范围
//  1<n<7
#include <cstring>
#include <fstream>
#include <iostream>
#include <localCheck.h>
using namespace std;
const int N = 10;

int n;

int path[N]; // 保存输出的数据
bool st[N];  // 保存那些数字用过了

void dfs(int u)
{
    // u的值 表示处于第几层
    if (u == n) // 判断叶子结点
    {
        for (int i = 0; i < n; i++)
            printf("%d ", path[i]);
        puts("");
        // 第一反应，这里也可以回复现场，不过，在进入下一层的后面也可以恢复现场
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!st[i])
        {
            path[u] = i;
            st[i] = true;
            dfs(u + 1); // 进入下一层
            // 回复现场
            // path[u]=0;
            st[i] = false;
        }
}

// 全排列 顺序！
int main()
{
    FREOPEN
    cin >> n;
    dfs(0);
    CHECK
    return 0;
}

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#define LOCAL
using namespace std;

/*
给定一颗树，树中包含n个结点（编号1~n）和n-1条无向边。
请你找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。

重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。

输入格式
第一行包含整数n,表示树的结点数。
接下来n-1行，每行包含两个整数a和b，表示点a和点b之前存在一条边。

输出格式
输出一个整数m，表示重心的所有的子树中最大的子树的结点数目。
数据范围
 1<n<10^5

*/

const int N = 1e5 + 10, M = N * 2;
int n, m;
// 结点队列
int h[N];
bool st[N]; // 保存遍历过的点

int ans = N;

// 静态链表，效率最高，比 vector 高
int e[M], ne[M], idx;

void add(int a, int b)
{
    // 头插法
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 以 u 为根的子树中点的数量
int dfs(int u)
{
    st[u] = true; // 标记一下，已经被搜过了

    int sum = 1, res = 0; // res 表示删除该结点后，子树的连通结点的最大值
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }

    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("temp_result.txt", "w", stdout);
#endif

    cin >> n;
    memset(h, -1, sizeof h);

    // 树的 结点个数= 边数+1
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(1); // 从第一个开始遍历

    cout << ans << endl;

    // 关闭重定向的文件流
    fclose(stdin);
    fclose(stdout);

    // 重新打开临时输出文件和期望的输出文件进行比较
    ifstream tempOutput("temp_result.txt");
    ifstream expectedOutput("output.txt");

    if (!tempOutput.is_open() || !expectedOutput.is_open())
    {
        cerr << "无法打开文件!" << endl;
        return -1;
    }

    string computedSum, expectedSum;
    tempOutput >> computedSum;
    expectedOutput >> expectedSum;

    if (computedSum == expectedSum)
    {
        cerr << "结果一致。" << endl;
    }
    else
    {
        cerr << "结果不一致。" << endl;
    }

    tempOutput.close();
    expectedOutput.close();
    return 0;
}
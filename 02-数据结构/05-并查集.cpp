
#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int n, m;
int p[N];

// 返回 x 的祖宗结点 + 路径优化
int find(int x)
{
    if (p[x] != x)
        // 妙啊
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n, m;

    for (int i = 1; i <= n; i++)
        p[i] = i;

    while (m--)
    {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);

        if (op[0] == 'M')
            p[find(a)] = find(b);
        else
        {
            if (find(a) == find(b))
                puts("Yes");
        }
    }
}

/*
4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4

*/
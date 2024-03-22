
#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int n, m;
int p[N];

// 保证只有根结点的信息是有效的
int sizes[N];

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
    {
        p[i] = i;
        sizes[i] = 1;
    }

    while (m--)
    {
        char op[5];
        int a, b;
        scanf("%s", op);

        if (op[0] == 'C')
        {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b))
                continue;
            sizes[find(b)] += sizes[find(a)];
            p[find(a)] = find(b);
        }
        else if (op[1] == '1')
        {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b))
                puts("Yes");
            else
                puts("No");
        }
        else
        {
            scanf("%d", &a);
            printf("%d\n", sizes[find(a)]);
        }
    }
}

/*


*/
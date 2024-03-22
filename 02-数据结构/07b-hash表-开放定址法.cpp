
#include <cstring>
#include <iostream>
using namespace std;

//  不在数据集里面的数据，表示 为空
const int null = 0x3f3f3f3f;
const int N = 2e5 + 3;

int getPrimeNumber(int x)
{
    for (int i = x;; i++)
    {
        bool flag = true;
        for (int j = 2; j * j <= i; j++)
            if (i % j == 0)
            {
                flag = false;
                break;
            }
        if (flag)
        {
            return i;
        }
    }
}

// 保存 各个的头指针
int h[N], idx;

int find(int x)
{
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x)
    {
        k++;
        // 在回到起点查找
        if (k == N)
            k = 0;
    }
    return k;
}

int main()
{
    int n;
    cin >> n;

    // 按字节赋值
    memset(h, 0x3f, sizeof h);

    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        int k = find(x);
        if (*op == 'I')
            h[k] = x;
        else
        {
            if (find(x))
                puts("Yes");
            else
                puts("No");
        }
    }
}
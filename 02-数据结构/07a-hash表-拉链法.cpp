
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5 + 3;

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
int h[N], e[N], ne[N], idx;

void insert(int x)
{
    int k = (x % N + N) % N; // 确保 k 为 正整数

    e[idx] = x, ne[idx] = h[k], h[k] = idx++; // 静态链表，头插法
}

bool find(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;

    return false;
}

int main()
{
    // cout << getPrimeNumber(1e5);
    int n;
    cin >> n;

    // 数组按字节赋值 0 和 -1 ，不会出错
    memset(h, -1, sizeof h);
    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if (*op == 'I')
            insert(x);
        else
        {
            if (find(x))
                puts("Yes");
            else
                puts("No");
        }
    }
}
#include <iostream>
using namespace std;

// 给定一个长度为N的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出-1。
// 解题： 用栈 保存 比他小的数
const int N = 1e6 + 10;

int stk[N], tt;

void push(int x)
{
    stk[++tt] = x;
}

int pop()
{
    return stk[tt--];
}

bool isEmpty()
{
    return tt <= 0;
}

int get()
{
    return stk[tt];
}

int main()
{
    // 优化读入 当输入和输出比较大的时候，用 scanf 和 printf ，比 cin cout 快 10倍
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        // 栈不为空，且内部的值都小于x，满足单调栈
        while (!isEmpty() && get() >= x)
            pop();
        if (!isEmpty())
            cout << get() << ' ';
        else
            cout << -1 << ' ';

        push(x);
    }
}

/*
5
3 4 2 7 5

*/
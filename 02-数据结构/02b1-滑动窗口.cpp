#include <iostream>
using namespace std;

/*
输出滑动窗口内的最大值 和 最小值
*/

const int N = 1e6 + 10;

int a[N], q[N], hh, tt = -1;

void push(int x)
{
    q[++tt] = x;
}

int pop()
{
    return q[hh++];
}

int pop_tail()
{
    return q[tt--];
}

bool isEmpty()
{
    return hh > tt;
}

// 取出队头元素
int get_head()
{
    return q[hh];
}

int get_tail()
{
    return q[tt];
}

int main()
{
    ios::sync_with_stdio(false);
    int n, k = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        // 判断队头是否已经滑出窗口, 只需要一次
        if (!isEmpty() && i - k + 1 > get_head())
            pop();
        // 构造单调队列,队列保存的是下标
        while (!isEmpty() && a[get_tail()] >= a[i])
            pop_tail();
        // 放在前面，是因为 上面的while 可能会清空 队列， a[i] 已经参加比较了
        push(i);
        // for (int j = hh; j <= tt; j++)
        //     cout << a[q[j]] << ' ';
        // cout << endl;

        if (i >= k - 1)
            cout << a[get_head()] << ' ';
    }
    puts("");

    hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        // 判断队头是否已经滑出窗口, 只需要一次
        if (!isEmpty() && i - k + 1 > get_head())
            pop();
        // 构造单调队列,队列保存的是下标
        while (!isEmpty() && a[get_tail()] <= a[i])
            pop_tail();
        // 放在前面，是因为 上面的while 可能会清空 队列， a[i] 已经参加比较了
        push(i);

        if (i >= k - 1)
            cout << a[get_head()] << ' ';
    }

    return 0;
}

/*
8 3
1 3 -1 -3 5 3 6 7

*/
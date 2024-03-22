

#include <iostream>
using namespace std;

/**
 *
实现一个单链表，链表初始为空，支持三种操作：
(1) 向链表头插入一个数；
(2) 删除第 k 个插入的数后面的数；
(3) 在第 k 个插入的数后插入一个数
现在要对该链表进行M次操作，进行完所有操作后，从头到尾输出整个链表。

 *
 */

const int N = 1e6 + 10;

// head 头结点的下标
// e[i] 表示节点 i 的值
// ne[i] 表示节点 i的 next 指针是多少
// idx 存储当前已经用到了哪个点
int head, e[N], ne[N], idx;

void init()
{
    head = -1;
    idx = 0;
}
// 插入到头结点的后面
void add_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

// 插入到 k 下标的后面
void add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}
// 将下标是 k 的点后面的点删除
void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    int m;
    cin >> m;

    init();
    while (m--)
    {
        int k, x;
        char op;

        cin >> op;
        if (op == 'H')
        {
            cin >> x;
            add_head(x);
        }
        else if (op == 'D')
        {
            cin >> k;
            if (!k)
                head = ne[head];
            remove(k - 1);
        }
        else
        {
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i])
    {
        cout << e[i] << ' ';
    }
    cout << endl;
    return 0;
}

/*
10
H 9
Ι 1 1
D 1
D 0
Н 6
I 3 6
Ι 4 5
I 4 5
I 3 4
D 6


*/
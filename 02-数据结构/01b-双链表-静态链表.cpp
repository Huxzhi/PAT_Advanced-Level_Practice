

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
// l,r 表示节点 i 的 左右 指针是多少
// idx 存储当前已经用到了哪个点
int head, e[N], l[N], r[N], idx;

// 偷个懒，0为头结点，1为尾结点，从2开始
void init()
{
    head = -1;
    idx = 2;
}

// 插入到 k 下标的后面，每次插入会idx++， 所以k-2 为第 i次插入
// add(l[k],x) 第k的左边
void add(int k, int x)
{
    k = k - 2;
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx; // 和下面一个 顺序不能反
    r[k] = idx;
    idx++;
}
// 删除第 k 个点
void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
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
            remove(k - 1);
        }
        else
        {
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = r[i])
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
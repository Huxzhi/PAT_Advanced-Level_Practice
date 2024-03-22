/**

维护一个字符串集合，支持两种操作：

1. "I x" 向集合中插入一个字符串 x;
2. "Q x" 询问一个字符串在集合中出现了多少次。

共有N个操作，输入的字符串总长度不超过 10^5，字符串仅包含小写英文字母。

 */

#include <iostream>
using namespace std;

// 字符的最大长度
const int N = 1e5 + 10;

char str[N];

/* 静态链表的思路，构成树结构
x
son[x][0] 为 x的后继字母 a 的指针，指针每用一个+1
cnt[x] 保存对应指针的 个数
*/
int son[N][26];

int cnt[N];

// 下标是0的点，既是根结点，又是空结点， 和cnt的下标关联
int idx;

void insert(char str[])
{
    int p = 0; // p表示指针
    for (int i = 0; i < str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx; // idx 表示指针，当路径发生变化时++，没有后续字母，或者后续为没有保存的字母
        p = son[p][u];
    }

    cnt[p]++;
}

int query(char str[])
{
    int p = 0;
    for (int i = 0; i < str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }

    return cnt[p];
}

int main()
{

    int n;
    scanf("%d", &n);
    int num = n;
    while (n--)
    {
        char op[2];
        scanf("%s%s", op, str);
        if (op[0] == 'I')
            insert(str);
        else
            printf("%d\n", query(str));
    }

    // 展示
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
            printf("%d ", son[i][j]);
        puts("");
    }
    puts("");
    for (int j = 0; j < 26; j++)
        printf("%d ", cnt[j]);
    return 0;
}
/*
4
I abcdef
I abdef
I aced
I abc
*/
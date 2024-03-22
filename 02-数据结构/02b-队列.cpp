#include <iostream>
using namespace std;
const int N = 1e6 + 10;

int q[N], hh, tt = -1;

void push(int x)
{
    q[++tt] = x;
}

int pop()
{
    return q[hh++];
}

bool isEmpty()
{
    return hh > tt;
}

// 取出队头元素
int get()
{
    return q[hh];
}

int main()
{
}
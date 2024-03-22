#include <iostream>
using namespace std;
const int N = 1e6 + 10;

int stk[N], tt = 0;

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
}
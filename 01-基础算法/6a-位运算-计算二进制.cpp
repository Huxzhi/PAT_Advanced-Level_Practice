#include <iostream>
using namespace std;
int main()
{
    int n = 10;
    // 逆序输出
    for (int k = 3; k >= 0; k--)
    {
        cout << (n >> k & 1);
    }
}
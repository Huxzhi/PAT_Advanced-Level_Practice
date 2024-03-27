/*

棋盘分割成若干个1*2的的长方形,有多少种方案。
例如当N=2, M=4时,共有5种方案。当N=2, M=3时,共有3种方案。
如下图所示：

输入格式
输入包含多组测试用例。
每组测试用例占一行，包含两个整数N和M。
当输入用例N=0，M=0时，表示输入终止，且该用例无需处理。

输出格式
每个测试用例输出一个结果，每个结果占一行。

数据范围
1<N, M<11

*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <localCheck.h>
using namespace std;

const int N = 12, M = 1 << N;

int n, m;

bool st[M]; // 状态是不是合法

long long f[N][M];
int main()
{
  FREOPEN

  while (cin >> n >> m, n || m)
  {
    memset(f, 0, sizeof f);
    for (int i = 0; i < 1 << n; i++)
    {
      st[i] = true;
      int cnt = 0; // 当前个数
      // 横放的方块 不能是奇数个
      for (int j = 0; j < n; j++)
        if (i >> j & 1)
        {
          if (cnt & 1)
            st[i] = false;
          cnt = 0;
        }
        else
          cnt++;
      if (cnt & 1)
        st[i] = false;
    }
    f[0][0] = 1;
    for (int i = 1; i <= m; i++)
      for (int j = 0; j < 1 << n; j++)
        for (int k = 0; k < 1 << n; k++)
          if ((j & k) == 0 && st[j | k])
            f[i][j] += f[i - 1][k];

    cout << f[m][0] << endl;
  }

  CHECK
  return 0;
}
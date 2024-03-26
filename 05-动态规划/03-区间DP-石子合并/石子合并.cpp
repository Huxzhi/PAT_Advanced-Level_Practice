/*
每堆石子有一定的质量,可以用一个整数来描述,现在要将这N堆石子合并成为一堆。
每次只能合并相邻的两堆，合并的代价为这两堆石子的质量之和，合并后与这两堆石子相邻的石子将和新堆相
邻，合并时由于选择的顺序不同,合并的总代价也不相同。
例如有4堆石子分别为 1352，我们可以先合并1、2堆，代价为4，得到452，又合并 1，2堆，代价为9，得到
92，再合并得到11，总代价为4+9+11=24;
如果第二步是先合并2, 3堆,则代价为7,得到4 7,最后一次合并代价为11,总代价为4+7+11=22。
问题是：找出一种合理的方法，使总的代价最小，输出最小代价。
输入格式
第一行一个数N表示石子的堆数N。
第二行N个数,表示每堆石子的质量(均不超过1000)。
输出格式
输出一个整数，表示最小代价。
数据范围
 1<N< 300

*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <localCheck.h>
using namespace std;

const int N = 310, INF = 1e9;

int n, m;

int s[N]; // 前缀和
// 保存路径最大值
int f[N][N];
int main()
{
  FREOPEN
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> s[i];

  // 求前缀和
  for (int i = 1; i <= n; i++)
    s[i] += s[i - 1];

  // 起点 和 长度
  for (int len = 2; len <= n; len++)
    for (int i = 1; i + len - 1 <= n; i++)
    {
      int l = i, r = i + len - 1;
      f[l][r] = 1e8; // 初始为较大的数
      for (int k = l; k < r; k++)
      {
        f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
      }
    }
  cout << f[1][n] << endl;
  CHECK
  return 0;
}
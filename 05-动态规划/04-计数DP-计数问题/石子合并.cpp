/*
给定两个整数 a 和 b，求 a 和 b 之间的所有数字中0~9的出现次数。
例如，a=1024，b=1032，则 a 和 b 之间共有9个数如下：
1024 1025 1026 1027 1028 1029 1030 1031 1032
其中‘0’出现10次，‘1’出现10次，‘2’出现7次，‘3’出现3次等等….

输入格式

输入包含多组测试数据。
每组测试数据占一行,包含两个整数 a 和 b。
当读入一行为0 0时，表示输入终止，且该行不作处理。

输出格式

每组数据输出一个结果，每个结果占一行。
每个结果包含十个用空格隔开的数字,第一个数字表示0'出现的次数，第二个数字表示1'出现的次数,以此类
推。

数据范围

0<a,b<1e8
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
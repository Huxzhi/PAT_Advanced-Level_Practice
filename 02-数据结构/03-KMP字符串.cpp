#include <iostream>
using namespace std;

const int N = 10010, M = 100010;
int p[N], s[M], ne[N];
int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> s[i];

    // 求 next 过程，即 最大公共前后缀
    // i从 1 开始， 但 next[1] = 0
    for (int i = 2, j = 0; i < n; i++)
    {
        while (j && p[i] != p[j + 1])
            // 不匹配就会退一步
            j = ne[j];
        if (p[i] == p[j + 1])
            /**      ⬇ ++i
             * A B C A B C D
             *       A B C A B C D
             *      ⬆ ++j
             */
            j++;
        ne[i] = j;
    }

    // kmp 匹配过程
    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && s[i] != p[j + 1])
            // 不能匹配，就退一步
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == n)
        {
            // 匹配成功
            printf("%d ", i - n);
            j = ne[j]; // 进行下一步的匹配
        }
    }
}

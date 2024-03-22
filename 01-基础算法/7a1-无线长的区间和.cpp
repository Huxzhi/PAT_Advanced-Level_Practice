#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
const int N = 300010;

int n, m;
int a[N], s[N]; // s是前缀和

vector<int> alls;       // 存储所有待离散化的值
vector<PII> add, query; // 插入操作，查询操作，维护一个映射关系

// 二分求出x对应的离散化的值
int find(int x) // 找到第一个大于等于x的位置
{

    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }

    return r + 1; // 映射到 1,2...n， 与题目有关
}

int find2(int x)
{
    return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});

        alls.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;

        query.push_back({l, r});

        alls.push_back(l);
        alls.push_back(r);
    }
    // 去重
    sort(alls.begin(), alls.end());                           // 将所有值排序
    alls.erase(unique(alls.begin(), alls.end()), alls.end()); // 去掉重复元素

    // 处理插入
    for (auto item : add)
    {
        int x = find(item.first);
        a[x] += item.second;
    }

    // 预处理前缀和
    for (int i = 1; i <= alls.size(); i++)
    {
        s[i] = s[i - 1] + a[i];
    }

    // 处理查询
    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}
/*
3 3
1 2
3 6
7 5
1 3
4 6
7 8

*/
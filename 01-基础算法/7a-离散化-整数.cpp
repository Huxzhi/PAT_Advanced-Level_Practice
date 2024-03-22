#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 二分求出x对应的离散化的值
int find(int x) // 找到第一个大于等于x的位置
{

    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }

    return r + 1; // 映射到 1,2...n， 与题目有关
}

vector<int> alls; // 存储所有待离散化的值

int main()
{

    sort(alls.begin(), alls.end()); // 将所有值排序
    // unique() 会排序，重复的元素排在最后面，
    // erase()  删除指定区间的元素
    alls.erase(unique(alls.begin(), alls.end()), alls.end()); // 去掉重复元素
}
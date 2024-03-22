#include <iostream>
#include <unordered_set>
using namespace std;

/**
 * 优化
 *
 */

string s1, s2;

// bool exists(char c)
// {
//     for (auto a : s2)
//         if (a == c)
//             return true;
//     return false;
// }

int main()
{
    getline(cin, s1);
    getline(cin, s2);

    unordered_set<char> hash; // 定义哈希表
    for (auto c : s2)
        hash.insert(c); // 将s2 中的字符 插入哈希表

    string res;
    for (auto c : s1)
        if (!hash.count(c)) // 统计 字符的个数
            res += c;       // O（1）
    cout << res << endl;
    return 0;
}
#include <iostream>
#include <unordered_map>
using namespace std;

bool check(char s)
{
    if (s >= 'a' && s <= 'z' || s >= 'A' && s <= 'Z' || s >= '0' && s <= '9')
        return true;
    return false;
}

int main()
{
    string str;
    getline(cin, str);
    unordered_map<string, int> hash;

    for (int i = 0; i < str.size(); i++)
    {

        if (check(str[i]))
        {
            string word;
            int j = i; // 双指针的用法

            while (j < str.size() && check(str[j]))
                word += tolower(str[j++]);
            hash[word]++;
            i = j;
        }
        else
        {
        }
    }

    string word;
    int cnt = -1;
    for (auto item : hash)
        if (item.second > cnt || item.second == cnt && item.first < word)
        {
            word = item.first;
            cnt = item.second;
        }
    cout << word << ' ' << cnt << endl;
}
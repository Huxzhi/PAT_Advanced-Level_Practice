#include <iostream>
using namespace std;
int main()
{
    string n;
    cin >> n;
    int s = 0;
    for (auto c : n)
        s += (c - '0');

    string str = to_string(s);
    // cout << str;
    char word[10][10] = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
    };
    cout << word[str[0] - '0'];
    for (int i = 1; i < str.size(); i++)
        cout << ' ' << word[str[i] - '0'];
    return 0;
}
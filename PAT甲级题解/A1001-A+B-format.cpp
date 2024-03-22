#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    long long a, b;
    string d;
    cin >> a >> b;

    d = to_string(a + b);
    int len = d.length();
    for (int i = 0; i < len; i++)

    {
        cout << d[i];
        if (d[i] == '-')
            continue;
        if ((i + 1) % 3 == 0 && i != len - 1)
            cout << ',';
    }
    return 0;
}
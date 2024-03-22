#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 大数 除 小数

// C = A / b
vector<int> div(vector<int> &A, int &b, int &r)
{

    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];

        C.push_back(r / b);
        r %= b;
    }

    reverse(C.begin(), C.end());

    while (C.size() > 1 && C.back() == 0) // 去掉 前导0
        C.pop_back();

    return C;
}

int main()
{
    string a;
    int b;
    vector<int> A, B;

    cin >> a >> b; // a = "123456"

    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0'); // A = [6, 5, 4, 3, 2, 1]
    int r;
    auto C = div(A, b, r);

    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << endl
         << r << endl;
    return 0;
}
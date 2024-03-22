#include <iostream>
#include <vector>
using namespace std;

// 大数 乘 小数

// C = A * b
vector<int> mul(vector<int> &A, int &b)
{
    vector<int> C;
    int t = 0; // 进位，若 b < 100 ，则 t < 900
    for (int i = 0; i < A.size() || t; i++)
    {
        if (i < A.size())
            t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
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

    auto C = mul(A, b);

    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// A >= B
bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size())
        return A.size() > B.size();
    for (int i = A.size() - 1; i > 0; i--)
        if (A[i] != B[i])
        {
            return A[i] > B[i];
        }
    return true;
}

// C = A -B
vector<int> sub(vector<int> &A, vector<int> &B)
{
    if (!cmp(A, B))
        return sub(B, A);
    vector<int> C;

    int t = 0; // 借位
    for (int i = 0; i < A.size(); i++)
    {

        t += A[i];

        if (i < B.size())
            t -= B[i];

        C.push_back((t + 10) % 10);

        if (t < 0)
            t = -1;
        else
            t = 0;
    }

    while (C.size() > 1 && C.back() == 0) // 去掉 前导0
        C.pop_back();

    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;

    cin >> a >> b; // a = "123456"

    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0'); // A = [6, 5, 4, 3, 2, 1]
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');
    auto C = sub(A, B);

    if (!cmp(A, B))
        cout << '-';

    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    return 0;
}
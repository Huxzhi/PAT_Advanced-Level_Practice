#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
int n;
vector<PII> segs;

void merge(vector<PII> &segs)
{
    vector<PII> res;

    sort(segs.begin(), segs.end());
    int st = -2e9, ed = -2e9;
    for (auto seg : segs)

        if (ed < seg.first)
        {
            // 不是同一个区间
            if (st != -2e9) // 防止数组为空
                res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else // 合并区间
            ed = max(ed, seg.second);

    if (st != -2e9)
        res.push_back({st, ed});

    segs = res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    merge(segs);
    cout << segs.size() << endl;
    return 0;
}

/*
5
1 2
2 4
5 6
7 8
7 9

result 3
*/
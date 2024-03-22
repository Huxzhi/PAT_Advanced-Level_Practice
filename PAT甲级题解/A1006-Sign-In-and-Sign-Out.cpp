#include <iostream>
using namespace std;

/*
为啥我的其中一个测试不通过
*/

bool comp(string time_eary, string time_last)
{
    for (int i = 0; i < time_eary.size(); i++)
    {
        if (time_eary[i] < time_last[i])
        {
            return true;
        }
        else if (time_eary[i] > time_last[i])
        {
            return false;
        }
        else
            continue;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int num;
    cin >> num;

    string id_eary, id_last;

    string time_eary, time_last;

    string tep_eary, tep_last, tep_id;

    cin >> id_eary >> time_eary >> time_last;
    id_last = id_eary;
    for (int i = 1; i < num; i++)
    {
        cin >> tep_id >> tep_eary >> tep_last;
        if (!comp(time_eary, tep_eary))
        {
            id_eary = tep_id;
        }
        if (comp(time_last, tep_last))
        {
            id_last = tep_id;
        }
    }
    cout << id_eary << " " << id_last;

    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    string open_id, open_time;
    string close_id, close_time;

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string id, in_time, out_time;
        cin >> id >> in_time >> out_time;

        // 开门的人
        if (!i || in_time < open_time)
        {
            open_id = id;
            open_time = in_time;
        }

        // 关门的人
        if (!i || out_time > close_time)
        {
            close_id = id;
            close_time = out_time;
        }
    }
    cout << open_id << ' ' << close_id;
    return 0;
}

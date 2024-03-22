#include <iostream>
using namespace std;
/**
This time you are asked to tell the difference between the lowest grade of all the male students and the highest grade of all the female students.

Input Specification:
Each input file contains one test case. Each case contains a positive integer N, followed by N lines of student information. Each line contains a student's name, gender, ID and grade, separated by a space, where name and ID are strings of no more than 10 characters with no space, gender is either F (female) or M (male), and grade is an integer between 0 and 100. It is guaranteed that all the grades are distinct.

Output Specification:
For each test case, output in 3 lines. The first line gives the name and ID of the female student with the highest grade, and the second line gives that of the male student with the lowest grade. The third line gives the difference grade
F
​
 −grade
M
​
 . If one such kind of student is missing, output Absent in the corresponding line, and output NA in the third line instead.
 */

struct student
{
    string name;
    char gender;
    string ID;
    int grade;
};

int main()
{
    int n;
    student s[101], f, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].name >> s[i].gender >> s[i].ID >> s[i].grade;
    }
    int fgrade = -1;
    string fID, mID, fname, mname;
    int mgrade = 101;

    /**
     *  string.empty() 判断字符串有没有赋值
     *
     */

    // for (int i = 0; i < n; i++)
    // {
    //     cout << s[i].name << s[i].gender << s[i].ID << s[i].grade << endl;
    // }

    for (int i = 0; i < n; i++)
    {

        if (s[i].gender == 'F' && s[i].grade > fgrade)
        {
            fgrade = s[i].grade;
            fID = s[i].ID;
            fname = s[i].name;
        }

        if (s[i].gender == 'M' && s[i].grade < mgrade)
        {
            mgrade = s[i].grade;
            mID = s[i].ID;
            mname = s[i].name;
        }
    }
    if (fgrade == -1)
        cout << "Absent" << endl;
    else
        cout << fname << ' ' << fID << endl;

    if (mgrade == 101)
        cout << "Absent" << endl;
    else
        cout << mname << ' ' << mID << endl;

    if (fname.size() && mname.size())
        cout << abs(fgrade - mgrade) << endl;
    else
        // " " 和 '' 是不一样的
        cout << "NA" << endl;
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
/*
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm


*/

int main()
{
    char week[7][5] = {
        "MON",
        "TUE",
        "WED",
        "THU",
        "FRI",
        "SAT",
        "SUN"};
    char str1[70], str2[70], str3[70], str4[70];
    cin >> str1 >> str2 >> str3 >> str4;

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len3 = strlen(str3);
    int len4 = strlen(str4);
    int i;

    // 寻找 str1 和 str2中第一对相同位置的A~G的大写字母
    for (i = 0; i < len1 && i < len2; i++)
    {
        if (str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G')
        {
            printf("%s ", week[str1[i] - 'A']); // 输出对应是星期几
            break;
        }
    }
    // 在上面的基础上，往后寻找相同位置的 0~9 或A~N 的字符
    for (i++; i < len1 && i < len2; i++)
    {
        if (str1[i] == str2[i])
        {
            if (str1[i] >= '0' && str1[i] <= '9')
            {
                printf("%02d:", str1[i] - '0'); // 输出 0-9
                break;
            }
            else if (str1[i] >= 'A' && str1[i] <= 'N')
            {
                printf("%02d:", str1[i] - 'A' + 10); // 输出 10~23
                break;
            }
        }
    }
    // 寻找 str3 和 str4 中第一对相同位置的 A~Z 或 a~z 的英文字母
    for (i = 0; i < len3 && i < len4; i++)
    {
        if (str3[i] == str4[i])
        {
            if ((str3[i] >= 'A' && str3[i] <= 'Z') || (str3[i] >= 'a' && str3[i] <= 'z'))
            {
                printf("%02d", i); // 输出当前位置
                break;
            }
        }
    }
    return 0;
}

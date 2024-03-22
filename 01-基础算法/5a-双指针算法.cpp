/**
 * @file 5a-双指针算法.cpp
 * @author Huxzhi
 * @brief
 * @version 0.1
 * @date 2024-03-05
 *
 * @copyright Copyright (c) 2024
 *
 * 基本模版
 for (int i = 0; i < n; i++)
    {
        while (j < i && check(i, j))
            j++;

        // 每道题目的具体逻辑
    }
 */

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str[1000];
    gets(str);
    int n = strlen(str);

    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j < n && str[j] != ' ')
            j++;

        // 每道题目的具体逻辑
        for (int k = i; k < j; k++)
            cout << str[k];
        cout << endl;

        i = j;
    }
    return 0;
}
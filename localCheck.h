#include <chrono>
#include <fstream>
#include <iostream>

using namespace std;
using namespace std::chrono;

#define INPUT "input.txt"
#define OUTPUT "output.txt"
#define TEMPOUTOUT "temp_result.txt"

#define FREOPEN                       \
    freopen(INPUT, "r", stdin);       \
    freopen(TEMPOUTOUT, "w", stdout); \
    auto starttime = system_clock::now();

#define CHECK                                                              \
    duration<double> diff = system_clock::now() - starttime;               \
    /*关闭重定向的文件流*/                                        \
    fclose(stdin);                                                         \
    fclose(stdout);                                                        \
                                                                           \
    /*重新打开临时输出文件和期望的输出文件进行比较*/ \
    ifstream tempOutput(TEMPOUTOUT);                                       \
    ifstream expectedOutput(OUTPUT);                                       \
                                                                           \
    if (!tempOutput.is_open() || !expectedOutput.is_open())                \
    {                                                                      \
        cerr << "无法打开文件!" << endl;                                   \
        return -1;                                                         \
    }                                                                      \
                                                                           \
    string computedSum, expectedSum;                                       \
    cerr << "本次耗时: " << diff.count() * 1000 << " ms\n";                \
    bool error = false;                                                    \
    while (!error)                                                         \
    {                                                                      \
        if (!expectedOutput && !tempOutput)                                \
            break;                                                         \
        expectedOutput >> expectedSum;                                     \
        tempOutput >> computedSum;                                         \
        if (computedSum != expectedSum)                                    \
            error = true;                                                  \
    }                                                                      \
    tempOutput.close();                                                    \
    expectedOutput.close();                                                \
    cerr << "输出结果: " << endl;                                          \
    ifstream resultOutput(TEMPOUTOUT);                                     \
    if (!resultOutput.is_open())                                           \
    {                                                                      \
        cerr << "无法打开文件 " << TEMPOUTOUT << endl;                     \
        return -1;                                                         \
    }                                                                      \
    string c;                                                              \
    while (getline(resultOutput, c))                                       \
        cerr << c << endl;                                                 \
    if (error)                                                             \
        cerr << "\n结果不一致" << endl;                                    \
    else                                                                   \
        cerr << "\n结果一致" << endl;

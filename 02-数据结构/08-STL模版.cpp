/*

vector 变长数组,倍增的思想
    size()
    empty()
    clear()
    front()/back()
    push_back()/pop_back()
    begin()/end()
    []
    支持比较运算，按字典序
pair
    first，第一个元素
    second，第二个元素
    支持比较运算，以first为第一关键字，以second为第二关键字（字典序）
string 字符串  substr() ,c_str()
    size()
    empty()
    clear()
    substr(下标从0开始,长度)
queue 队列
    size()
    empty()
    push() 向队尾插入一个元素
    front() 返回队头元素
    back() 返回队尾元素
    pop() 弹出队头元素
priority_queue 优先队列，堆实现，默认大根堆，如果小根堆 插入时为 -x，或者定义
    push() 插入一个元素
    top()  返回堆顶元素
    pop() 弹出堆顶元素
    定义小根堆的方式 priority_queue<int, vector<int>, greater<int>> heap;
stack 栈
    push() 插入一个元素
    top()  返回栈顶元素
    pop() 弹出栈顶元素
deque 双端队列 只是速度较慢
    size()
    empty()
    clear()
    front()/back()
    push_back()/pop_back()
    push_front()/pop_front()
    begin()/end() ++，-- 返回前驱和后继
    []
set, map, multiset, multimap 基于平衡二叉树（红黑树）
    set/multiset
        insert()
        find() 查找一个数
        count() 返回个数
        erase()
            (1) 输入是一个数，删除所有x
            (2) 输入一个迭代器，删除这个迭代器
        lower_bound()/upper_bound()
            lower_bound(x)返回大于等于x的最小的数的迭代器
            upper_bound(×)返回大于x的最小的数的迭代器
    map/multimap
        insert() 插人的数是一个pair
        erase() 输入的参数是pair或者迭代器
        find() 时间复杂度是0(logn)
        lower_bound()/upper_bound()
unordered_set, unordered_map, unordered_multiset, unordered_multimap 哈希表
    和上面类似，增删改查的时间复杂度是0(1)
    不支持 lower bound()/upper bound() 迭代器的++..
bitset 压位 位存储，状态压缩
    bitset<10000> s; 大小为 bool 的 八分之一，用 1 bit 表示真假
    ~, &, |, ^
    >>, <<
    ==, !=
    []
    count() 返回有多少个1
    any（） 判断是否至少有一个1
    none() 判断是否全为
    set() 把所有位置成1
    set(k，v) 将第k位变成v
    reset（) 把所有位变成e
    flip() 等价于~
    flip(k) 把第k位取反



*/

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int main()
{
    vector<int> a(10, 3); // 长度为 10，每个元素为 3

    a.size();
    a.empty();
    for (vector<int>::iterator i = a.begin(); i != a.end(); i++)
        cout << *i << ' ';
    cout << endl;

    pair<int, string> p;
    pair<int, pair<int, int>> q; // 保存3个数据项

    // 两种构建方式
    p = make_pair(10, "Yes");
    p = {20, "abc"};

    string a = "abu";
    printf("%s", a);

    priority_queue<int, vector<int>, greater<int>> heap;
}
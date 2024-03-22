# PAT 甲级考试备考

[Acwing 算法基础课](https://www.acwing.com/activity/content/11/)

## 知识点

- 基础算法 —— [代码模板和思路](./01-基础算法/0-代码模板和思路.md)
  - 排序
  - 二分
  - 高精度
  - 前缀和与差分
  - 双指针算法
  - 位运算
  - 离散化
  - 区间合并
- 数据结构 —— 代码模板链接 常用代码模板 2——数据结构
  - 链表与邻接表：树与图的存储
  - 栈与队列：单调队列、单调栈
  - KMP 字符串
  - Trie 树 （存储和读取字符串）
  - 并查集
  - 堆
  - Hash 表
  - C++ STL 使用技巧
- 搜索与图论 —— [代码模板和思路](./03-搜索与图论/0-代码模板和思路.md)
  - DFS 与 BFS
  - 树与图的遍历
    - 拓扑排序
  - 最短路
  - 最小生成树
  - 二分图：
    - 染色法
    - 匈牙利算法
- 数学知识 —— 代码模板链接 常用代码模板 4——数学知识
  - 质数
  - 约数
  - 欧拉函数
  - 快速幂
  - 扩展欧几里得算法
  - 中国剩余定理
  - 高斯消元
  - 组合计数
  - 容斥原理
  - 简单博弈论
- 动态规划
  - 背包问题
  - 线性 DP
  - 区间 DP
  - 计数类 DP
  - 数位统计 DP
  - 状态压缩 DP
  - 树形 DP
  - 记忆化搜索
- 贪心
- 时空复杂度分析

## 自动化测试结果

在图的之后的文件才考虑到输入输出的麻烦

添加了一个自定义头文件 `localCheck.h`，用 重定向输入流和输出流实现从文件中读取测试数据，用了两个自己写的宏定义

- `FREOPEN` 在读取输入流之前
- `CHECK` 在 `return 0` 的前面 即可

在 VS Code 里会自动检测工作区内的头文件，在编译的时候需要加上 `-I $workspaceRoot`

- 使用 `run coder` 插件，设置为 `  "cpp": "cd $dir && g++ $fileName -o $fileNameWithoutExt -I $workspaceRoot && $dir$fileNameWithoutExt",`
- debug 则在 `.vscode/c_cpp_properties.json` 加上`includePath:["${workspaceFolder}/**"]` 对应的

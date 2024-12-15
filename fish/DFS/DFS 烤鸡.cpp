#include <bits/stdc++.h>
using namespace std;

int n, res = 0;  // n表示美味程度，res用于统计方案数
int arr[12];  // 存储配料的质量方案
int out[52000][10];  // 存储所有符合条件的配料方案

// 深度优先搜索函数，x表示当前配料位置，sum表示当前累计的总和
void dfs(int x, int sum)
{
     if (sum > n) return;  // 如果总和超过n，返回
     if (x > 10)  // 如果已经遍历了所有10个配料
     {
          if (sum == n)  // 如果总和等于n
          {
               res++;  // 增加方案数
               for (int i = 1; i <= 10; i++)
                    out[res][i] = arr[i];  // 保存该方案
          }
          return;
     }
     for (int i = 1; i <= 3; i++)  // 对每个配料，选择1、2、3克
     {
          arr[x] = i;  // 设定当前配料的质量
          dfs(x + 1, sum + i);  // 递归处理下一个配料
          arr[x] = 0;  // 回溯，清空当前配料质量
     }
}

int main()
{
     cin >> n;  // 输入美味程度n

     // 如果n小于10或者大于30，直接返回0，因为不可能有符合条件的组合
     if (n < 10 || n > 30)
     {
          cout << "0";
          return 0;
     }

     // 从第一个配料开始进行深度优先搜索
     dfs(1, 0);

     // 输出结果
     cout << res << endl;  // 输出方案总数
     for (int i = 1; i <= res; i++)  // 输出每种方案
     {
          for (int j = 1; j <= 10; j++)
               cout << out[i][j] << " ";
          cout << endl;
     }
}

/*
#include <bits/stdc++.h>
using namespace std;

int n, res = 0;
int arr[12]; // 存方案
int out[52000][10];

void dfs(int x, int sum) //x表示当前位置
{
     if (sum > n) return; //如果目前累计大于n直接返回
     if (x > 10) //遍历结束
     {
          if (sum == n)
          {
               res++; //结果
               for (int i = 1; i <= 10; i++) out[res][i] = arr[i]; //输出方案中的所有数字
          }
          return;
     }
     for (int i = 1; i <= 3; i++)
     {
          arr[x] = i;
          dfs(x + 1, sum + i); //遍历下一个位置
          arr[x] = 0;
     }
}

int main()
{
     cin >> n;
     if (n < 10 || n > 30)
     {
          cout << "0";
          return 0;
     }
     dfs(1, 0);
     cout << res << endl;
     for (int i = 1; i <= res; i++)
     {
          for (int j = 1; j <= 10; j++)
               cout << out[i][j] << " ";
          cout << endl;
     }
}

 */
/*
# 烤鸡

## 题目背景

猪猪 Hanke 得到了一只鸡。

## 题目描述

猪猪 Hanke 特别喜欢吃烤鸡（本是同畜牲，相煎何太急！）Hanke 吃鸡很特别，为什么特别呢？因为他有 $10$ 种配料（芥末、孜然等），每种配料可以放 $1$ 到 $3$ 克，任意烤鸡的美味程度为所有配料质量之和。

现在， Hanke 想要知道，如果给你一个美味程度 $n$ ，请输出这 $10$ 种配料的所有搭配方案。

## 输入格式

一个正整数 $n$，表示美味程度。

## 输出格式

第一行，方案总数。

第二行至结束，$10$ 个数，表示每种配料所放的质量，按字典序排列。

如果没有符合要求的方法，就只要在第一行输出一个 $0$。

## 样例 #1

### 样例输入 #1

```
11
```

### 样例输出 #1

```
10
1 1 1 1 1 1 1 1 1 2
1 1 1 1 1 1 1 1 2 1
1 1 1 1 1 1 1 2 1 1
1 1 1 1 1 1 2 1 1 1
1 1 1 1 1 2 1 1 1 1
1 1 1 1 2 1 1 1 1 1
1 1 1 2 1 1 1 1 1 1
1 1 2 1 1 1 1 1 1 1
1 2 1 1 1 1 1 1 1 1
2 1 1 1 1 1 1 1 1 1
```

## 提示

对于 $100\%$ 的数据，$n \leq 5000$。
 */
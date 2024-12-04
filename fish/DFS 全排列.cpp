#include <bits/stdc++.h>
using namespace std;

int n;  // 存储元素个数
const int N = 20;  // 最大支持的排列个数
bool arr[N];  // 用来标记数字是否被选择
int g[N];  // 存储当前排列

// 深度优先搜索（DFS）函数，用来生成排列
void dfs(int u) {
    if (u > n) {  // 如果已经生成了一个完整的排列
        // 输出当前的排列
        for (int i = 1; i <= n; i++)
            printf("%5d", arr[i]);  // 输出当前排列的数字
        cout << endl;  // 输出换行
        return;
    }

    // 对于每一个数字，尝试放入当前位置u
    for (int i = 1; i <= n; i++) {
        if (!arr[i]) {  // 如果数字i没有被选择过
            arr[i] = true;  // 标记数字i为已选择
            g[u] = i;  // 将数字i放入当前位置u
            dfs(u + 1);  // 递归处理下一个位置
            arr[i] = false;  // 回溯，将数字i标记为未选择
        }
    }
}

int main() {
    cin >> n;  // 输入排列的元素个数n
    dfs(1);  // 从第一个位置开始递归生成排列
}

/*
#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 20;
bool arr[N];
int g[N];

void dfs(int u)
{
    if (u > n)
    {
        for (int i = 1; i <= n; i++) printf("%5d", arr[i]);
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!arr[i])
        {
            arr[i] = true;
            g[u] = i;
            dfs(u + 1);
            arr[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
}

 */
/*
# 全排列问题

## 题目描述

按照字典序输出自然数 $1$ 到 $n$ 所有不重复的排列，即 $n$ 的全排列，要求所产生的任一数字序列中不允许出现重复的数字。

## 输入格式

一个整数 $n$。

## 输出格式

由 $1 \sim n$ 组成的所有不重复的数字序列，每行一个序列。

每个数字保留 $5$ 个场宽。

## 样例 #1

### 样例输入 #1

```
3
```

### 样例输出 #1

```
1    2    3
    1    3    2
    2    1    3
    2    3    1
    3    1    2
    3    2    1
```

## 提示

$1 \leq n \leq 9$。
 */
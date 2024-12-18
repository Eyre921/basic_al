#include <bits/stdc++.h>
using namespace std;

int n, r;
const int N = 20;
int arr[N];

void dfs(int x, int start) {
    if (x > r) {  // 如果已选择了 r 个数，打印组合
        for (int i = 1; i <= r; i++) printf("%3d", arr[i]);
        cout << endl;
        return;
    }
    for (int i = start; i <= n; i++) {  // 从 start 开始，尝试选择数字
        arr[x] = i;  // 选择第 x 个位置的数字
        dfs(x + 1, i + 1);  // 递归选择下一个数字，确保递增
        arr[x] = 0;  // 撤销选择（虽然这里不需要，但为了理解递归流程）
    }
}

int main() {
    cin >> n >> r;  // 输入 n 和 r
    dfs(1, 1);  // 从第一位置开始尝试选择
    return 0;
}

/*
# 组合的输出

## 题目描述

排列与组合是常用的数学方法，其中组合就是从 $n$ 个元素中抽出 $r$ 个元素（不分顺序且 $r \le n$），我们可以简单地将 $n$ 个元素理解为自然数 $1,2,\dots,n$，从中任取 $r$ 个数。

现要求你输出所有组合。

例如 $n=5,r=3$，所有组合为：

$123,124,125,134,135,145,234,235,245,345$。

## 输入格式

一行两个自然数 $n,r(1<n<21,0 \le r \le n)$。

## 输出格式

所有的组合，每一个组合占一行且其中的元素按由小到大的顺序排列，每个元素占三个字符的位置，所有的组合也按字典顺序。

**注意哦！输出时，每个数字需要 $3$ 个场宽。以 C++ 为例，你可以使用下列代码：**

```cpp
cout << setw(3) << x;
```

输出占 $3$ 个场宽的数 $x$。注意你需要头文件 `iomanip`。

## 样例 #1

### 样例输入 #1

```
5 3
```

### 样例输出 #1

```
1  2  3
  1  2  4
  1  2  5
  1  3  4
  1  3  5
  1  4  5
  2  3  4
  2  3  5
  2  4  5
  3  4  5
```
 */

#include <bits/stdc++.h>
using namespace std;
int n, r;
const int N = 20;
bool st[N];
int arr[N], q[N];
int ans;
/*
# [NOIP2002 普及组] 选数

## 题目描述

已知 $n$ 个整数 $x_1,x_2,\cdots,x_n$，以及 $1$ 个整数 $k$（$k<n$）。从 $n$ 个整数中任选 $k$ 个整数相加，可分别得到一系列的和。例如当 $n=4$，$k=3$，$4$ 个整数分别为 $3,7,12,19$ 时，可得全部的组合与它们的和为：

$3+7+12=22$

$3+7+19=29$

$7+12+19=38$

$3+12+19=34$

现在，要求你计算出和为素数共有多少种。

例如上例，只有一种的和为素数：$3+7+19=29$。

## 输入格式

第一行两个空格隔开的整数 $n,k$（$1 \le n \le 20$，$k<n$）。

第二行 $n$ 个整数，分别为 $x_1,x_2,\cdots,x_n$（$1 \le x_i \le 5\times 10^6$）。

## 输出格式

输出一个整数，表示种类数。

## 样例 #1

### 样例输入 #1

```
4 3
3 7 12 19
```

### 样例输出 #1

```
1
```

## 提示

**【题目来源】**

NOIP 2002 普及组第二题
 */
bool is_prime(int n)
{
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0) return false;
    }
    return true;
}

void dfs(int x, int start)
{
    if (x > r)
    {
        int sum = 0;
        for (int i = 1; i <= r; i++) sum += arr[i];
        if (is_prime(sum)) ans++;
        return;
    }
    for (int i = start; i <= n; i++)
    {
        arr[x] = q[i];
        dfs(x + 1, i + 1);
        arr[x] = -1;
    }
}


int main()
{
    cin >> n >> r;
    for (int i = 1; i <= n; i++) scanf("%d", &q[i]);
    dfs(1, 1);
    printf("%d\n", ans);
}

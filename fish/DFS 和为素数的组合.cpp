#include <bits/stdc++.h>
using namespace std;

int n, r;  // n是数组的长度，r是组合的长度
const int N = 20;
bool st[N];  // 标记数组，用于去重（此处未使用）
int arr[N], q[N];  // arr存储当前组合，q存储输入的数组
int ans;  // 记录符合条件的组合个数

// 判断一个数是否为素数
bool is_prime(int n)
{
    if (n < 2) return false;  // 小于2的数不是素数
    if (n == 2 || n == 3) return true;  // 2和3是素数
    if (n % 2 == 0) return false;  // 偶数不是素数
    // 检查从3开始到sqrt(n)的奇数
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0) return false;  // 如果能整除，则不是素数
    }
    return true;  // 如果没有找到因数，则是素数
}

// 深度优先搜索（DFS）函数，生成所有的组合
void dfs(int x, int start)
{
    // 递归到组合长度r时，检查当前组合的和是否为素数
    if (x > r)
    {
        int sum = 0;
        // 计算当前组合的和
        for (int i = 1; i <= r; i++) sum += arr[i];
        // 如果和是素数，增加结果计数
        if (is_prime(sum)) ans++;
        return;
    }

    // 遍历从start位置到n的所有元素
    for (int i = start; i <= n; i++)
    {
        arr[x] = q[i];  // 选取第i个元素加入组合
        dfs(x + 1, i + 1);  // 递归生成下一个位置的组合
        arr[x] = -1;  // 回溯，恢复状态
    }
}

int main()
{
    // 输入n和r
    cin >> n >> r;
    // 输入n个整数到q数组
    for (int i = 1; i <= n; i++) scanf("%d", &q[i]);
    // 从第1个位置开始生成组合
    dfs(1, 1);
    // 输出符合条件的组合个数
    printf("%d\n", ans);
}


/*
#include <bits/stdc++.h>
using namespace std;
int n, r;
const int N = 20;
bool st[N];
int arr[N], q[N];
int ans;

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

 */
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
#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int n, k;  // n为整数的总和，k为将整数分成的份数
int res = 0;  // 记录不同分法的数量

// dfs函数：深度优先搜索，x为当前递归深度，sum为当前组合的和，start为当前可以选择的最小数字
void dfs(int x, int sum, int start)
{
    // 如果当前和超过了目标n，直接返回
    if (sum > n) return;

    // 如果当前深度x超过了k，说明已经分完k份
    if (x > k)
    {
        // 如果当前组合的和等于n，计数器增加
        if (n == sum)
        {
            res++;  // 找到一个符合条件的分法，计数器加1
        }
        return;
    }

    // 遍历当前数字的选择范围
    // (k - x + 1) * i <= n 保证剩余选择的数字之和不会超过n
    for (int i = start; sum + (k - x + 1) * i <= n; i++)
    {
        // 深度优先搜索，递归选择下一个数字
        dfs(x + 1, sum + i, i);
    }
}

int main()
{
    cin >> n >> k;  // 输入目标和n和分成份数k
    dfs(1, 0, 1);  // 从深度1开始，当前和为0，最小数字为1
    cout << res;  // 输出符合条件的不同分法数量
}

/*
# [NOIP2001 提高组] 数的划分

## 题目描述

将整数 $n$ 分成 $k$ 份，且每份不能为空，任意两个方案不相同（不考虑顺序）。

例如：$n=7$，$k=3$，下面三种分法被认为是相同的。

$1,1,5$;
$1,5,1$;
$5,1,1$.

问有多少种不同的分法。

## 输入格式

$n,k$ （$6<n \le 200$，$2  \le k  \le  6$）

## 输出格式

$1$ 个整数，即不同的分法。

## 样例 #1

### 样例输入 #1

```
7 3
```

### 样例输出 #1

```
4
```

## 提示

四种分法为：
$1,1,5$;
$1,2,4$;
$1,3,3$;
$2,2,3$.

**【题目来源】**

NOIP 2001 提高组第二题
 */

/*
#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int n, k;
//int arr[N];
int res = 0;

void dfs(int x, int sum, int start)
{
    if (sum > n) return;
    if (x > k)
    {
        if (n == sum)
        {
            res++;
            //for (int i = 1; i <= k; i++) cout << arr[i] << " ";
            //cout << endl;
        }
        return;
    }
    for (int i = start; sum + (k - x + 1) * i <= n; i++)
    {
        //arr[x] = i;
        dfs(x + 1, sum + i, i);
        //arr[x] = 0;
    }
}

int main()
{
    cin >> n >> k;
    dfs(1, 0, 1);
    cout << res;
}
*/
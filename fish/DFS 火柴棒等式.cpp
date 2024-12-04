#include <bits/stdc++.h>
using namespace std;

int n;  // n表示火柴棒的总数
const int N = 1e3;  // 预设一个常数N，用于控制数组大小
int arr[10];  // 用于存储三个数字A、B、C的位置
int firenum[N] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};  // firenum[i]表示拼出数字i所需的火柴棒数
int res = 0;  // 用于统计符合条件的等式的数量

// 深度优先搜索函数，x表示当前处理的是第几个数字，sum表示当前已使用的火柴棒数量
void dfs(int x, int sum)
{
    // 如果已用的火柴棒数超过了n，或者sum大于n，直接返回
    if (sum > n) return;

    // 如果已经处理了三个数字
    if (x > 3)
    {
        // 检查是否满足A + B = C并且火柴棒数等于n
        if (arr[1] + arr[2] == arr[3] && sum == n)
        {
            res++;  // 满足条件，结果增加1
        }
        return;
    }

    // 遍历所有可能的数字
    for (int i = 0; i < N; i++)
    {
        arr[x] = i;  // 将当前数字设置为i
        dfs(x + 1, sum + firenum[i]);  // 递归处理下一个数字
        arr[x] = 0;  // 回溯，清空当前位置
    }
}

int main()
{
    cin >> n;  // 输入火柴棒数
    n -= 4;  // 减去等式中加号和等号各自需要的2根火柴棒
    // 计算数字10到99所需的火柴棒数
    for (int i = 10; i < N; i++)
        firenum[i] = firenum[i / 10] + firenum[i % 10];

    // 通过DFS计算符合条件的等式数量
    dfs(1, 0);
    cout << res;  // 输出结果
}


/*
#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 1e3;
int arr[10];
int firenum[N] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int res = 0;

void dfs(int x, int sum)
{
    if (sum > n) return;
    if (x > 3)
    {
        if (arr[1] + arr[2] == arr[3] && sum == n)
        {
            res++;
        }
        return;
    }
    for (int i = 0; i < N; i++)
    {
        arr[x] = i;
        dfs(x + 1, sum + firenum[i]);
        arr[x] = 0;
    }
}

int main()
{
    cin >> n;
    n -= 4;
    for (int i = 10; i < N; i++) firenum[i] = firenum[i / 10] + firenum[i % 10];
    dfs(1, 0);
    cout << res;
}

 */
/*
# [NOIP2008 提高组] 火柴棒等式

## 题目描述

给你 $n$ 根火柴棍，你可以拼出多少个形如 $A+B=C$ 的等式？等式中的 $A$、$B$、$C$ 是用火柴棍拼出的整数（若该数非零，则最高位不能是 $0$）。用火柴棍拼数字 $0\sim9$ 的拼法如图所示：

![](https://cdn.luogu.com.cn/upload/image_hosting/p5hsawt2.png)

注意：

1. 加号与等号各自需要两根火柴棍；
2. 如果 $A\neq B$，则 $A+B=C$ 与 $B+A=C$ 视为不同的等式（$A,B,C\geq0$）；
3. $n$ 根火柴棍必须全部用上。

## 输入格式

一个整数 $n(1 \leq n\leq 24)$。

## 输出格式

一个整数，能拼成的不同等式的数目。

## 样例 #1

### 样例输入 #1

```
14
```

### 样例输出 #1

```
2
```

## 样例 #2

### 样例输入 #2

```
18
```

### 样例输出 #2

```
9
```

## 提示

【输入输出样例 1 解释】

$2$ 个等式为 $0+1=1$ 和 $1+0=1$。

【输入输出样例 2 解释】

$9$ 个等式为

$0+4=4$、$0+11=11$、$1+10=11$、$2+2=4$、$2+7=9$、$4+0=4$、$7+2=9$、$10+1=11$、$11+0=11$。

noip2008 提高第二题
 */
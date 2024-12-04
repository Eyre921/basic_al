#include <bits/stdc++.h>
using namespace std;

const int N = 201;  // 最大楼层数
int n, a, b, ans = 1e9;  // n为楼层数，a为起始楼层，b为目标楼层，ans记录最少按键次数
int K[N];  // K[i]表示第i层楼上的电梯可跳跃的层数
int st[N];  // st[i]为1表示可以到达第i层楼
int steps[N];  // steps[i]记录到达第i层楼的最少步数

// dfs函数：深度优先搜索，x为当前楼层，step为当前步数
void dfs(int x, int step)
{
    // 如果步数超过最大楼层数n，或者楼层越界，则返回
    if (step > n || x > n || x < 0) return;

    // 如果当前楼层已经到达，并且当前步数大于等于之前到达该楼层的最小步数，则返回
    if (st[x] == 1 && step >= steps[x]) return;

    // 如果回到了起始楼层a，则返回
    if (step != 0 && x == a) return;

    // 标记当前楼层为已访问
    st[x] = 1;

    // 更新到达该楼层的最小步数
    if (x != a) steps[x] = min(steps[x], step);

    // 如果已经到达目标楼层b，更新最小按键次数
    if (x == b)
    {
        ans = min(ans, step);
        return;
    }
    else
    {
        // 如果当前楼层的最小步数大于当前的最小按键次数，或者步数大于最小按键次数，则剪枝返回
        if (steps[x] > ans || step > ans || step > steps[x]) return;
    }

    // 深度优先搜索：尝试向上和向下跳跃
    dfs(x + K[x], step + 1);  // 向上跳跃到x + K[x]层
    dfs(x - K[x], step + 1);  // 向下跳跃到x - K[x]层
}

int main()
{
    cin >> n >> a >> b;  // 输入楼层数n，起始楼层a，目标楼层b

    // 如果起始楼层和目标楼层相同，输出0
    if (a == b)
    {
        cout << "0" << endl;
        return 0;
    }

    // 输入每一层楼的电梯跳跃层数K[i]
    for (int i = 1; i <= n; i++)
        scanf("%d", &K[i]), steps[i] = 1e9, st[i] = 0;

    // 从起始楼层a开始，执行深度优先搜索
    dfs(a, -1);

    // 如果目标楼层b可以到达，输出最少的按键次数
    if (st[b] == 1)
    {
        cout << ans;
        return 0;
    }

    // 如果目标楼层b不可达，输出-1
    cout << "-1";
    return 0;
}
/*
# 奇怪的电梯

## 题目背景

感谢 @[yummy](https://www.luogu.com.cn/user/101694) 提供的一些数据。

## 题目描述

呵呵，有一天我做了一个梦，梦见了一种很奇怪的电梯。大楼的每一层楼都可以停电梯，而且第 $i$ 层楼（$1 \le i \le N$）上有一个数字 $K_i$（$0 \le K_i \le N$）。电梯只有四个按钮：开，关，上，下。上下的层数等于当前楼层上的那个数字。当然，如果不能满足要求，相应的按钮就会失灵。例如： $3, 3, 1, 2, 5$ 代表了 $K_i$（$K_1=3$，$K_2=3$，……），从 $1$ 楼开始。在 $1$ 楼，按“上”可以到 $4$ 楼，按“下”是不起作用的，因为没有 $-2$ 楼。那么，从 $A$ 楼到 $B$ 楼至少要按几次按钮呢？

## 输入格式

共二行。

第一行为三个用空格隔开的正整数，表示 $N, A, B$（$1 \le N \le 200$，$1 \le A, B \le N$）。

第二行为 $N$ 个用空格隔开的非负整数，表示 $K_i$。

## 输出格式

一行，即最少按键次数，若无法到达，则输出 `-1`。

## 样例 #1

### 样例输入 #1

```
5 1 5
3 3 1 2 5
```

### 样例输出 #1

```
3
```

## 提示

对于 $100 \%$ 的数据，$1 \le N \le 200$，$1 \le A, B \le N$，$0 \le K_i \le N$。

本题共 $16$ 个测试点，前 $15$ 个每个测试点 $6$ 分，最后一个测试点 $10$ 分。
 */

//BFS
/*
#include <bits/stdc++.h>
using namespace std;

const int N = 201;
int n, a, b;  // n为楼层数，a为起始楼层，b为目标楼层
int K[N];  // K[i]表示第i层楼上的电梯可跳跃的层数

// BFS函数，用于计算从起始楼层a到目标楼层b的最少按键次数
int bfs(int start, int end) {
    queue<pair<int, int>> q;  // 队列存储楼层和当前步数
    vector<int> dist(N, -1);  // dist[i]记录到达第i层的最小按键次数
    dist[start] = 0;  // 起始楼层按键次数为0
    q.push({start, 0});  // 将起始楼层和步数入队

    while (!q.empty()) {
        int x = q.front().first;  // 当前楼层
        int step = q.front().second;  // 当前按键次数
        q.pop();

        // 如果到达目标楼层，返回按键次数
        if (x == end) {
            return step;
        }

        // 上楼按钮，跳跃到x + K[x]层
        if (x + K[x] <= n && dist[x + K[x]] == -1) {
            dist[x + K[x]] = step + 1;
            q.push({x + K[x], step + 1});
        }

        // 下楼按钮，跳跃到x - K[x]层
        if (x - K[x] >= 1 && dist[x - K[x]] == -1) {
            dist[x - K[x]] = step + 1;
            q.push({x - K[x], step + 1});
        }
    }

    return -1;  // 如果无法到达目标楼层，返回-1
}

int main() {
    cin >> n >> a >> b;  // 输入楼层数n，起始楼层a，目标楼层b
    for (int i = 1; i <= n; i++) {
        cin >> K[i];  // 输入每层楼的电梯可跳跃层数K[i]
    }

    // 调用bfs函数计算最少按键次数并输出结果
    int result = bfs(a, b);
    cout << result << endl;  // 输出最少按键次数，如果无法到达则输出-1

    return 0;
}

 */


/*

#include <bits/stdc++.h>
using namespace std;
const int N = 201;
int n, a, b, ans = 1e9;
int K[N];
int st[N]; //1表示可以到达
int steps[N]; //记录到每层楼的步数

void dfs(int x, int step)
{
    if (step > n || x > n || x < 0) return;
    if (st[x] == 1 && step >= steps[x]) return;
    if (step != 0 && x == a) return; //回到起点就返回
    st[x] = 1;

    if (x != a) steps[x] = min(steps[x], step);
    if (x == b)
    {
        ans = min(ans, step);
        return;
    } else
    {
        if (steps[x] > ans || step > ans || step > steps[x]) return;
    }


    dfs(x + K[x], step+1);
    dfs(x - K[x], step+1);
}

int main()
{
    cin >> n >> a >> b;
    if (a == b)
    {
        cout << "0" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &K[i]), steps[i] = 1e9, st[i] = 0;
    dfs(a, -1);
    if (st[b] == 1) //如果可以到b
    {
        cout << ans;
        return 0;
    }
    cout << "-1";
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 105; // 定义网格的最大尺寸
int n, m;
char g[N][N];  // 用来存储网格
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};  // 八个方向的 x 偏移量
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};  // 八个方向的 y 偏移量

// 深度优先搜索（DFS）函数，返回一个水坑的大小
int dfs(int c_i, int c_j) {
    // 如果当前坐标越界或者已经是干地（'.'），返回 0
    if (c_i < 0 || c_j < 0 || c_i >= n || c_j >= m || g[c_i][c_j] == '.') {
        return 0;
    }

    // 标记当前坐标为已经访问
    g[c_i][c_j] = '.';
    int sum = 1;  // 当前块算作一个水坑
    // 遍历八个方向
    for (int i = 0; i < 8; i++) {
        sum += dfs(c_i + dx[i], c_j + dy[i]);  // 递归处理每个邻居
    }
    return sum;
}

int main() {
    cin >> n >> m;  // 输入网格的尺寸
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];  // 输入网格中的每一行
        }
    }

    vector<int> s;  // 用来保存每个水坑的面积
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int area = dfs(i, j);  // 计算从 (i, j) 开始的水坑的面积
            if (area > 0) {
                s.push_back(area);  // 如果找到了一个水坑，保存其面积
            }
        }
    }

    cout << s.size() << endl;  // 输出水坑的数量
    return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;
const int N = 105;
int n, m;
char g[N][N];
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
vector<int> s;

int dfs(int c_i, int c_j)
{

    if (c_i < 0 || c_j < 0 || c_i >= n || c_j >= m || g[c_i][c_j] == '.')
    {
        return 0;
    }
    g[c_i][c_j] = '.';
    int sum = 1; // 以当前块为中心向四周遍历
    for (int i = 0; i < 8; i++)
    {
        sum += dfs(c_i + dx[i], c_j + dy[i]);
    }
    return sum;
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int area = dfs(i, j);
            if (area) s.push_back(area);
        }


    cout << s.size() << endl;
    return 0;
}

 */

/*
# [USACO10OCT] Lake Counting S

## 题面翻译

由于近期的降雨，雨水汇集在农民约翰的田地不同的地方。我们用一个 $N\times M(1\leq N\leq 100, 1\leq M\leq 100)$ 的网格图表示。每个网格中有水（`W`） 或是旱地（`.`）。一个网格与其周围的八个网格相连，而一组相连的网格视为一个水坑。约翰想弄清楚他的田地已经形成了多少水坑。给出约翰田地的示意图，确定当中有多少水坑。

输入第 $1$ 行：两个空格隔开的整数：$N$ 和 $M$。

第 $2$ 行到第 $N+1$ 行：每行 $M$ 个字符，每个字符是 `W` 或 `.`，它们表示网格图中的一排。字符之间没有空格。

输出一行，表示水坑的数量。

## 题目描述

Due to recent rains, water has pooled in various places in Farmer John's field, which is represented by a rectangle of N x M (1 <= N <= 100; 1 <= M <= 100) squares. Each square contains either water ('W') or dry land ('.'). Farmer John would like to figure out how many ponds have formed in his field. A pond is a connected set of squares with water in them, where a square is considered adjacent to all eight of its neighbors. Given a diagram of Farmer John's field, determine how many ponds he has.

## 输入格式

Line 1: Two space-separated integers: N and M \* Lines 2..N+1: M characters per line representing one row of Farmer John's field. Each character is either 'W' or '.'. The characters do not have spaces between them.

## 输出格式

Line 1: The number of ponds in Farmer John's field.

## 样例 #1

### 样例输入 #1

```
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
```

### 样例输出 #1

```
3
```

## 提示

OUTPUT DETAILS: There are three ponds: one in the upper left, one in the lower left, and one along the right side.
 */

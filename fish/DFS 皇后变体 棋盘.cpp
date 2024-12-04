#include <bits/stdc++.h>

using namespace std;
const int N = 10;
int n, k;
char g[N][N];
bool col[N]; // 记录每列是否已经有棋子
long long res = 0; // 记录结果

// 回溯函数
void dfs(int u, int epo)
{
    if (epo == k)
    {
        // 已经放置了 k 个棋子
        res++;
        return;
    }

    if (u >= n) return; // 如果已经超过棋盘的行数，停止递归

    for (int i = 0; i < n; i++)
    {
        // 对应每一列
        if (!col[i] && g[u][i] == '#')
        {
            // 如果可以放置棋子
            col[i] = true; // 标记该列已经放置了棋子
            dfs(u + 1, epo + 1); // 放置棋子，递归进入下一行
            col[i] = false; // 撤销放置棋子的操作
        }
    }

    // 即使不放棋子，当前行也应该继续往下一行递归
    dfs(u + 1, epo);
}

int main()
{
    while (true)
    {
        cin >> n >> k;
        if (n == -1 && k == -1) return 0; // 结束输入

        // 读取棋盘形状
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> g[i][j];
            }
        }

        // 初始化
        res = 0;
        memset(col, 0, sizeof(col)); // 初始化列是否被占用的标记

        // 从第一行开始，尝试放置 k 个棋子
        dfs(0, 0);

        cout << res << endl;
    }

    return 0;
}

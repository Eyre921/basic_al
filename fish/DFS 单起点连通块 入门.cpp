#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int n, m;
char g[N][N];  // 存储瓷砖地图，'@'代表安全砖，'#'代表不安全砖
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};  // 四个方向的偏移量（右、左、下、上）

// 深度优先搜索（DFS）函数，用来计算能走过的最大安全瓷砖数量
int dfs(int c_i, int c_j)
{
    // 如果越界或者当前瓷砖是不安全的，返回0
    if (c_i < 0 || c_j < 0 || c_i >= n || c_j >= m || g[c_i][c_j] == '#')
    {
        return 0;
    }

    // 标记当前瓷砖已经访问过（为了避免重复计数）
    g[c_i][c_j] = '#';  // 变成不安全砖

    int count = 1;  // 当前瓷砖算作1块安全砖
    // 向四个方向递归探索，走过的安全砖数量累加
    for (int i = 0; i < 4; i++)
    {
        count += dfs(c_i + dx[i], c_j + dy[i]);
    }

    return count;  // 返回能走过的最大安全砖数量
}

int main()
{
    // 输入地图的行数和列数
    cin >> m >> n;

    // 输入瓷砖地图，'@'代表安全砖，'#'代表不安全砖
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    int maxSafeTiles = 0;  // 用于记录可以走过的最大安全砖数量

    // 遍历地图，找到每个安全砖，计算能走过的最大安全砖数量
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '@')  // 如果当前位置是安全砖
            {
                maxSafeTiles = max(maxSafeTiles, dfs(i, j));  // 计算能走过的最大安全砖数量
            }
        }

    // 输出最大能走过的安全砖数量，即成功进入桃花岛的最大砖数
    cout << maxSafeTiles << endl;

    return 0;
}






/*
#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int n, m;
char g[N][N];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
vector<int> s;

int dfs(int c_i, int c_j)
{
    if (c_i < 0 || c_j < 0 || c_i >= n || c_j >= m || g[c_i][c_j] == '#')
    {
        return 0;
    }
    g[c_i][c_j] = '#';
    int sum = 1; // 以当前块为中心向四周遍历
    for (int i = 0; i < 4; i++)
    {
        sum += dfs(c_i + dx[i], c_j + dy[i]);
    }
    return sum;
}

int main()
{
    // 输入
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    // 以@为起点遍历得到一个答案
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '@')
            {
                cout << dfs(i, j);
            }
        }


    return 0;
}

 */




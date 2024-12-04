#include <bits/stdc++.h>
using namespace std;

const int N = 20; // 最大矩阵尺寸
int n, m;          // 矩阵的行数和列数
int g[N][N];       // 存储二进制矩阵
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}; // 四个方向的偏移量
vector<int> s;     // 存储每个岛屿的面积

// DFS函数，计算岛屿面积
int dfs(int c_i, int c_j) {
    // 越界或者当前单元格是水（0），返回0
    if (c_i < 0 || c_j < 0 || c_i >= n || c_j >= m || g[c_i][c_j] == 0) {
        return 0;
    }

    // 标记当前单元格为水（已访问）
    g[c_i][c_j] = 0;
    int sum = 1;  // 当前岛屿的面积从1开始

    // 遍历四个方向，递归访问相邻的陆地（1）
    for (int i = 0; i < 4; i++) {
        sum += dfs(c_i + dx[i], c_j + dy[i]);
    }

    return sum;
}

int main() {
    // 输入矩阵的行列数
    cin >> n >> m;

    // 输入矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    // 计算每个岛屿的面积
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int area = dfs(i, j);  // 计算从 (i, j) 出发的岛屿面积
            if (area > 0) {
                s.push_back(area);  // 如果找到了岛屿，保存面积
            }
        }
    }

    // 如果没有岛屿
    if (s.empty()) {
        cout << 0 << endl;
    } else {
        // 按面积倒序排列
        sort(s.begin(), s.end(), greater<int>());

        // 输出每个岛屿的面积
        for (int i = 0; i < s.size(); i++) {
            cout << "#" << i + 1 << " " << s[i] << endl;
        }
    }

    return 0;
}



/*
给你一个大小为 m x n 的二进制矩阵 grid 。
岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
岛屿的面积是岛上值为 1 的单元格的数目。
计算并返回 grid 中每个岛屿面积,按倒序排列。如果没有岛屿，则返回 0 。
 */
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, m;
int g[N][N];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
vector<int> s;
// 输出每个岛屿的面积
int dfs(int c_i, int c_j)
{
    // 越界或者岛屿不存在，返回0
    if (c_i < 0 || c_j < 0 || c_i >= n || c_j >= m || g[c_i][c_j] == 0)
    {
        return 0;
    }
    g[c_i][c_j] = 0;
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
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    // 以每个点为起点遍历得到一个答案
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int area = dfs(i, j);
            if (area) s.push_back(area);
        }


    if (s.empty())
        cout << 0 << endl;
    else
    {
        sort(s.begin(), s.end(), greater<int>());
        for (int i = 0; i < s.size(); i++) cout << "#" << i + 1 << " " << s[i] << endl;
    }
    return 0;
}
*/
/*
8 13
0 0 1 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1 1 1 0 0 0
0 1 1 0 1 0 0 0 0 0 0 0 0
0 1 0 0 1 1 0 0 1 0 1 0 0
0 1 0 0 1 1 0 0 1 1 1 0 0
0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 1 1 0 0 0 0
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m;
char g[N][N];
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
vector<int> s;
// 输出每个岛屿的面积
int dfs(int c_i, int c_j)
{
    // 越界或者岛屿不存在，返回0
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


    cout << s.size() << endl;
    return 0;
}


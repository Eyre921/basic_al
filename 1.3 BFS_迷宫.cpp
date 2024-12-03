#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int m,n;
const int N = 20;
vector<vector<int>> g,visited;
pair<int,int> pre[N][N];
vector<int> dx = {-1,1,0,0}, dy = {0,0,1,-1};
// g 储存墙，visited储存是否访问

int bfs(){
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = 0;
    while(!q.empty())
    {
        for (int i = 0; i < q.size(); i++)
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && visited[nx][ny] == -1 && g[nx][ny] == 0)
                {
                    visited[nx][ny] = visited[x][y] + 1;
                    pre[nx][ny] = make_pair(x, y);
                    q.push({nx, ny});
                }
            }
        }
    }
    int x = n-1, y = m-1;
    while(x||y)
    {
        cout << x << " " << y << endl;
        auto it = pre[x][y];
        x = it.first, y = it.second;
    }
    puts("0 0");

    return visited[n-1][m-1];
}


int main()
{
    cin >> n >> m;
    g.resize(n, vector<int>(m)); // 初始化迷宫
    visited.resize(n, vector<int>(m, -1)); // 初始化访问标记

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    cout << bfs();
    return 0;
}
/*
 5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
 */
/*
给定一个n*m的二维整数数组，用来表示一个迷宫，数组中只包含0或1，其中0表示可以走的路，1表示不可通过
的墙壁。
最初，有一个人位于左上角(1,1)处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。
请问，该人从左上角移动至右下角(n,m)处，至少需要移动多少次。
数据保证(1,1)处和(n,m)处的数字为0，且一定至少存在一条通路。
输入格式
第一行包含两个整数n和m。
接下来n行，每行包含m个整数(0或1)，表示完整的二维数组迷宫。
输出格式
输出一个整数，表示从左上角移动至右下角的最少移动次数。
 */
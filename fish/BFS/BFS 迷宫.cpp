#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int n, m;
const int N = 20;
int g[N][N], dis[N][N];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
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
数据保证(1,1)处和(n,m)处的数字为0，且一定至少存在一条通路。*/
void bfs()
{
    queue<pair<int, int> > q;
    q.push({0, 0});
    dis[0][0] = 0;
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == 0 && dis[nx][ny] == -1)
            {
                q.push({nx, ny});
                dis[nx][ny] = dis[x][y] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &g[i][j]);
    memset(dis, -1, sizeof(dis));
    bfs();
    cout << dis[n - 1][m - 1] << endl;
}

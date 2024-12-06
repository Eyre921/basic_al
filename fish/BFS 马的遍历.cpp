#include <iostream>
#include <string.h>
using namespace std;
int n, m, hx, hy;
const int N = 405;
int dis[N][N];
pair<int, int> q[N * N];
int hh = 0, tt = 0;
int dx[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dy[8] = {2, -2, 2, -2, 1, -1, -1, 1};

void bfs()
{
    q[0] = {hx, hy};
    dis[hx][hy] = 0;
    while (hh <= tt)
    {
        auto t = q[hh++];
        int x = t.first, y = t.second;
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (dis[nx][ny] != -1) continue;
            dis[nx][ny] = dis[x][y] + 1;
            q[++tt] = {nx, ny};
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%-5d", dis[i][j]);
        printf("\n");
    }
}

int main()
{
    scanf("%d %d%d%d", &n, &m, &hx, &hy);
    memset(dis, -1, sizeof(dis));
    bfs();
}

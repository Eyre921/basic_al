#include <iostream>
#include <string.h>
using namespace std;
int n, m, a, b;
const int N = 510;
int dis[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
pair<int, int> q[N * N];
int hh = 0, tt = -1;

void bfs()
{
    while (hh <= tt)
    {
        auto cur = q[hh++];
        int x = cur.first, y = cur.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx > n || ny > m || nx < 1 || ny < 1) continue;
            if (dis[nx][ny] != -1)continue;
            dis[nx][ny] = dis[x][y] + 1;
            q[++tt] = make_pair(nx, ny);
        }
    }
}


int main()
{
    scanf("%d %d %d %d", &n, &m, &a, &b);
    memset(dis, -1, sizeof(dis));
    while (a--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        dis[x][y] = 0;
        q[++tt] = {x, y};
    }
    bfs();
    while (b--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        cout << dis[x][y] << endl;
    }
}

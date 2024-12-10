#include <iostream>
using namespace std;

int n;
const int N = 35;
int g[N][N];
pair<int, int> q[N * N];
int hh = 0, tt = 0;
bool st[N][N] = {false};
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void bfs()
{
    q[0] = {0, 0};
    hh = tt = 0;
    st[0][0] = true;
    while (hh <= tt)
    {
        auto cur = q[hh++];
        int x = cur.first, y = cur.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx > n + 1 || ny < 0 || ny > n + 1) continue;
            if (g[nx][ny] != 0) continue;
            if (st[nx][ny] == true) continue;
            st[nx][ny] = true;
            q[++tt] = make_pair(nx, ny);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &g[i][j]);
    for (int i = 0; i <= n + 1; i++) g[i][0] = g[0][i] = 0;
    for (int i = 0; i <= n + 1; i++) g[i][n + 1] = g[n + 1][i] = 0;

    bfs();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (g[i][j] == 0 && st[i][j] == false) g[i][j] = 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", g[i][j]);
        printf("\n");
    }
}

// 注意人物是在有限范围还是在无限范围

#include <bits/stdc++.h>
using namespace std;

int m;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
const int N = 310;
int t[N][N], fire[N][N];
pair<int, int> q[N * N];

int bfs()
{
    int hh = 0, tt = 0;
    t[0][0] = 0; //初始时间为0
    q[0] = {0, 0};
    while (hh <= tt)
    {
        auto cur = q[hh++];
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || ny < 0) continue;
            if (t[nx][ny]) continue; //已经到过了
            t[nx][ny] = t[cur.first][cur.second] + 1; //更新到达时间
            if (t[nx][ny] >= fire[nx][ny]) continue; //到的时候被毁掉了
            if (fire[nx][ny] > 1e9) return t[nx][ny]; //如果到了不会被砸到的地方就返回
            q[++tt] = {nx, ny}; //入队
        }
    }
    return -1;
}

int main()
{
    cin >> m;
    memset(fire, 0x3f, sizeof(fire));
    while (m--)
    {
        int x, y, t;
        scanf("%d %d %d", &x, &y, &t);
        fire[x][y] = min(fire[x][y], t); //当前点最小被感染时间
        for (int i = 0; i < 4; i++) //四周扩散
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx > 301 || ny > 301) continue; //越界跳过
            fire[nx][ny] = min(t, fire[nx][ny]);
        }
    } // 预处理，计算每个可能被砸到位置不能走的最小时间
    // 开始遍历
    cout << bfs();
}

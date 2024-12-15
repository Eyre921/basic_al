#include <iostream>
#include <deque>
#include <string.h>
#include <string>
using namespace std;
int n, m;
const int N = 510;
int dis[N][N];
char g[N][N];
deque<pair<int, int> > q;
int x1, y1, x2, y2;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int bfs(int x, int y)
{
   q.push_back(make_pair(x, y));
   dis[x][y] = 0;

   while (q.size())
   {
      auto t = q.front();
      q.pop_front();
      char ch = g[t.first][t.second];
      for (int i = 0; i < 4; i++)
      {
         int nx = t.first + dx[i], ny = t.second + dy[i];
         if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
         if (dis[nx][ny] >= 0) continue;

         if (ch == g[nx][ny])
         {
            dis[nx][ny] = dis[t.first][t.second];
            q.push_front(make_pair(nx, ny));
         }
         if (ch != g[nx][ny])
         {
            dis[nx][ny] = dis[t.first][t.second] + 1;
            q.push_back(make_pair(nx, ny));
         }
         if (nx == x2 && ny == y2) return dis[x2][y2];
      }
   }
   return -1;
}

int main()
{
   while (cin >> n >> m, n || m)
   {
      for (int i = 0; i < n; i++) scanf("%s", &g[i]);
      memset(dis, -1, sizeof(dis));
      q.clear();
      cin >> x1 >> y1 >> x2 >> y2;
      cout << bfs(x1, y1) << endl;
   }
}

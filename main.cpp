#include <iostream>
#include <string.h>
#include <string>
using namespace std;
typedef pair<int, int> PII;
int m, n;
const int N = 505;
int high[N][N], flag[N][N];
bool st[N][N];
PII q[N * N + 10];
int cnt_flat = 0;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int x1, y1;

bool check(int mid)
{
    q[0] = {x1, y1};
    st[x1][y1] = true;
    int hh = 0, tt = 0;
    int cnt = 1;
    while (hh <= tt)
    {
        auto t = q[hh++];
        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a < 1 || a > n || b < 1 || b > m) continue;
            if (st[a][b]) continue;
            if (abs(high[a][b] - high[t.first][t.second]) > mid) continue;
            st[a][b] = true;
            q[++tt] = make_pair(a, b);
            if (flag[a][b] == 1)
            {
                cnt++;
                if (cnt_flat == cnt) return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    // 读入棋盘
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) scanf("%d", &high[i][j]);
    // 读入flag
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &flag[i][j]);
            if (flag[i][j] == 1)
            {
                cnt_flat++;
            }
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (flag[i][j] == 1)
            {
                x1 = i, y1 = j;
                break;
            }
        }
    int l = -1, r = 1e9 + 10;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        memset(q, 0, sizeof(q));
        memset(st, false, sizeof(st));
        if (check(mid))
        {
            r = mid;
        } else l = mid;
    }
    cout << r << endl;
}

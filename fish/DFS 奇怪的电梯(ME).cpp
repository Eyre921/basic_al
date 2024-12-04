#include <bits/stdc++.h>
using namespace std;
const int N = 201;
int n, a, b, ans = 1e9;
int K[N];
int st[N]; //1表示可以到达
int steps[N]; //记录到每层楼的步数

void dfs(int x, int step)
{
    if (step > n || x > n || x < 0) return;
    if (st[x] == 1 && step >= steps[x]) return;
    if (step != 0 && x == a) return; //回到起点就返回
    st[x] = 1;

    if (x != a) steps[x] = min(steps[x], step);
    if (x == b)
    {
        ans = min(ans, step);
        return;
    } else
    {
        if (steps[x] > ans || step > ans || step > steps[x]) return;
    }


    dfs(x + K[x], step+1);
    dfs(x - K[x], step+1);
}

int main()
{
    cin >> n >> a >> b;
    if (a == b)
    {
        cout << "0" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &K[i]), steps[i] = 1e9, st[i] = 0;
    dfs(a, -1);
    if (st[b] == 1) //如果可以到b
    {
        cout << ans;
        return 0;
    }
    cout << "-1";
    return 0;
}

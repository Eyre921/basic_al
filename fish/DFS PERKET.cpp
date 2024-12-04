#include <bits/stdc++.h>
using namespace std;

int suan[12], ku[12];
int st[20]; //0 不知道，1选，2不选
int n, res = 0, ans = 1e9;

void dfs(int x, int s, int k)
{
    if (x > n)
    {
        if (k == 0) return; //如果没有加则苦度为0
        res = abs(s - k);
        ans = min(res, ans);
        return;
    }

    st[x] = 1;
    dfs(x + 1, s * suan[x], k + ku[x]);
    st[x] = 0;

    st[x] = 2;
    dfs(x + 1, s, k);
    st[x] = 0;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d%d", &suan[i], &ku[i]);
    dfs(1, 1, 0);
    cout << ans << endl;
}

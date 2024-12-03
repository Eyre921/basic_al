#include <bits/stdc++.h>
using namespace std;
const int N = 10, M = 2 * N;
int n;
int h[N],e[M],ne[M],idx;
bool st[N];

int ans = N;
void insert(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int dfs(int u)
{
    st[u] = true;
    int sum = 1, res = 0;
    for(int i = h[u]; i != -1;i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    res= max(res, n-sum);
    ans = min(ans, res);
    return sum;
}
int main()
{
    cin >> n;
    memset(h, -1, sizeof(h));
    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        insert(a, b),insert(b,a);
    }
    dfs(1);
    cout << ans << endl;
}
/*
 *
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6
 */

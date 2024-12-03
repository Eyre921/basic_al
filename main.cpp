#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 20;
bool arr[N];
int g[N];

void dfs(int u)
{
    if (u > n)
    {
        for (int i = 1; i <= n; i++) cout << g[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!arr[i])
        {
            arr[i] = true;
            g[u] = i;
            dfs(u + 1);
            arr[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) arr[i] = false;
    dfs(1);
}

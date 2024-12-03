#include <iostream>

using namespace std;
const int N = 10;
int n;
char g[N][N];
bool col[N],dg[2*N] ,udg[2*N];

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++) puts(g[i]);
        puts("");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!col[i] && !dg[i+u] && !udg[n+ i-u])
        {
            g[u][i] = 'Q';
            col[i] = dg[i+u] = udg[i-u+n] = true;
            dfs(u+1);
            col[i] = dg[i+u] = udg[i-u+n] = false;
            g[u][i] = '.';
        }
    }
}

int main(){
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';
    dfs(0);
}
#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int n, k;
//int arr[N];
int res = 0;

void dfs(int x, int sum, int start)
{
    if (sum > n) return;
    if (x > k)
    {
        if (n == sum)
        {
            res++;
            //for (int i = 1; i <= k; i++) cout << arr[i] << " ";
            //cout << endl;
        }
        return;
    }
    for (int i = start; sum + (k - x + 1) * i <= n; i++)
    {
        //arr[x] = i;
        dfs(x + 1, sum + i, i);
        //arr[x] = 0;
    }
}

int main()
{
    cin >> n >> k;
    dfs(1, 0, 1);
    cout << res;
}

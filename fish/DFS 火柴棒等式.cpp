#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 1e3;
int arr[10];
int firenum[N] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int res = 0;

void dfs(int x, int sum)
{
    if (sum > n) return;
    if (x > 3)
    {
        if (arr[1] + arr[2] == arr[3] && sum == n)
        {
            res++;
        }
        return;
    }
    for (int i = 0; i < N; i++)
    {
        arr[x] = i;
        dfs(x + 1, sum + firenum[i]);
        arr[x] = 0;
    }
}

int main()
{
    cin >> n;
    n -= 4;
    for (int i = 10; i < N; i++) firenum[i] = firenum[i / 10] + firenum[i % 10];
    dfs(1, 0);
    cout << res;
}

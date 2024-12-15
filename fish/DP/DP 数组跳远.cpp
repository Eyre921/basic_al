#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int a[N], dp[N];
int n, t,maxscore = 0;;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = n; i >= 1; i--) dp[i] = a[i] + (i + a[i] > n ? 0 : dp[i + a[i]]);// 从后向前更新
        for (int i = 1; i <= n; i++) maxscore = max(maxscore, dp[i]);
        cout << maxscore << endl;
    }
}

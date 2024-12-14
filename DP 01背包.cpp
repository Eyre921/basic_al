#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, C; // n为物品个数，C为背包容量
    cin >> n >> C;

    vector<int> weight(n + 1), value(n + 1);

    // 输入每个物品的重量和价值（从索引1开始）
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    // dp[i][j]表示前i个物品，在背包容量为j时的最大价值
    vector<vector<int>> dp(n + 1, vector<int>(C + 1, 0));

    // 动态规划计算最大价值
    for (int i = 1; i <= n; i++)  // 从第1个物品开始
    {
        for (int j = 0; j <= C; j++)  // 遍历每个容量
        {
            // 不选物品i
            dp[i][j] = dp[i - 1][j];
            // 选物品i（前提是容量足够）
            if (j >= weight[i])
            {
                dp[i][j] = max(dp[i][j], value[i] + dp[i - 1][j - weight[i]]);
            }
        }
    }

    // dp[n][C]为最大价值
    cout << dp[n][C] << endl;

    return 0;
}



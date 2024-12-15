#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, W;  // n: 物品的数量, W: 背包的最大容量
    cin >> n >> W;

    vector<int> weights(n), values(n);

    // 输入每个物品的重量和价值
    for (int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
    }

    // dp[i] 表示容量为 i 的背包能获得的最大价值
    vector<int> dp(W + 1, 0);

    // 完全背包的动态规划
    for (int i = 0; i < n; ++i) {
        for (int w = weights[i]; w <= W; ++w) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    // 输出背包容量为 W 时能获得的最大价值
    cout << dp[W] << endl;

    return 0;
}

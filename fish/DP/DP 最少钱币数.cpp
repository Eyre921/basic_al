#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int M;
    while (cin >> M && M)
    {
        // 如果 M == 0 退出
        int K;
        cin >> K;
        vector<int> billtype(K);
        for (int &coin: billtype) cin >> coin; // 读取所有硬币面额

        vector<int> dp(M + 1, INT_MAX); // 初始化 dp 数组
        dp[0] = 0; // 目标金额为 0 时，所需硬币数为 0

        //从一元钱开始遍历所有的硬币组合，直到钱M
        for (int i = 1; i <= M; i++)
        {
            // 尝试用每个硬币来填补
            for (auto coin: billtype)
            {
                if (i >= coin && dp[i - coin] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // 输出结果
        cout << (dp[M] == INT_MAX ? "Impossible" : to_string(dp[M])) << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

typedef long long ll;

const int N = 5010;
int nums[N];
int q[N];
int n;

// 计算所有窗口大小为k的子序列的最小值之和和最大值之和
void calculateRangeSum(int k, ll &sum_min, ll &sum_max)
{
    // 计算最小值之和
    int hh = 0, tt = -1;
    sum_min = 0;
    for (int i = 0; i < n; i++)
    {
        // 移除不在窗口内的元素
        if (hh <= tt && i - k + 1 > q[hh])
            hh++;
        // 保持队列单调递增
        while (hh <= tt && nums[q[tt]] >= nums[i])
            tt--;
        q[++tt] = i;
        // 当窗口形成时，累加最小值
        if (i >= k - 1)
            sum_min += (ll) nums[q[hh]];
    }

    // 计算最大值之和
    hh = 0, tt = -1;
    sum_max = 0;
    for (int i = 0; i < n; i++)
    {
        // 移除不在窗口内的元素
        if (hh <= tt && i - k + 1 > q[hh])
            hh++;
        // 保持队列单调递减
        while (hh <= tt && nums[q[tt]] <= nums[i])
            tt--;
        q[++tt] = i;
        // 当窗口形成时，累加最大值
        if (i >= k - 1)
            sum_max += (ll) nums[q[hh]];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n)
    {
        if (n == 0)
            break;
        // 读取序列
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        ll ans = 0;
        // 遍历所有窗口大小k，从2到n
        for (int k = 2; k <= n; k++)
        {
            ll sum_min = 0, sum_max = 0;
            calculateRangeSum(k, sum_min, sum_max);
            ans += (sum_max - sum_min);
        }
        cout << ans << "\n";
    }

    return 0;
}

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
void calculateRangeSum(int k, ll &sum_min, ll &sum_max) {
    // 计算最小值之和
    int hh = 0, tt = -1;
    sum_min = 0;
    for (int i = 0; i < n; i++) {
        // 移除不在窗口内的元素
        if (hh <= tt && i - k + 1 > q[hh])
            hh++;
        // 保持队列单调递增
        while (hh <= tt && nums[q[tt]] >= nums[i])
            tt--;
        q[++tt] = i;
        // 当窗口形成时，累加最小值
        if (i >= k - 1)
            sum_min += (ll)nums[q[hh]];
    }

    // 计算最大值之和
    hh = 0, tt = -1;
    sum_max = 0;
    for (int i = 0; i < n; i++) {
        // 移除不在窗口内的元素
        if (hh <= tt && i - k + 1 > q[hh])
            hh++;
        // 保持队列单调递减
        while (hh <= tt && nums[q[tt]] <= nums[i])
            tt--;
        q[++tt] = i;
        // 当窗口形成时，累加最大值
        if (i >= k - 1)
            sum_max += (ll)nums[q[hh]];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) {
        if (n == 0)
            break;
        // 读取序列
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        ll ans = 0;
        // 遍历所有窗口大小k，从2到n
        for (int k = 2; k <= n; k++) {
            ll sum_min = 0, sum_max = 0;
            calculateRangeSum(k, sum_min, sum_max);
            ans += (sum_max - sum_min);
        }
        cout << ans << "\n";
    }

    return 0;
}
/*
在数据分析中，我们常常会用到全距这个概念，它是指对于一定的统计量序列，序列最大值与最小值之差，即：

image.png(其中Xmax为最大值，Xmin为最小值)

举例，比如：序列 (3, 1, 7, 2) 全距为6, 序列(42, 42)全距为0.

现在给出一个长度为n的序列{ai} (i=1,2,…n)，请你求出该序列所有连续子序列的全距和，即

image.png其中R(i,j) 表示从下标i到下标j区间序列（闭区间）的全距。

【输入形式】

输入共有两行，第一行一个整数n，表示序列的长度。第二行输入n个数，即序列的所有元素值。

【输出形式】

输出仅一行，表示序列的连续子序列全距和。

【样例输入】

3
1 2 3
【样例输出】

4
【样例说明】

如对于上述示例第一组数据，{1，2，3}的连续子序列有：{1}、{2}、{3}、{1，2}、{2，3}、{1，2，3}，对应的全距为0，0，0，1，1，2，求和即为4。

【评分标准】

对于80%的数据，有 2 ≤ n ≤ 1000，1 ≤ai≤100000；

对于100%的数据，有 2 ≤ n ≤ 5000，1 ≤ai≤100000。
*/
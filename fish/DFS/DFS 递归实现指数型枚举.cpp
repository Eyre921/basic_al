#include <bits/stdc++.h>  // 引入所有标准库
using namespace std;

int n;  // n 表示我们需要从 1 到 n 中选择数字
const int N = 20;  // 最大支持的数字个数（根据题目条件，n最大为15，设置为20足够）
int st[N];  // st[i] 表示数字 i 是否被选择：1 表示选择，0 表示不选择，2 表示当前数字被跳过

// 深度优先搜索（DFS）函数，x 表示当前考虑的数字
void dfs(int x)
{
    // 如果 x 超过 n，表示已经考虑了所有数字，输出当前选择的方案
    if (x == n + 1)
    {
        // 输出当前选择的数字（即 st[i] == 1 的数字）
        for (int i = 1; i <= n; i++)
        {
            // 如果 st[i] == 1，表示选择了数字 i，输出它
            if (st[i] == 1)
            {
                printf("%d ", i);  // 输出选择的数字，并且数字之间有一个空格
            }
        }
        puts(" ");  // 输出一个空行，表示一个方案结束
        return;  // 递归结束
    }

    // 选择当前数字 x
    st[x] = 1;  // 标记选择了数字 x
    dfs(x + 1);  // 递归考虑下一个数字

    // 不选择当前数字 x
    st[x] = 2;  // 标记当前数字 x 被跳过（不选择）
    dfs(x + 1);  // 递归考虑下一个数字

    st[x] = 0;  // 撤销跳过，恢复 st[x] 状态
    return;  // 返回，继续尝试其他选择
}

int main()
{
    cin >> n;  // 输入数字 n
    dfs(1);  // 从数字 1 开始递归
}

/*
从 1∼n这 n 个整数中随机选取任意多个，输出所有可能的选择方案。

输入格式输入一个整数 n。

输出格式
每行输出一种方案。

同一行内的数必须升序排列，相邻两个数用恰好 1个空格隔开。
对于没有选任何数的方案，输出空行。
本题有自定义校验器（SPJ），各行（不同方案）之间的顺序任意。
数据范围
1≤n≤15
输入样例：
3
输出样例：

3
2
2 3
1
1 3
1 2
1 2 3
 */
/*
#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 20;
int st[N];

void dfs(int x)
{
    if (x == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (st[i] == 1)
            {
                printf("%d ", i);
            }
        }
        puts(" ");
        return;
    }
    st[x] = 1;
    dfs(x + 1);
    st[x] = 0;

    st[x] = 2;
    dfs(x + 1);
    st[x] = 0;
    return;
}

int main()
{
    cin >> n;
    dfs(1);
}

 */

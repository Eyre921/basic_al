/*
题目描述
按照字典序输出自然数
1 到 n
所有不重复的排列，即
n 的全排列，要求所产生的任一数字序列中不允许出现重复的数字。

输入格式
一个整数
n
n。

输出格式
由 1∼n
1∼n 组成的所有不重复的数字序列，每行一个序列。

每个数字保留 5个场宽。
 */

#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 20;
bool arr[N];
int g[N];

void dfs(int u)
{
    if (u > n)
    {
        for (int i = 1; i <= n; i++) printf("%5d", arr[i]);
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!arr[i])
        {
            arr[i] = true;
            g[u] = i;
            dfs(u + 1);
            arr[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
}

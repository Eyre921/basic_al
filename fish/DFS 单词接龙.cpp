

#include <bits/stdc++.h>
using namespace std;

const int N = 30;  // 定义最大单词数
int n;  // 存储单词数量
int res = 0;  // 记录当前找到的最长的单词链长度
int used[N];  // 记录每个单词使用的次数，防止单词被重复使用
int g[N][N];  // g[i][j]表示单词i和单词j是否能拼接，值为它们的重合部分长度
string words[N];  // 存储输入的单词

// dfs深度优先搜索，用于寻找最长单词链
void dfs(string dragon, int x) {
    res = max(res, (int) dragon.size());  // 更新最长单词链的长度
    used[x]++;  // 标记当前单词已经被使用
    // 遍历所有单词，尝试与当前单词拼接
    for (int i = 0; i < n; i++) {
        if (g[x][i] && used[i] < 2) {  // 如果i和x可以拼接并且i没有被使用超过一次
            // 拼接后继续dfs
            dfs(dragon + words[i].substr(g[x][i]), i);  // substr(g[x][i])表示拼接重叠部分
        }
    }
    used[x]--;  // 回溯时，恢复使用状态
}

int main() {
    cin >> n;  // 读取单词数
    for (int i = 0; i < n; i++) cin >> words[i];  // 读取所有单词
    char start;  // 读取起始字母
    cin >> start;

    // 预处理，构造每两个单词之间的最大重叠部分
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            string a = words[i], b = words[j];
            // 尝试找出单词a和单词b的最小重叠部分
            for (int k = 1; k < min(a.size(), b.size()); k++) {
                // 如果a的尾部与b的头部重叠
                if (a.substr(a.size() - k, k) == b.substr(0, k)) {
                    g[i][j] = k;  // 记录重叠部分长度
                    break;  // 找到重叠部分后退出
                }
            }
        }

    // 遍历每个可能作为第一个单词的元素
    for (int i = 0; i < n; i++) {
        if (words[i][0] == start) {  // 如果单词的第一个字母与给定的start字母相同
            dfs(words[i], i);  // 从这个单词开始进行dfs搜索
        }
    }

    // 输出最长单词链的长度
    cout << res << endl;
}
/*
# [NOIP2000 提高组] 单词接龙

## 题目背景

注意：本题为上古 NOIP 原题，不保证存在靠谱的做法能通过该数据范围下的所有数据。

本题为搜索题，本题不接受 hack 数据。[关于此类题目的详细内容](https://www.luogu.com.cn/paste/isdgwj5l)

NOIP2000 提高组 T3

## 题目描述

单词接龙是一个与我们经常玩的成语接龙相类似的游戏，现在我们已知一组单词，且给定一个开头的字母，要求出以这个字母开头的最长的“龙”（每个单词都最多在“龙”中出现两次），在两个单词相连时，其重合部分合为一部分，例如 `beast` 和 `astonish`，如果接成一条龙则变为 `beastonish`，另外相邻的两部分不能存在包含关系，例如 `at` 和 `atide` 间不能相连。

## 输入格式

输入的第一行为一个单独的整数 $n$ 表示单词数，以下 $n$ 行每行有一个单词，输入的最后一行为一个单个字符，表示“龙”开头的字母。你可以假定以此字母开头的“龙”一定存在。

## 输出格式

只需输出以此字母开头的最长的“龙”的长度。

## 样例 #1

### 样例输入 #1

```
5
at
touch
cheat
choose
tact
a
```

### 样例输出 #1

```
23
```

## 提示

样例解释：连成的“龙”为 `atoucheatactactouchoose`。

$n \le 20$。
 */
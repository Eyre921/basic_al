#include <iostream>
using namespace std;

const int N = 10;
int n, k;
char g[N][N];
bool col[N];  // 记录每列是否有棋子
long long res = 0;  // 记录总的方案数

// 回溯函数
void dfs(int u, int epo) {
    if (epo == k) {  // 如果已经放置了 k 个棋子
        res++;
        return;
    }

    if (u == n) return;  // 已经遍历到棋盘的最后一行

    for (int i = 0; i < n; i++) {
        if (!col[i] && g[u][i] == '#') {  // 当前行的第 i 列可以放棋子
            col[i] = true;  // 标记列 i 已经有棋子
            dfs(u + 1, epo + 1);  // 尝试放置棋子，递归到下一行
            col[i] = false;  // 撤销放置棋子的操作，继续探索
        }
    }

    // 不放棋子，尝试递归到下一行
    dfs(u + 1, epo);
}

int main() {
    while (true) {
        cin >> n >> k;
        if (n == -1 && k == -1) break;  // 输入结束

        // 读取棋盘形状
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> g[i][j];
            }
        }

        res = 0;  // 重置结果
        fill(begin(col), end(col), false);  // 初始化列占用标记

        // 从第一行开始尝试
        dfs(0, 0);

        cout << res << endl;
    }
    return 0;
}

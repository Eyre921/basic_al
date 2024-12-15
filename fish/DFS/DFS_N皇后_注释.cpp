#include <iostream> // 引入输入输出流库

using namespace std;

// 定义常量 N，最大棋盘尺寸为 10
const int N = 10;
int n; // 存储棋盘的大小
char g[N][N]; // 用二维数组 g 存储棋盘状态，'Q' 表示皇后，'.' 表示空位
bool col[N], dg[2*N], udg[2*N]; // col[i] 表示第 i 列是否被占用，dg[i+u] 表示从左上到右下的对角线是否被占用，udg[i-u+n] 表示从右上到左下的对角线是否被占用

// 深度优先搜索函数，用于回溯求解 n 皇后问题
void dfs(int u)
{
    // 如果已放置完所有皇后，输出棋盘状态
    if (u == n)
    {
        for (int i = 0; i < n; i++) // 遍历棋盘行
            puts(g[i]); // 输出每一行棋盘
        puts(""); // 输出一个空行，用于分隔不同的解
        return; // 返回，表示当前解已找到
    }

    // 遍历当前行的每一列
    for (int i = 0; i < n; i++)
    {
        // 检查该列、两个对角线是否被占用
        // col[i] 表示第 i 列是否被占用
        // dg[i+u] 表示左上到右下对角线是否被占用
        // udg[i-u+n] 表示右上到左下对角线是否被占用
        if (!col[i] && !dg[i+u] && !udg[n+i-u])
        {
            g[u][i] = 'Q'; // 在棋盘上放置一个皇后
            col[i] = dg[i+u] = udg[i-u+n] = true; // 标记该列和两个对角线已被占用
            dfs(u+1); // 递归放置下一行的皇后
            col[i] = dg[i+u] = udg[i-u+n] = false; // 回溯，撤销占用标记
            g[u][i] = '.'; // 撤销放置的皇后
        }
    }
}

int main(){
    cin >> n; // 输入棋盘大小 n

    // 初始化棋盘，所有位置初始化为 '.'，表示空位
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';

    // 从第 0 行开始递归求解
    dfs(0);

    return 0; // 程序结束
}

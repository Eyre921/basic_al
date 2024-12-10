#include <iostream>     // 引入输入输出流库，用于读取输入和输出结果
#include <string.h>     // 引入字符串处理库，主要用于内存操作函数如 memset
#include <string>       // 引入字符串类库
using namespace std;

typedef pair<int, int> PII; // 定义一个类型别名PII，表示一个整数对，用于存储网格的坐标

int m, n; // m表示网格的列数，n表示网格的行数
const int N = 505; // 定义网格的最大尺寸，防止数组越界
int high[N][N], flag[N][N]; // high数组存储每个格子的海拔高度，flag数组标记哪些格子是路标（1表示路标，0表示非路标）
bool st[N][N]; // st数组用于标记在搜索过程中某个格子是否已经被访问过
PII q[N * N + 10]; // 定义一个队列q，用于广度优先搜索（BFS），存储待处理的格子的坐标
int cnt_flat = 0; // cnt_flat记录需要访问的路标数量
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}; // dx和dy数组定义了四个方向（东、西、南、北）的移动偏移量
int x1, y1; // x1和y1存储第一个路标的坐标，用作BFS的起点

// check函数用于判断在给定的难度系数D（mid）下，是否可以使所有路标相互可达
bool check(int mid)
{
    q[0] = {x1, y1}; // 将起始路标点加入队列
    st[x1][y1] = true; // 标记起始路标点为已访问
    int hh = 0, tt = 0; // 初始化队列的头尾指针
    int cnt = 1; // 已访问的路标数量，初始为1（起点本身是路标）

    while (hh <= tt) // 当队列不为空时继续搜索
    {
        auto t = q[hh++]; // 取出队列中的第一个元素
        for (int i = 0; i < 4; i++) // 遍历四个方向
        {
            int a = t.first + dx[i], b = t.second + dy[i]; // 计算相邻格子的坐标
            // 检查新坐标是否在网格范围内
            if (a < 1 || a > n || b < 1 || b > m) continue;
            // 如果该格子已经被访问过，则跳过
            if (st[a][b]) continue;
            // 如果相邻格子的海拔高度差超过当前难度系数mid，则无法通过，跳过
            if (abs(high[a][b] - high[t.first][t.second]) > mid) continue;
            // 标记该格子为已访问
            st[a][b] = true;
            q[++tt] = make_pair(a, b); // 将该格子加入队列
            if (flag[a][b] == 1) // 如果该格子是路标
            {
                cnt++; // 增加已访问的路标数量
                if (cnt_flat == cnt) return true; // 如果所有路标都已访问，返回true
            }
        }
    }
    return false; // 如果无法访问所有路标，返回false
}

int main()
{
    cin >> n >> m; // 输入网格的行数n和列数m

    // 读入网格的海拔高度信息
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) scanf("%d", &high[i][j]);

    // 读入路标信息，1表示该格子是路标，0表示非路标，并统计路标的总数cnt_flat
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &flag[i][j]);
            if (flag[i][j] == 1)
            {
                cnt_flat++;
            }
        }

    // 找到第一个路标的坐标作为BFS的起点(x1, y1)
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (flag[i][j] == 1)
            {
                x1 = i, y1 = j;
                break;
            }
        }

    int l = -1, r = 1000000010; // 初始化二分查找的上下界，l为-1，r为一个足够大的值
    while (l + 1 < r) // 当搜索范围尚未收敛时继续
    {
        int mid = (l + r) >> 1; // 计算中间值mid作为当前的难度系数D
        memset(q, 0, sizeof(q)); // 重置队列q
        memset(st, false, sizeof(st)); // 重置访问标记st
        if (check(mid)) // 如果在当前mid下所有路标都可达
        {
            r = mid; // 将上界缩小为mid
        }
        else l = mid; // 否则，将下界增大为mid
    }
    cout << r << endl; // 输出最小满足条件的难度系数D
}

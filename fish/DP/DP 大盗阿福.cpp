#include <iostream>
#include <string.h>
#include <string>
using namespace std;

const int N = 100010;
int n, T, res = 0;
int val[N], f[N];
//若想要记忆化搜索，那么dfs的参数要尽可能少
//不应该把没有影响到边界的参数放进来
//想要剪枝，就要把尽可能能剪枝的参数写上来
//x表示当前正在考虑哪家店


int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
        for (int i = 1; i <= n; i++) f[i + 1] = max(f[i], f[i - 1] + val[i]);
        for (int i = 1; i <= n + 1; i++) res = max(res, f[i]);
        cout << res << endl;
    }
}

/*
 2
 3
 1 8 2
 4
 10 7 6 14
 */

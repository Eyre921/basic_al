#include <iostream>
#include <string.h>
#include <string>
using namespace std;

const int N = 100010;
int n, T;
int home[N], mem[N];
//若想要记忆化搜索，那么dfs的参数要尽可能少
//不应该把没有影响到边界的参数放进来
//想要剪枝，就要把尽可能能剪枝的参数写上来
//x表示当前正在考虑哪家店

int dfs(int x)
{
    if (mem[x]) return mem[x];
    int sum = 0;
    if (x > n) sum = 0;
    else sum = max(dfs(x + 1), dfs(x + 2) + home[x]); //+1不选当前，+2选
    mem[x] = sum;
    return sum;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &home[i]);
        memset(mem, 0, sizeof(mem));
        cout << dfs(1) << endl;
    }
}

/*
 2
 3
 1 8 2
 4
 10 7 6 14
 */

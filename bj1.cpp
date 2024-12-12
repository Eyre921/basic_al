#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
int n;
const int N = 100010;
int a, b, c;

struct pp {
    int num;
    int a;
    int b;
    int v;
};

pp p[N];

bool cmp(pp a1, pp b1) {
    return a1.v > b1.v;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d %d%d", &a, &b, &c);
        p[i] = {a, b, c, b + c};
    }
    sort(p, p + n, cmp);
    printf("%d %d %d %d\n", p[1].num, p[1].a, p[1].b, p[1].v);
}

/*
*牛奶中含有多种营养物质。假设现在要通过营养物质含量多少来评价牛奶的价值，简单起见，只考虑其中两种营养物质：A为钙、B为蛋白质。给定一种牛奶A和B的含量a和b，用a+b的值作为该水果的价值。给定一组牛奶，要求选出这组牛奶中价值第二高的那种牛奶。

【输入形式】

第一行为N,表示有N种牛奶，N<100000。

接着的N行每行三个非负整数，分别是牛奶ID、该牛奶的a和b。（a和b均<10000）（输入保证没有价值相同的牛奶）

【输出形式】

输出价值第二高的牛奶ID以及对应的a、b和价值，共4个非负整数，中间用一个空格隔开。

【样例输入】

3

1 1 1

2 2 4

3 3 2

【样例输出】

3 3 2 5

【样例说明】

最高的牛奶ID是2，价值为6，第二高的牛奶ID是3，价值为5。
 **/
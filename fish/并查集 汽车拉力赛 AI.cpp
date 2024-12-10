#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 定义一个结构体来表示边
struct Edge {
    int u, v, diff;
};

// 并查集结构体
struct UnionFind {
    vector<int> parent;
    vector<int> rank;
    vector<bool> has_marker;

    UnionFind(int size, const vector<int>& markers) : parent(size), rank(size, 0), has_marker(size, false) {
        for(int i = 0; i < size; ++i){
            parent[i] = i;
        }
        // 初始化包含路标的集合
        for(auto marker : markers){
            has_marker[marker] = true;
        }
    }

    // 查找根节点，并进行路径压缩
    int find_set(int x) {
        if(parent[x] != x)
            parent[x] = find_set(parent[x]);
        return parent[x];
    }

    // 合并两个集合，并返回是否减少了路标连通组件
    bool union_set(int x, int y) {
        int fx = find_set(x);
        int fy = find_set(y);
        if(fx == fy) return false;

        // 按秩合并
        if(rank[fx] < rank[fy]){
            parent[fx] = fy;
            // 如果两个集合都包含路标，合并后连通组件减少
            if(has_marker[fx] && has_marker[fy]){
                has_marker[fy] = true;
                return true;
            }
            if(has_marker[fx] || has_marker[fy]){
                has_marker[fy] = true;
            }
        }
        else{
            parent[fy] = fx;
            if(rank[fx] == rank[fy]) rank[fx]++;
            // 如果两个集合都包含路标，合并后连通组件减少
            if(has_marker[fx] && has_marker[fy]){
                has_marker[fx] = true;
                return true;
            }
            if(has_marker[fx] || has_marker[fy]){
                has_marker[fx] = true;
            }
        }
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M; // 输入网格的行数N和列数M

    // 读取海拔高度
    vector<vector<int>> high(N, vector<int>(M));
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            cin >> high[i][j];

    // 读取路标信息，并记录所有路标的位置
    vector<vector<int>> flag(N, vector<int>(M));
    vector<int> markers; // 存储所有路标的一维编号
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j) {
            cin >> flag[i][j];
            if(flag[i][j] == 1)
                markers.push_back(i * M + j); // 将二维坐标转化为一维编号
        }

    int total_markers = markers.size();
    if(total_markers <= 1 ){
        cout << 0 << "\n"; // 如果路标数量少于等于1，难度系数为0
        return 0;
    }

    // 定义所有可能的边
    vector<Edge> edges;

    // 遍历网格，添加所有相邻单元格的边
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            int current = i * M + j;
            // 向右
            if(j < M-1){
                int neighbor = i * M + (j+1);
                int diff = abs(high[i][j] - high[i][j+1]);
                edges.push_back(Edge{current, neighbor, diff});
            }
            // 向下
            if(i < N-1){
                int neighbor = (i+1) * M + j;
                int diff = abs(high[i][j] - high[i+1][j]);
                edges.push_back(Edge{current, neighbor, diff});
            }
        }
    }

    // 按照高度差从小到大排序
    sort(edges.begin(), edges.end(), [&](const Edge &a, const Edge &b) -> bool {
        return a.diff < b.diff;
    });

    // 初始化并查集
    UnionFind uf(N * M, markers);

    // 初始的连通组件数量
    int connected_components = total_markers;

    // 遍历所有边，逐步合并
    for(auto &edge : edges){
        bool merged = uf.union_set(edge.u, edge.v);
        if(merged){
            connected_components--;
            if(connected_components == 1){
                cout << edge.diff << "\n"; // 当前的高度差即为最小难度系数D
                return 0;
            }
        }
    }

    // 如果所有路标无法连接，输出-1（根据题目可能不会出现）
    cout << -1 << "\n";
    return 0;
}

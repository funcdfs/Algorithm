// 将所有边按照权重从小到 大进行排序
// 枚举每条边 a 到 b 权重是 c
// if a b 不连通，将这条边加入集合中 （并查集：连通块中点的数量）
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;
int n, m;
int p[N];

struct Edge {
    int a, b, w;
    bool operator<(const Edge &W) { return w < W.w; }
} es[M];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal() {
    sort(es, es + m);
    for (int i = 1; i <= n; i++) p[i] = i;
    
    int ans = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int a = es[i].a, b = es[i].b, w = es[i].w;
        a = find(a), b = find(b);
        if (a != b) {
            p[a] = b;
            cnt ++;
            ans += w;
        }
    }
    if (cnt + 1 < n) return INF;
    return ans;
}

int main() {
    cin >> n >> m; 
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        es[i] = {a, b, w};
    }
    int t = kruskal();
    if (t == INF) {
        cout << "impossible" << endl;
    } else {
        cout << t << endl;
    }
    
    return 0;
}
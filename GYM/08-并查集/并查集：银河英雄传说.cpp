// Problem: 银河英雄传说
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/240/
// date: 2022-03-13 16:08:06
// Memory Limit: 64 MB
// Time Limit: 2000 ms

/* https://github.com/fengwei2002/algorithm */

#define INF 0x3f3f3f3f
#define LL long long
#define PII pair<int, int>

// for debug:

// #define d(a)  // cout << #a << " = " << a << ' ';
// #define dline // cout << " ----- " << endl;
// #define dendl // cout << " | \n";

#define d(a) cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 3e4 + 10;

int m;
int p[N];     // 并查集数组
int sz[N];    // 存储每个并查集中存储的节点个数
int dist[N];  // d 是每个点距离根节点的距离

int find(int x) {
    if (p[x] != x) {
        int root = find(p[x]); // 找出具体的根节点
        dist[x] += dist[p[x]]; // 把 dist[p[x]] 累加到 d[x] 中  
        p[x] = root;           // p[x] 更新为 root 
    }
    return p[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> m;
    for (int i = 1; i <= N; i++) {
        p[i] = i;
        sz[i] = 1;
        dist[i] = 0;
    }

    while (m--) {
        string op;
        cin >> op;
        int a, b;
        cin >> a >> b;
        if (op == "M") {
            int pa = find(a);
            int pb = find(b);

            dist[pa] += sz[pb];  // pa 的深度变为 sz[pb] 自己用
            sz[pb] += sz[pa];    // sz[pb] += sz[pa] 供接到他后面的使用
            p[pa] = pb;          // 更新新的节点到 pb
        } else {
            int pa = find(a);
            int pb = find(b);
            if (pa != pb) {
                cout << "-1" << endl;
            } else {
                cout << max(0, abs(dist[a] - dist[b]) - 1) << endl;
                // 求出间隔飞船的个数
            }
        }
    }

    return 0;
}
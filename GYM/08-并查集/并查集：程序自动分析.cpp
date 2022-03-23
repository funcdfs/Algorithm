// Problem: 程序自动分析
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/239/
// date: 2022-03-12 15:24:19 
// Memory Limit: 64 MB
// Time Limit: 3000 ms

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int N = 2e6 + 10;

int n, m;
int p[N];
unordered_map<int, int> hs;

struct Query {
    int x, y, e;
};

Query query[N];

int get(int x) {
    if (hs.count(x) == 0) hs[x] = ++n;
    return hs[x];
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int t = 0;
    cin >> t; 
    while (t--) {
        n = 0;
        hs.clear();
        cin >> m;
        
        for (int i = 0; i < m; i++) {
            int x, y, e;
            cin >> x >> y >> e;
            query[i] = {get(x), get(y), e};
            // 离散化读入数据
        }
        
        for (int i = 1; i <= n; i++) p[i] = i;
        // 初始化并查集
        
        // 合并所有的相等的约束条件
        for (int i = 0; i < m; i++) {
            if (query[i].e == 1) {
                int pa = find(query[i].x);
                int pb = find(query[i].y);
                p[pa] = pb;
            }
        }
        
        // 检查所有的不相等的条件，是否会发生冲突 
        bool hasConflict = false;
        for (int i = 0; i < m; i++) {
            if(query[i].e == 0) {
                int pa = find(query[i].x);
                int pb = find(query[i].y);
                if (pa == pb) {
                    hasConflict = true; 
                    break;
                }
            }
        }
        
        if (hasConflict == true) {
            puts("NO");
        } else {
            puts("YES");
        }
    }
    
    return 0;
}
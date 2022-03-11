// Problem: 医院设置
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1257/
// date: 2022-03-03 14:36:32
// Memory Limit: 64 MB
// Time Limit: 1000 ms


/* https://github.com/fengwei2002/algorithm */

#define INF 0x3f3f3f3f
#define LL long long
#define PII pair<int, int>

// for debug:

// #define d(a)  // cout << #a << " = " << a << ' ';
// #define dline // cout << " ----- " << endl;
// #define dendl // cout << " | \n";

#define d(a)  cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 110, M = N * 2;

int n;
int cnt[N];
int h[N], e[M], ne[M], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}


int dfs(int u, int father, int dist) { // u 节点存储当前节点，father 存储从哪里来
    int sum = cnt[u] * dist;
    
    for (int i = h[u]; ~i; i++) {
        int j = e[i];
        if (j == father) continue;
        sum += dfs(j, u, dist + 1);
    }
    
    return sum;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n; // 读入所有节点的个数
    
    // 建立一个医院
    // 使得所有居民所走的路程之和最小
    // 医院中的居民移动距离为 0
    
    memset(h, -1, sizeof h);
    
    for (int i = 1; i <= n; i++) {
        int l, r; 
        cin >> cnt[i] >> l >> r;
        if (l) add(i, l), add(l, i); // 连接双向边
        if (r) add(i, r), add(r, i);
    }
    
    
    int ans = INF;
    for (int i = 1; i <= n; i++) {
         ans = dfs(i, -1, 0);
    }
    
    cout << ans << endl;
    
    return 0;
}



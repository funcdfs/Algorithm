// Problem: 1347：【例4-8】格子游戏
// Contest: SSOIER
// URL: http://ybt.ssoier.cn:8088/problem_show.php?pid=1347
// date: 2022-03-12 14:27:27
// Memory Limit: 65 MB
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

using namespace std;

const int N = 40010; // 点的数量最多是 n^2 个点

int n, m;
int p[N];

int find(int x) {
    if (p[x] != x) {
        p[x] = find(p[x]);
    }
    return p[x];
}

int get(int x, int y) {
    return x * n + y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    // 执行每一步连边的时候，第一次形成环的地方在哪 
    
    // 当两个点已经存在于一个集合中，那么这两个点再连一条边就是游戏结束了（形成了一个具体的环）
    // 也就是从前往后进行合并，合并到第一次出现环为止
    
    // x y 都是从 0 开始的话： (x, y) = x * n + y 
    for (int i = 0; i < n * n; i++) p[i] = i; // 初始化并查集
    
    int ans = 0;
    
    for (int i = 1; i <= m; i++) {
        int x, y;
        string d;
        cin >> x >> y >> d; 
        x--, y--; // 对下标做一个映射
        
        int a = get(x, y); // a 表示坐标对应的编号
        int b;
        if (d == "D") { // 往下走
            b = get(x + 1, y);
        } else { // 往右走
            b = get(x, y + 1);
        }
        
        int pa = find(a);
        int pb = find(b);
        
        if (pa == pb) { // 说明 pa 和 pb 在一个集合中
            ans = i;
            break;
        }
        p[pa] = pb; // 否则将 pa 和 pb 进行合并
    }
    
    if (ans == 0) {
        // 说明没有形成环，输出平局
        cout << "draw" << endl;
    } else {
        cout << ans << endl;
    }
    
    return 0;
}
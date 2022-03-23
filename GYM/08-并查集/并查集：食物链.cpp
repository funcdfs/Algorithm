// Problem: 食物链
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/242/
// date: 2022-03-14 20:18:00
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

using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N];
int d[N];


int find(int x) {
    if (p[x] != x) {
        int t = find(p[x]); // 记录根节点
        d[x] += d[p[x]];    // 更新 d[x] 的距离为两段相加
        p[x] = t;           // 将 p[x] 移动到应该存在的根节点的位置
    }
    return p[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        p[i] = i; 
        d[i] = 0;
    } // 初始化并查集 
    
    int ans = 0;
    while (m--) {
        int t, x, y; 
        cin >> t >> x >> y;
        if (x > n || y > n) {
            // 超出了数据范围，是假话
            ans++;
        } else {
            int px = find(x);
            int py = find(y);
            if (t == 1) {
                if (px == py && (d[x] - d[y]) % 3 != 0) {
                    ans++;
                } else if (px != py) {
                    p[px] = py;
                    d[px] = d[y] - d[x];
                } 
            } else {
                if (px == py && (d[x] - d[y] - 1) % 3 != 0) {
                    // 判断 x 和 y 的关系是否满足 x 吃 y 
                    ans++;
                } else if (px != py) {
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    cout << ans << endl;
        
    return 0;
}
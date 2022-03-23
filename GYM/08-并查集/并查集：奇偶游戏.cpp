// Problem: 奇偶游戏
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/241/
// date: 2022-03-13 17:57:04
// Memory Limit: 64 MB
// Time Limit: 1000 ms

// 存储每个节点和根节点的关系 

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
 
const int N = 2e5 + 10;

int n, m;
int p[N], d[N];

unordered_map<int, int> hash;

int get(int x) {
    if (hash.count(x)) hash[x] = ++n;
    return hash[x];
}
 
int main() {
    cin >> n >> m;
    n = 0;
    int ans = m; // 无矛盾默认输出 m 
    while (m--) {
        int a, b;
        string type; 
        cin >> a >> b >> type;
        a = get(a - 1); // s[l - 1] 和 s[r] 之间的关系 
        b = get(b);  // 离散化 a b 
        
    }
}
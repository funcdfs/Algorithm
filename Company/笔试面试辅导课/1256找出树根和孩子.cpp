// Problem: 找树根和孩子
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1256/
// date: 2022-03-03 13:06:18
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

const int N = 1010;
int n, m;
bool st[N]; // 存储每个点是否存在父节点
vector<int> g[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int father, son;
        cin >> father >> son; 
        st[son] = true; 
        // 儿子节点存在父节点
        g[father].push_back(son); 
        // 放入 father 的数组后面
    }
    // 所以就可以根据 st 数组和 g 数组的长度是否大于 0 来判断这个点是否存在
    
    // 寻找根节点
    for (int i = 1; i <= 1000; i++) {
        if (st[i] || g[i].size()) {
            if (!st[i]) {
                cout << i << endl;
                break;
            }
        }
    }
    
    // 寻找节点数量最多的一个点
    int p = 1;
    for (int i = 2; i <= 1000; i++) {
        if (g[i].size() > g[p].size()) {
            p = i;
        }
    }
    cout << p << endl;
    sort(g[p].begin(), g[p].end());
    for (auto x : g[p]) cout << x << ' ';
    cout << endl;
    
    // 输出格式：
    // - 树根
    // - 孩子最多的节点 max 
    // - max 的孩子 (由小到大排序)
    
    // 这个题目可以学习如何进行图的存储
    return 0;
}
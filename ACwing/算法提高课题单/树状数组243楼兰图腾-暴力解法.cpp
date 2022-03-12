// Problem: 楼兰图腾
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/243/
// date: 2022-03-10 12:32:23
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
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 10;

int n;
int a[N];
int tree[N];

int ll[N];
int rl[N];
int lg[N];
int rg[N];
 
// 树状数组的三个函数-----------------------------------------

int lowbit(int i) { // lowbit 函数 
    return i & (-i);
}

void add(int x, int c) { // 将序列中的第 x 个数字加上 k, 更新 tr 
    for (int i = x; i <= n; i += lowbit(i)) {
        tree[i] += c;
    }
}

int sum(int x) { // 查询序列前 x 个数字的和 
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) {
        ans += tree[i];
    }
    return ans;
}
// -----------------------------------------------------------
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // 统计低洼的数量
    LL ans1 = 0;
    // 统计山峰的数量
    LL ans2 = 0;
    
    // 统计左侧的信息
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) ll[i]++;
            else lg[i]++;
        }
    }
    
    // 统计右侧的信息
    for (int i = 1; i <= n; i++) {
        for (int j = n; j > i; j--) {
            if (a[j] < a[i]) rl[i]++;
            else rg[i]++;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        ans1 += (LL)lg[i] * rg[i];
        ans2 += (LL)ll[i] * rl[i];
    }
    
    cout << ans1 << " " << ans2 << endl;
    
    return 0;
}
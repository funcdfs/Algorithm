// Problem: 楼兰图腾
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/243/
// date: 2022-03-10 12:32:23
// Memory Limit: 64 MB
// Time Limit: 1000 ms

/* https://github.com/fengwei2002/algorithm */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;
int a[N];
int low[N];
int gre[N];
int tree[N];
int n;

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i)) tree[i] += c;
}

int ask(int x) {
    int sum = 0;
    for (int i = x; i; i -= lowbit(i)) {
        sum += tree[i];
    }
    return sum;
}

int main() {
    typedef long long LL;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 1; i <= n; i++) {
        int y = a[i];
        low[i] = ask(y - 1);     // 统计 a[i] 之前放入的元素中, 比 a[i] 小的数字的总数
        gre[i] = ask(n) - ask(y);// 统计 a[i] 后面放入的元素中, 比 a[i] 大的数字的总数
        add(y, 1);               // 将 a[i] 加入树状数组中
    }
    
    memset(tree, 0, sizeof tree);
    LL ans1 = 0, ans2 = 0;
    for (int i = n; i >= 1; i--) {
        int y = a[i];
        ans1 += (LL)gre[i] * (ask(n) - ask(y));
        ans2 += (LL)low[i] * ask(y - 1);
        add(y, 1);
    }
    
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}
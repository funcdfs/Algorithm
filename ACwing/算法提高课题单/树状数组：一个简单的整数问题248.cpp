// Problem: 一个简单的整数问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/248/
// date: 2022-03-12 08:27:13
// Memory Limit: 64 MB
// Time Limit: 1000 ms


/* https://github.com/fengwei2002/algorithm */

#include <iostream>

using namespace std;

const int N = 1e5 + 10;
typedef long long LL;

int a[N];
int b[N];
LL tr[N];
int n, m;

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i)) {
        tr[i] += c;
    }
}

LL sum(int x) {
    LL ans = 0;
    for (int i = x; i; i -= lowbit(i)) {
        ans += tr[i];
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i]; 
    for (int i = 1; i <= n; i++) insert(i, i, a[i]); // 构建差分数组
    for (int i = 1; i <= n; i++) add(i, b[i]);       // 构建树状数组

    while (m--) {
        string op;
        cin >> op;
        if (op == "C") {
            int l, r, d;
            cin >> l >> r >> d;
            add(l, d);      // 单点修改差分数组
            add(r + 1, -d);
        } else if (op == "Q") {
            int x;
            cin >> x;
            cout << sum(x) << endl; 
            // 从差分数组的定义出发，a[x] 是差分数组前 x 项的和，输出 sum(x) 即可
        }
    }
    return 0;
}

// 树状数组适用的问题：单点加求区间和
// 这个问题是区间加，求单点和

// 预处理一个差分数组 
// 这样的话，给原数组中的一个区间加上一个和的操作就可以转换为
// 在差分数组中的操作 b[l] += c, b[r+1] -= c;
// 等价于在差分数组中更改两个点的值

// 在元素组中查询一个值的操作可以转换为 
// 对差分数组求前缀和， 直接使用树状数组的 sum() 函数即可
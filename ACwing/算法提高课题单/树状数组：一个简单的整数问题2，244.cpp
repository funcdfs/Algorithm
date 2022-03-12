// Problem: 一个简单的整数问题2
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/244/
// date: 2022-03-12 09:55:03
// Memory Limit: 64 MB
// Time Limit: 1000 ms


/* https://github.com/fengwei2002/algorithm */

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
typedef long long LL;

int n, m;
LL tr1[N]; // 维护 b[i] 的前缀和
LL tr2[N]; // 维护的是 b[i]*i 的前缀和
int a[N];
int b[N];

int lowbit(int x) {
    return x & (-x);
}

void add(LL tr[], int x, LL c) {
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

LL sum(LL tr[], int x) {
    LL ans = 0;
    for (int i = x; i; i -= lowbit(i)) ans += tr[i];
    return ans;
}

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

LL prefixSum(int x) {
    return sum(tr1, x) * (x + 1) - sum(tr2, x);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) insert(i, i, a[i]);
    
    for (int i = 1; i <= n; i++) {
        add(tr1, i, b[i]);
        add(tr2, i, (LL)b[i] * i);    
    }
    
    while (m--) {
        string op;
        cin >> op;
        if (op == "C") {
            int l, r, d;
            cin >> l >> r >> d;
            add(tr1, l, d);      add(tr2, l, l * d);
            add(tr1, r + 1, -d); add(tr2, r + 1, (r + 1) * -d);
        } else if (op == "Q") {
            int l, r;
            cin >> l >> r;
            cout << prefixSum(r) - prefixSum(l - 1) << endl;
        }
    }
    
    return 0;
}
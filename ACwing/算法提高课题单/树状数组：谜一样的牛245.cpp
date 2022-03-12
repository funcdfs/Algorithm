// Problem: 谜一样的牛
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/245/
// date: 2022-03-12 10:17:10
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

typedef long long LL;
int n;
int h[N];
int ans[N];
LL tr[N];

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
    cin >> n;
    for (int i = 2; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) add(i, 1);
    
    for (int i = n; i; i--) {
        int k = h[i] + 1;
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (sum(mid) >= k) r = mid;
            else l = mid + 1;
        }
        ans[i] = r;
        add(r, -1);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
    return 0;
}
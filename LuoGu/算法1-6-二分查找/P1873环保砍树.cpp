// Problem: P1873 [COCI 2011/2012 #5] EKO / 砍树
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1873
// date: 2022-02-09 14:41:30
// Memory Limit: 125 MB
// Time Limit: 1000 ms

/* https://github.com/fengwei2002/algorithm */

#define INF 0x3f3f3f3f
#define LL long long
#define PII pair<int, int>
// for dbg:
#define d(a)  // cout << #a << " = " << a << ' ';
#define dline // cout << " ----- " << endl;
#define dendl // cout << " | \n";

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e6 + 10;
int n;
LL m;
int a[N];

bool check(int mid) {
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        int val = 0;
        if (a[i] > mid) {
            val = a[i] - mid;
        } else {
            val = 0;
        }
        ans += val;
        d(val) dline
    }
    d(mid) d(ans) dline return ans >= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int maxVal = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) maxVal = max(maxVal, a[i]);

    // 找出锯子的最大高度使得可以获得 m 的木材
    int l = 0, r = maxVal;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid) == true) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << r << endl;

    return 0;
}
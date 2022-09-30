// LINK: https://atcoder.jp/contests/abc065/tasks/abc065_b
// NAME: B - Trained?, AtCoder - AtCoder Beginner Contest 065
// DATE: 2022.09.19 16:31:31, LIMIT: 256 MB, 2000 ms

#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int n = 0;
    cin >> n; 
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<bool> st(n + 1, false);
    st[1] = true;

    int lightCnt = 1;
    int light = 1;
    while (lightCnt <= n) {
        int b = a[light];
        st[b] = true;
        light = b; 
        if (b == 2) {
            cout << lightCnt << '\n';
            return 0;
        }
        lightCnt++;
        // for (auto x : st) cerr << x << ' '; cerr << '\n';
    } 
    if (lightCnt >= n) {
        cout << -1 << '\n';
    }

    return 0;
}

/*

abc065_b是否可以以第二个按钮亮起来的状态结束


如果可能，找到按的最小的数量

*/
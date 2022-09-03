// LINK: https://codeforces.com/contest/330/problem/B
// NAME: B. Road Construction, Codeforces - Codeforces Round #192 (Div. 2)
// DATE: 2022-08-30 11:48:38, LIMIT: 256 MB, 2000 ms

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*----------------------------------*/

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int n = 0, m = 0;
    cin >> n >> m;
    unordered_set<int> S;

    for (int i = 0; i < m; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        S.insert(a);
        S.insert(b);
    }

    int x = n >> 1;
    if (n % 2) {
        x++; 
    }
    int mid = -1;
    
    if (S.contains(x) == false) {
        mid = x;
    } else {
        int i = x - 1;
        int j = x + 1;
        while (i >= 1 && j <= n) {
            if (S.contains(i) == false) {
                mid = i;
                break;
            } else if (S.contains(j) == false) {
                mid = j;
                break;
            } else {
                i--;
                j++;
            }
        }
    }
    // find the mid node, then, 
    // the left side is connected to the mid, 
    // and the right side have same treatment

    cout << (mid - 1) + (n - mid) << '\n';
    if ((mid - 1) + (n - mid) == 0) { 
        // do nothing. have no edge
    } else {
        for (int i = 1; i < mid; i++) {
            cout << i << ' ' << mid << '\n';
        }

        for (int i = mid + 1; i <= n; i++) {
            cout << mid << ' ' << i << '\n';
        }
    }

    return 0;
}

/*

330B两步到达任意城市的最小的路线数量



从每一个城市到另外一个城市最多走两个路线
给定 m pairs of cities
路线不可以在给出的两个 pair 中间构建

建造最少的路的数量，使得仍然满足上述条件


*/
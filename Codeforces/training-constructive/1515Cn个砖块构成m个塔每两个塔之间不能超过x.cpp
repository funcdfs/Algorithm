// LINK: https://codeforces.com/contest/1515/problem/C
// NAME: C. Phoenix and Towers, Codeforces - Codeforces Global Round 14
// DATE: 2022.09.14 22:51:15, LIMIT: 256 MB, 2000 ms
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

    int tt = 0;
    cin >> tt;
    while (tt--) {
        int n = 0, m = 0, x = 0;
        cin >> n >> m >> x;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<pair<int, int>> aa(n);
        for (int i = 0; i < n; i++) {
            aa[i] = {a[i], i};
        }
        sort(aa.begin(), aa.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first > b.first;
        });
        unordered_map<int, int> hs; 
        // use hs to record index in final towel
        
        vector<int> b(m, 0);
        // b is the final towel height array
        
        int loop = n % m ? n / m + 1 : n / m;
        int idx = 0;
        bool right = true;
        while (loop--) {
            if (right == true) {
                for (int i = 0; i < m; i++) {
                    b[i] += aa[idx].first;
                    hs[aa[idx].second] = i + 1; 
                    idx++;
                    if (idx == n) break;
                }
                if (idx == n) break;
                right = false;
            } else if (right == false) {
                for (int i = m - 1; i >= 0; i--) {
                    b[i] += a[idx];
                    hs[aa[idx].second] = i + 1; 
                    idx++;
                    if (idx == n) break;
                }
                if (idx == n) break;
                right = true;
            }
        }
        bool ok = true;
        for (int i = 1; i + 1 < m; i++) {
            if (abs(a[i] - a[i - 1]) > x || abs(a[i + 1] - a[i]) > x) {
                ok = false;
                break;
            }
        }

        if (ok == false) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                cout << hs[i] << " \n"[i == n - 1]; 
            }
        }
    }
    return 0; 
}

/*

1515Cn个砖块构成m个塔每两个塔之间不能超过x

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220914235157.png)

*/
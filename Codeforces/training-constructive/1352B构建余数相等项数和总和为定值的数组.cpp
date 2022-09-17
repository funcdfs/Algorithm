// LINK: https://codeforces.com/contest/1352/problem/B
// NAME: B. Same Parity Summands, Codeforces - Codeforces Round #640 (Div. 4)
// DATE: 2022-09-08 14:32:30, LIMIT: 256 MB, 1000 ms

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int tt = 0;
    cin >> tt;
    while (tt--) {
        int n = 0, k = 0;
        cin >> n >> k;

        vector<int> ans;

        auto solve1 = [&](int n, int k) {
            int t = n; 
            n -= (k - 1) * 1; 
            if (n % 2 == 0 || t < k) {
                return false;
            }
            while (k--) {
                ans.push_back(1); 
            }
            ans.pop_back();
            ans.push_back(n);
            return true;
        };
        // 全部放余数为 1 的

        auto solve2 = [&](int n, int l) {
            int t = n; 
            n -= (k - 1) * 2; 
            if (n % 2 == 1 || t < k * 2) {
                return false;
            }
            while (k--) {
                ans.push_back(2);
            }
            ans.pop_back();
            ans.push_back(n);
            return true;
        };
        // 全部放余数是 2 的

        if (solve1(n, k)) {
            cout << "YES\n";
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] << " \n"[i == ans.size() - 1];
            }
        } else if (solve2(n, k)) {
            cout << "YES\n";
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] << " \n"[i == ans.size() - 1];
            }
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

/*

1352B构建余数相等项数和总和为定值的数组

*/
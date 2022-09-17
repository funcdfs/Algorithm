#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

int trans(vector<int>& a) {
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        ans = ans * 10 + a[i];
    }
    return ans;
}

int findMaxNum(vector<int>& a, vector<int>& b) {
    int maxVal = *max_element(a.begin(), a.end());
    function<int(int)> find1st = [&](int val) {
        int x = -1;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] <= val) {
                x = a[i];
            }
        }
        return x;
    };
    function<int(int)> find2nd = [&](int val) {
        int x = -1;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] < val) {
                x = a[i];
            }
        }
        return x;
    };
    /* ------------------------------------ */

    int ans = 0;
    function<void(vector<int>&, int)> dfs = [&](vector<int>& path, int lastIdx) {
        dbg(path, lastIdx);
        if (path == b) {
            path.pop_back();
            lastIdx = path.size();
            dbg(1);
            dfs(path, lastIdx);
        }

        if (path.size() == b.size()) {
            ans = trans(path);
            return;
        }

        int v = b[path.size()];
        if (lastIdx != -1) {
            int t = find2nd(v);
            if (t != -1) {
                path.push_back(t);
                int len = path.size();
                dbg(path);
                for (int i = 0; i < b.size() - len; i++) {
                    path.push_back(maxVal);
                }
                dbg("after", path);
                ans = trans(path);
                return;
            } else {
                // not exist 2nd, only have 1st or nil
                path.pop_back();
                lastIdx--;
                dfs(path, lastIdx);
            }
        } else {
            int t = find1st(v);
            if (t != -1) {
                path.push_back(t);
                dfs(path, -1);
            } else {
                path.clear();
                for (int i = 0; i < b.size() - 1; i++) {
                    path.push_back(maxVal);
                }
                ans = trans(path);
                return;
            }
        }
        return;
    };

    vector<int> c(0, 0);
    dfs(c, -1);
    return ans;
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> a(0, 0);
    for (int x = 0; cin >> x;) {
        a.push_back(x);
    }

    vector<int> b;
    while (n) {
        b.push_back(n % 10);
        n /= 10;
    }
    reverse(b.begin(), b.end());
    cout << findMaxNum(a, b);

    return 0;
}

/*
(45)[path, lastIdx]: [{}, -1]
(45)[path, lastIdx]: [{3}, -1]
(45)[path, lastIdx]: [{3, 2}, -1]
(45)[path, lastIdx]: [{3, 2, 1}, -1]
(50)[1]: [1]
(45)[path, lastIdx]: [{3, 2}, 2]
(45)[path, lastIdx]: [{3}, 1]
(65)[path]: [{3, 1}]
(69)["after", path]: [after, {3, 1, 3}]

321
1 2 3

313
*/
// LINK: https://codeforces.com/contest/1393/problem/B
// NAME: B. Applejack and Storages, Codeforces - Codeforces Round #662 (Div. 2)
// DATE: 2022.09.14 14:42:04, LIMIT: 256 MB, 2000 ms

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
    cin.tie(0)->sync_with_stdio(false);

    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    // unordered_map<int, int> mp; but: unordered_map is faster
    map<int, int> mp; 
    // don't use unordered_map in contest because: https://codeforces.com/blog/entry/62393
    
    int r2 = 0, r4 = 0; 
    for (int i = 0; i < n; i++) {
        mp[a[i]]++; 
        if (mp[a[i]] % 2 == 0) r2 += 1, dbg(i, a[i]); 
        if (mp[a[i]] % 4 == 0) r4 += 1; 
    }
    dbg("init", r2, r4); 
    int q = 0; 
    cin >> q;
    string s; 
    int x = 0; 
    for (int i = 0; i < q; i++) {
        cin >> s >> x; 
        if (s == "+") {
            mp[x]++;
            if (mp[x] % 2 == 0) r2++; 
            if (mp[x] % 4 == 0) r4++; 
        } else {
            if (mp[x] % 2 == 0) r2--; 
            if (mp[x] % 4 == 0) r4--; 
            mp[x]--;
        }
        dbg(r2, r4); 
        // one r4 can add two value in r2
        cout << (r2 - 2 >= 2 and r4 >= 1 ? "YES\n" : "NO\n"); 
    }
    return 0;
}

int main_模拟() {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<int, int> hs;
    for (auto& x : a) {
        hs[x]++;
    }

    int q = 0;
    cin >> q;
    while (q--) {
        char op;
        int x;
        cin >> op >> x;
        if (op == '+') {
            hs[x]++;
        } else if (op == '-') {
            hs[x]--;
        }
        auto trans = [hs]() {
            int evenCnt = 0;
            int squreCnt = 0;
            for (auto& [_, v] : hs) {
                if (v >= 8) {
                    return true;
                } else {
                    if (v >= 6) {
                        squreCnt++;
                        evenCnt++;
                    } else if (v >= 4) {
                        squreCnt++;
                    } else if (v >= 2) {
                        evenCnt++;
                    }
                }
                if (squreCnt >= 2 || (squreCnt >= 1 && evenCnt >= 2)) {
                    return true;
                }
            }
            return false;
        };

        if (trans()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

/*

1393B创建一个正方形仓库和长方形仓库

不是每次去遍历一遍整个哈希表，而是动态的维护 可以除以 2 的数量，和可以除以 4 的数量

*/
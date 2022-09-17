// LINK: https://codeforces.com/contest/1353/problem/D
// NAME: D. Constructing the Array, Codeforces - Codeforces Round #642 (Div. 3)
// DATE: 2022.09.13 23:14:44, LIMIT: 256 MB, 1000 ms

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
        int n = 0; 
        cin >> n; 
        vector<int> a(n, 0); 
        using pii = pair<int, int>;
        function<bool(pii&, pii&)> cmp = [](pii& a, pii& b) {
            if (a.second - a.first == b.second - b.first) {
                return a.first > b.first; 
            } // left edge smaller first 
            return a.second - a.first < b.second - b.first; // gap bigger smaller
        }; 
        priority_queue<pii, vector<pii>, function<bool(pii&, pii&)>> hp(cmp); 
        hp.push({0, n - 1});
        
        int cnt = 0; 
        while (hp.size()) {
            auto [l, r] = hp.top(); 
            hp.pop(); 
            auto mid = (l + r) / 2; 
            a[mid] = ++cnt;
            if (mid - 1 >= l) hp.push({l, mid - 1}); 
            if (mid + 1 <= r) hp.push({mid + 1, r}); 
        } 
        
        for (int i = 0; i < (int)a.size(); i++) {
            cout << a[i] << " \n"[i == (int)a.size() - 1]; 
        }
    }
    
    return 0;
}


/*

1353D每次拿一个序列折成两半放回去

使用自定义的优先级队列

维护具体的优先级为区间的对应的性质

*/
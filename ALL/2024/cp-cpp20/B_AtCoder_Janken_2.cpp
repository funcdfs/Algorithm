/**
 * name: B - AtCoder Janken 2
 * link: https://atcoder.jp/contests/abc354/tasks/abc354_b
 * time: 2024/5/18 20:06:48 https://github.com/funcdfs
 **/


#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */



auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int n = 0;
    cin >> n;
    vector<string> S(n);
    vector<int> C(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> S[i] >> C[i];
    }

    sort(S.begin(), S.end(), [](auto& a, auto& b) {
        return a < b;
    });

    int64_t sum = accumulate(C.begin(), C.end(), int64_t(0));
    int idx = sum % n;

    cout << S[idx]; 
    
    return 0;
}
/*

*/
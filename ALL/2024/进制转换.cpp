/**
 * author: https://github.com/funcdfs
 * created: 2024-04-01 21:10:05
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

vector<int> div(vector<int>& A, int b) {
    vector<int> C;
    for (int i = A.size() - 1, r = 0; i >= 0; i--) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r = r % b;
    }
    reverse(C.begin(), C.end());
    while (C.size() and C.back() == 0) {
        C.pop_back();
    }
    return C;
}

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    string s;
    while (cin >> s) {
        vector<int> A;
        for (int i = 0; i < s.size(); i++) {
            A.push_back(s[i] - '0');
        }
        reverse(A.begin(), A.end());
        string ans;
        if (s == "0") {
            ans = "0";
        } else {
            while (A.size()) {
                ans += to_string(A[0] % 2);
                A = div(A, 2);
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }

    return 0;
}
/*

*/
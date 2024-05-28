/**
 * author: https://github.com/funcdfs
 * created: 2024-04-10 13:03:47
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    string s = "";
    cin >> s;

    string ans = "";
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] >= '0' and s[i] <= '9') {
            int j = i;
            while (j < (int)s.size() and s[j] >= '0' and s[j] <= '9') {
                ans += s[j];
                j += 1;
            }
            break;
        }
    }
    function<string(string)> judge = [](string s) {
        string temp = "2147483647";
        if (s.size() < temp.size()) {
            return s.c_str();
        } else if (s.size() > temp.size()) {
            return "-1";
        } else if (s.size() < temp.size()) {
            for (int i = 0; i < (int)temp.size(); i++) {
                if (s[i] > temp[i]) {
                    return "-1";
                }
            }
        }
        return s.c_str();
    };
    ans = judge(ans);
    if ((int)ans.size() >= 1) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
/*

*/
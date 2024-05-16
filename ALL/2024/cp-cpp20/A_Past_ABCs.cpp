#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    auto check = [&]() -> bool {
        string s;
        cin >> s;
        if ((int)s.size() != 6) return false;
        bool st = (s[0] == 'A' and s[1] == 'B' and s[2] == 'C');
        if (st == false) {
            dbg("st", s);
            return false;
        }
        dbg(s);
        int num = 0;
        if (s[4] > '9' or s[4] < '0') return false;
        num += s[4] - '0';
        num *= 100;
        if (s[5] > '9' or s[5] < '0') return false;
        num += (s[5] - '0') * 10;
        if (s[6] > '9' or s[6] < '0') return false;
        num += (s[6] - '0');
        if (num >= 350) {
            return false;
        }
        dbg(num);
        return true;
    };
    if (check() == true) {
        cout << format("Yes\n");
    } else {
        cout << format("No\n");
    }

    return 0;
}
/*

*/
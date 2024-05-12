#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int n = 0, m = 0;
    cin >> n >> m;

    int nn = n, mm = m;

    auto C = [](int a, int b) -> int64_t {
        int64_t res = 1;
        for (int i = a, j = 1; j <= b; i--, j++) res = res * i / j;
        return res;
    };

    auto findMin = [&]() -> int64_t {
        int64_t ans = 0;
        if (n % m) {
            // 怎样处理余数，可以使得人数尽可能的平均
            // 令前 n mod m 组的人数为 [n / m] + 1，剩下的组，人数为 [n / m]; 
            int leftCnt = n % m;
            int rightCnt = m - leftCnt;
            int left = n / m + 1;
            int right = n / m;
            ans = leftCnt * C(left, 2) + rightCnt * C(right, 2);
        } else {
            int k = n / m;
            ans = C(k, 2) * m;
        }
        return ans;
    };

    cout << findMin() << ' ';
    n = nn, m = mm;
    auto findMax = [&]() -> int64_t {
        int len = m - 1;
        return C(n - len, 2);
    };

    cout << findMax();

    return 0;
}
/*

*/
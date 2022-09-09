// LINK: https://codeforces.com/contest/1348/problem/B
// NAME: B. Phoenix and Beauty, Codeforces - Codeforces Round #638 (Div. 2)
// DATE: 2022-09-09 12:08:04, LIMIT: 256 MB, 2000 ms

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
        int n = 0, k = 0;
        cin >> n >> k;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];

        function<bool()> trans = [&a, n, k]() -> bool {
            unordered_set<int> S;
            for (auto& x : a) S.insert(x);

            if (S.size() > k) {
                return false;
            }

            a.clear();
            for (auto x : S) {
                a.push_back(x);
            }

            int idx = 0;
            while (a.size() < k) {
                a.push_back(a[idx]);
                idx++;
            }
            // 把这一轮补满

            return true;
        };

        if (trans() == true) {
            cout << n * k << endl;
            for (int i = 0; i < n * k; i++) {
                cout << a[i % k] << " \n"[i == n * k - 1];
            }
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}

/*

1348B添加一些值使得数组变漂亮

所有长度是 k 个子数组的总和都是一个值的话，就是一个漂亮数组


构造之后的序列一定是 abcd....abcd....abcd.... 这样循环的
循环节的长度为 k 这样才能使得任意连续 k 个数字加起来都是 a + b + c + d + ...
也就是一个循环节的和
为了使得原序列中每一个数字都出现在构造之后的序列中，可以输出 n 个循环节

却下来的位置依次放入滑动窗口前面出去的元素

*/
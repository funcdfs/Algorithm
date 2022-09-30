// LINK: https://codeforces.com/contest/1360/problem/C
// NAME: C. Similar Pairs, Codeforces - Codeforces Round #644 (Div. 3)
// DATE: 2022-09-08 16:58:53, LIMIT: 256 MB, 2000 ms

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

bool splitPair(vector<int>& a) {
    int n = a.size();
    if (n % 2) {
        return false;
    }

    sort(a.begin(), a.end());
    int even = count_if(a.begin(), a.end(), [&](int x) { return x % 2 == 0; });
    if (even % 2 == 0) {
        return true;
    } else {
        bool ok = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i + 1] - a[i] == 1) {
                ok = true;
            }
        }
        if (ok == true) {
            return true;
        } else {
            return false;
        }
    }

    return false;
}

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int tt = 0;
    cin >> tt;
    while (tt--) {
        int n = 0;
        cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (splitPair(a) == true) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

/*

1360C将数组划分为相似的pair

xy 相同余数或者绝对值相差 1

给定 n 个整数，是否可以将这 n
个整数划分为若干对数字，使得每一对数字的奇偶性相同或者差值为 1

设数列中偶数的个数为 m，当 m 为偶数的时候，所有的偶数因为奇偶性相同，可以被分为
m / 2 对 总个数为偶数，所以奇数的个数也是偶数，所以可以直接 return true

当数列中出现的偶数的个数不是偶数的时候，就需要把数列进行排序，看看存不存在两个数字的差值为
1 的情况 只要两个数字的差值为 1， 那么去除这两个数字之后，就又变成了上面的情况

1: 排序
2: 统计出现的偶数的数量
3: 如果出现的偶数的数量是偶数，就直接返回 true
4: 否则，如果出现一次 a[i] == a[i + 1] - 1 的情况就返回 true

*/
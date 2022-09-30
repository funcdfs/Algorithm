// URL: https://codeforces.com/problemset/problem/1466/B
// NAME: B. Last minute enhancements, Codeforces - Good Bye 2020
// LIMIT: 256 MB, 1000 ms
// DATE: 2022-08-04 15:19:33

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 0;
    cin >> tt;
    while (tt--) {
        int n = 0;
        cin >> n;

        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> ans(0, 0);
        unordered_map<int, int> hash;
        for (auto& x : a) hash[x]++;

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        dbg(a);

        for (int i = a.size() - 1; i >= 0; i--) {
            int x = a[i];
            if (hash[x] == 1 && hash[x + 1] == 0) {
                ans.push_back(x + 1);
                hash[x]--;
                hash[x + 1]++;
            } else if (hash[x] > 1 && hash[x + 1] == 0) {
                ans.push_back(x + 1);
                ans.push_back(x);
                hash[x + 1] += hash[x] - 1;
                hash[x] = 1;
            } else if (hash[x] == 1 && hash[x + 1] > 0) {
                ans.push_back(x);
            } else if (hash[x] > 1 && hash[x + 1] > 0) {
                ans.push_back(x + 1);
                ans.push_back(x);
                hash[x + 1] += hash[x] - 1;
                hash[x] = 1;
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        dbg(ans);
        cout << ans.size() << endl;
    }

    return 0;
}

/*

最大音符多样性

可以对原序列进行加一或者不变

求可以产生的最大的种类的数量


从大到小考虑，因为大的数字一定不影响小的数字的作用域

如果 x 出现一次，并且 x+1 不存在
        将 x 变为 x+1
如果 x 出现多次，并且 x+1 不存在
        变为 x+1，剩一个 x 就行
如果 x 出现一次，并且 x+1 存在
        x 不变
如果 x 出现多次，并且 x+1 存在
        变为 x+1，剩下一个 x 就行

1
5
2 2 3 4 5
-----
5

~~~~~

5
6
1 2 2 2 5 6
2
4 4
6
1 1 3 4 4 5
1
1
6
1 1 1 2 2 2
----
5
2
6
1
3
*/
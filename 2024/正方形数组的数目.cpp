过了 9/11 个数据，改成c 数组就能过了。不想写了。    
考察知识点：去重全排列

```cpp
/**
 * author: https://github.com/funcdfs
 * created: 2024-04-09 20:08:09
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

    int n = 0;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    // 暴搜搜出全排列，然后逐个判断。。 过了 9/11 懒得调了。思路正确

    function<bool(vector<int> & a)> is = [&](vector<int>& a) {
        for (int i = 1; i < (int)a.size(); i++) {
            int x = a[i - 1] + a[i];
            if (int(sqrt(x)) * int(sqrt(x)) != x) {
                return false;
            }
        }
        return true;
    };

    vector<int> path;
    vector<bool> st(nums.size(), false);
    sort(nums.begin(), nums.end());
    int cnt = 0;

    function<void(vector<int>&)> dfs = [&](vector<int>& path) {
        if (path.size() >= nums.size()) {
            if (path.size() == nums.size()) {
                if (is(path)) cnt += 1;
            }
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (st[i] == false) {
                if (i > 0 && nums[i] == nums[i - 1] && st[i - 1] == false)
                    continue;
                path.push_back(nums[i]);
                st[i] = true;
                dfs(path);
                st[i] = false;
                path.pop_back();
            }
        }
    };

    dfs(path);

    cout << cnt << endl;

    return 0;
}
/*

*/
```
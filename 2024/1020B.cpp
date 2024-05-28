/**
 * name: B. Badge
 * link: https://codeforces.com/contest/1020/problem/B
 * time: 2024/5/17 16:50:34 https://github.com/funcdfs
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
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= 1;
    }

    vector<int> ans(0, 0);
    vector<bool> st(n, false);

    for (int i = 0; i < n; i++) {
        fill(st.begin(), st.end(), false);
        int me = i;
        while (st[me] == false) {
            st[me] = true;
            me = a[me];
        }
        ans.push_back(me);
    }

    for (int i = 0; i < n; i++) {
        cout << format("{0} ", ans[i] + 1);
    }
    cout << format("\n");
    
    return 0;
}
/*
给你 n 个学生，每个学生都指向另一个学生，要你求从每一个学生出发，沿着他指向的学生走，第一个出现两次的学生编号。
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif


/* ---------- class start ---------- */ 
// 1 更换类名





class DSU { // https://github.com/funcdfs
   private:
    vector<int> f, siz;  // father and size
   public:
    DSU() {}  // DSU dsu(N);
    DSU(int n) { init(n); }
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x) {  // dsu.find(i) == i
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {  // dsu.merge(A, B);
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[find(x)]; }  // s = dsu.size(i);
};



class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        vector<int> d(n, 0);
        for (auto& edge : edges) {
            int x = edge[0], y = edge[1];
            dsu.merge(x, y);
            d[x] += 1, d[y] += 1;
        }
        vector<bool> st(n, true);
        for (int i = 0; i < n; i++) {
            if (d[i] != 2) st[dsu.find(i)] = false;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i and st[dsu.find(i)] == true) {
                ans += 1;
            }
        }
        return ans;
    }
};








/* ---------- class end ---------- */ 
// 2 更换函数名
void check(Solution s, auto input) {
    auto ans = s.functionName(input);
    dbg("new Test: ", input, ans);
    cout << ans << endl;
}


auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    Solution solution;

// 3 测试数据

    /* 字符串输入， ---------- string test input ---------- */

    // auto input1 = "";
    // auto input2 = "";
    // auto input3 = "";

    /* test case */
    // check(solution, input3);
    // check(solution, input3);
    // check(solution, input3);

    /* ---------- string test input ---------- */



    /* 数字输入 ---------- Number test input ---------- */

    // auto input1 = xxx;
    // auto input2 = xxx;
    // auto input3 = xxx;

    /* test case */
    // check(solution, input1);
    // check(solution, input2);
    // check(solution, input3);

    /* ---------- Number test input ---------- */



    return 0;
}
/*

*/
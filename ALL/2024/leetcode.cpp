/**
 * author: https://github.com/funcdfs
 * created: 2024-04-21 12:42:38
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid.at(0).size();
        // 每一列所有元素中的最大元素，以及具体的次数
        // 每一列所有元素中，出现次数第二多的元素，以及具体的次数
        vector<pair<int, int>> fir(m), sec(m);
        
        for (int i = 0; i < m; i++) {
            unordered_map<int, int> hs;
            for (int j = 0; j < n; j++) {
                int & x = grid[j][i];
                hs[x] += 1;
            }
            int maxFreq = 0, secFreq = 0;
            int maxVal = 0, secVal = 0;
            for (auto & [k, v] : hs) {
                if (maxFreq < v) {
                    maxFreq = v;
                    maxVal = k;
                }
            }
            fir[i] = make_pair(maxVal, maxFreq);
            
            hs.erase(maxVal);
            for (auto & [k, v] : hs) {
                if (secFreq <v) {
                    secFreq = v;
                    secVal = k;
                }
            }
            if (secFreq == 0) {
                secFreq = maxFreq;
                secVal = maxVal;
            }
            sec[i] = make_pair(secVal, secFreq);
        }
        
        
//         for (int i = 0; i < n; i++) {
//             for (int  j = 0; j < m; j++) {
//                 cout << grid[i][j] << ' ';
//             }
//             cout << endl;
//         }
//         for (auto & x : sec) {
//             cout << x.first << ' ' << x.second << endl;
//         }
        vector<vector<int>> f(3, vector<int>(m, 0));
        int ans = 0;
        int len = n;
        f[1][0] = len - fir[0].second;
        f[2][0] = len - sec[0].second;
        if (fir[0].first == sec[0].first or n == 1) {
            f[2][0] = f[1][0];
        }
        for (int i = 1; i < m; i++) {
            if (fir[i].first == fir[i - 1].first) {
                f[1][i] = f[2][i - 1] + (len - fir[i].second);
                f[2][i] = f[1][i - 1] + (len - sec[i].second);
                if (fir[i].first == fir[i - 1].first and fir[i - 1].first == sec[i - 1].first) {
                    f[1][i] = min(f[1][i - 1], f[2][i - 1]) + len;
                    f[2][i] = min(f[1][i - 1], f[2][i - 1]) + len;
                }
            } else {
                f[1][i] = min(f[1][i - 1], f[2][i - 1]) + (len - fir[i].second);
                f[2][i] = min(f[1][i - 1], f[2][i - 1]) + (len - sec[i].second);
            }
        }

        ans = min(f[1][m - 1], f[2][m - 1]);        
        return ans;
    }
};


auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    Solution s;
    int x = s.functionName(a);
    cout << x << endl;
    return 0;
}
/*

*/
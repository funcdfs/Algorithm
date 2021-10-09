/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string.h>

using namespace std;

/*2021-10-08-08-04*/

// from https://github.com/fengwei2002/Algorithm
/*
 !
 ! 字符串哈希加前缀和
 *
 *
 */

// @lc code=start
typedef unsigned long long ULL;
const int N = 1e5 + 10, P = 13331;

class Solution {
   private:
    ULL h[N], p[N];
    int get(ULL l, ULL r) { return h[r] - h[l - 1] * p[r - l + 1]; }

   public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;

        memset(h, 0, sizeof h);
        memset(p, 0, sizeof p);

        p[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            h[i] = h[i - 1] * P + s[i - 1];
            p[i] = p[i - 1] * P;
        }

        unordered_map<ULL, int> cnt;
        for (int i = 1; i + 10 - 1 <= s.size(); i++) {
            int j = i + 10 - 1;
            int hash = get(i, j);
            cnt[hash]++;

            if (cnt[hash] == 2) {
                ans.push_back(s.substr(j - 10, 10));
                cnt[hash]++;
            }
        }

        return ans;
    }
};

// @lc code=end

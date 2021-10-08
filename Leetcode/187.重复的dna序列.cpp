/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

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
const ULL N = 1e5 + 10, P = 13331;
typedef unsigned long long ULL;

class Solution {
   private:
    ULL h[N], p[N];

    ULL get(ULL l, ULL r) { return h[r] - h[l - 1] * p[r - l + 1]; }

   public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;

        // 初始化字符串哈希
        p[0] = 1;
        for (ULL i = 1; i <= s.size(); i++) {
            h[i] = h[i - 1] * P + s[i - 1];
            p[i] = p[i - 1] * P;
        }

        // 枚举所有长度为 10 的子串
        unordered_map<ULL, ULL> count;
        for (ULL i = 0; i < s.size(); i++) {
            ULL j = i + 10 - 1;
            count[get(j, i)]++;

            if (count[get(j, i)] >= 1) {
                string subs = s.substr(i - 1, 10);
                ans.push_back(subs);
            }
        }

        return ans;
    }
};
// @lc code=end

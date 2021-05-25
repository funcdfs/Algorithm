/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
   public:
    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());  // s2 为 s1 的逆序列
        return longestCommonSubsequence(s1, s2);
    }

    //最长公共子序列函数
    int longestCommonSubsequence(string s1, string s2) {
        int l1 = s1.size(), l2 = s2.size();
        int** dp = new int*[l1 + 1];
        for (int i = 0; i < l1 + 1; ++i) {
            dp[i] = new int[l2 + 1]();
        }
        for (int i = 1; i < l1 + 1; i++) {
            for (int j = 1; j < l2 + 1; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[l1][l2];
    }
};
// @lc code=end

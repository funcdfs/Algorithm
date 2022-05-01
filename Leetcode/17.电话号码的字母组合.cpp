/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-01-20-47*/

// from https://github.com/fengwei2002/Algorithm
/*
 !
 ! 回溯框架题
 *
 *
 */

// @lc code=start
class Solution {
private:
    vector<string> ans;
    string path;

    const string keyMap[10] = {
        "",
        "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz",
    };

    void dfs(string& digits, int index, string& path) {
        if (path.size() == digits.size()) {
            ans.push_back(path);
            return;
        }

        string keyMapItem = keyMap[digits[index] - '0'];

        for (int i = 0; i < keyMapItem.size(); i++) {
            path.push_back(keyMapItem.at(i));
            dfs(digits, index + 1, path);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        ans.clear();
        path.clear();
        
        if (digits.size() == 0) return ans;
        
        dfs(digits, 0, path);
        return ans;
    }
};
// 链接：https://leetcode.cn/problems/letter-combinations-of-a-phone-number/solution/lc17-fengwei2002-by-fengwei2002-3oj4/
// @lc code=end

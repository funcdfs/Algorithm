/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-19-08-20*/

// depository: 
// https://github.com/fengwei2002/Algorithm
// solution link: 
// https://leetcode.cn/problems/simplify-path/solution/lc71-fengwei2002-by-kycu-z3ke/


// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        string ans = "", name = "";
        if (path.back() != '/') path += "/";

        for (auto c : path) {
            if (c != '/') {
                name += c;
            } else {
                if (name == "..") {
                    while (ans.size() > 0 && ans.back() != '/') ans.pop_back();
                    if (ans.size() > 0) ans.pop_back();
                } else if (name == "." || name == "") {
                    // do nothing
                } else if (name != "." && name != "") {
                    ans += "/" + name;
                }
                name.clear();
            }
        } 

        if (ans.empty()) ans = "/";

        return ans;
    }
};
// @lc code=end

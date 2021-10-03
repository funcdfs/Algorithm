/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-09-27-17-38*/

// from https://github.com/fengwei2002/Algorithm
/*
 !
 !
 *
 * https://leetcode-cn.com/problems/container-with-most-water/solution/lc11-fengwei2002-by-fengwei2002-kpan/
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans = 0;

        int i = 0, j = h.size() - 1;
        while (i < j) {
            ans = max(ans, min(h[i], h[j]) * (j - i));
            
            if (h[i] < h[j]) i++;
            else j--;
        }
        
        return ans;
    }
};
// @lc code=end

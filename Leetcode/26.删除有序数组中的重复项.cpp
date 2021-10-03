/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-02-21-12*/

//from https://github.com/fengwei2002/Algorithm

// ? 思路解析： 只保留不等于前一个元素的元素
/*
 *     对有序数组进行去重 unique 函数
 当前元素不等于后面的元素的时候，就将 当前元素移动 到 k
 的位置，进行下一个数组的判断 
 https://www.acwing.com/solution/content/77/
 */

// @lc code=start
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int k = 0;
        for (int i = 0; i < nums.size(); i++)
            if (i != 0 || nums[i] != nums[i - 1]) nums[k++] = nums[i];
        return k;
    }
};
// @lc code=end

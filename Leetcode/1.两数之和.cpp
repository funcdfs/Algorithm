/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*2021-09-25-23-26*/
// ? 思路解析：
/* 
 * 
 *  利用哈希表进行存储，遍历一遍数组，每次考察 target - nums[i] 是否存在于 哈希表中
 *     将 nums[i] 对应的下标放入哈希表中， 哈希表可以在 O(1) 时间内找到一个数字
 *     所以加快了 时间复杂度
 !  https://leetcode.cn/problems/two-sum/solution/lc1-fengwei2002-ha-xi-biao-by-fengwei200-t94y/
 ! 
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> hash;
        
        for (int i = 0; i < nums.size(); i++) {
            int another = target - nums[i];
            if (hash.count(another) > 0) {
                ans.push_back(i);
                ans.push_back(hash[another]);
                break;
            }
            hash[nums[i]] = i;
        }
        return ans;
    }
};
// @lc code=end


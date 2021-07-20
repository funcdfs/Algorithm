/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-07-19-23-54*/

// @lc code=start
class Solution {
    // 摩尔投票法：  成立前提：有出现次数大于n/2的数存在
   public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ans = nums.at(0);
        for (int i = 0; i < nums.size(); i++) {
            if (ans == nums.at(i)) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    ans = nums.at(i + 1);
                    // 注意这里的 i 边界值并不需要特判，并不会越界
                }
            }
        }
        return ans;
    }
};
// @lc code=end

class Solution_02 {
    // 位运算版本
    //位运算法,统计每个数字每一位0，1出现的次数，如果某一位1出现的次数多则该位为1，0同理；
    //最后按为统计出来的数就是众数 （因为数据大于一半）
    // 太神奇一般也用不到
   public:
    int majorityElement(vector<int>& nums) {
        int res = 0, len = nums.size();
        for (int i = 0; i < 32; i++) {
            int ones = 0, zero = 0;
            for (int j = 0; j < len; j++) {
                if (ones > len / 2 || zero > len / 2) break;
                if ((nums[j] & (1 << i)) != 0)
                    ones++;
                else
                    zero++;
            }
            if (ones > zero) res = res | (1 << i);
        }
        return res;
    }
};
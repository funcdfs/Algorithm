/*
 * @lc app=leetcode.cn id=1431 lang=cpp
 *
 * [1431] 拥有最多糖果的孩子
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        const int max = *max_element(begin(candies), end(candies));
        /*一种判断向量中最大元素比较快并且简洁的一种方式*/
        vector<bool> result(candies.size());
        /*vector中可以用size得到数量*/
        for (int i = 0; i < candies.size(); ++i)
            result[i] = ((candies[i] + extraCandies) >= max);
        return result;
    }
};

// @lc code=end

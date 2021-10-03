/*
 * @lc app=leetcode.cn id=1 lang=javascript
 *
 * [1] 两数之和
 */

//date: 2021-10-03

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    let hash = new Map();

    for (let i = 0; i < nums.length; i++) {
        let another = target - nums[i];
        if (hash.has(another)) {
            return [hash.get(another), i];
        }
        hash.set(nums[i], i);
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=3 lang=javascript
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
/**
 * @param {string} s
 * @return {number}
 */
/**
 * @param {string} s
 * @return {number}
 */
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
    let l = 0; // 定义左指针
    let ans = 0; // 结果
    let map = new Map(); // 存放字符和对应下标

    for (let r = 0; r < s.length; r++) {
        if (map.has(s[r]) && map.get(s[r]) >= l) {
            l = map.get(s[r]) + 1;
        }
        ans = Math.max(ans, r - l + 1);
        map.set(s[r], r);
    }
    return ans;
};
// @lc code=end

var lengthOfLongestSubstring2 = function (s) {
    if (!s.length) return 0;
    let ans = 1;

    for (let i = 0; i < s.length; i++) {
        let a = new Set();
        r = i;

        while (r < s.length && !a.has(s[r])) {
            a.add(s[r]);
            r++;
        }
        ans = Math.max(ans, a.size);
    }
    return ans;
};

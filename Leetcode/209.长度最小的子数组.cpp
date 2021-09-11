/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-08-16-15-45*/
// ? 思路解析：
/*
 * 本来是在 二分tag 下看到的，结果前缀和加二分不会写
 *
 ! yxc 双指针写法，很厉害，i j 具有单调性的问题就可以使用双指针来解决 o(n)
 !

static_cast 用于良性转换，一般不会导致意外发生，风险很低。
c++的四种转换，http://c.biancheng.net/cpp/biancheng/view/3297.html
 */

// @lc code=start
class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        vector<int> s(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++) s[i] = s[i - 1] + nums[i - 1];
        for (int i = 0; i < s.size(); i++) {
            int l = i, r = s.size() - 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (s[mid] - s[i] >= target)
                    r = mid;
                else
                    l = mid + 1;
            }
            if (s[l] - s[i] >= target) ans = min(ans, l - i);
        }
        return ans == INT_MAX? 0 : ans;
    }
};
// @lc code=end

class Solution_双指针 {
   public:  // O(n)
    int minSubArrayLen(int target, vector<int>& nums) {
        int asn = INT_MAX;
        //  i j 为双指针， sum 是 i 到 j 的和
        for (int i = 0, j = 0, sum = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum - nums[j] >= target) sum -= nums[j++];
            //! 如果 while 循环可以执行的话
            //! 说明 新加入的 i 可以至少电梯一个去掉的 j
            // j 向后移动，找到满足 ij 满足条件的最右侧 j 的值
            if (sum >= target) asn = min(asn, i - j + 1);
        }
        if (asn == INT_MAX) asn = 0;
        return asn;
    }
};

class Solution_前缀和加二分查找 {
   public:  // O(n * log_n)
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        vector<int> s(nums.size() + 1, 0);
        vector<int> a(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++) a[i] = nums[i - 1];
        for (int i = 1; i <= nums.size(); i++) s[i] = s[i - 1] + a[i];
        // // for (auto i : s) cout << i << ' ';
        // // puts("");
        // s[i] 代表前缀和数组， a[i] 代表区间元素

        for (int i = 0; i < s.size(); i++) {
            // ! 注意 i 要从 0 开始，因为还有当区间和刚好等于目标值的情况
            int l = i, r = s.size() - 1;
            // 使用二分优化找到区间起始位置时，再找区间结束位置的步骤
            while (l < r) {
                int mid = (l + r) >> 1;
                if (s[mid] - s[i] >= target)
                    r = mid;
                else
                    l = mid + 1;
            }
            // // cout << " i = " << i << " l = " << l << endl;
            if (s[l] - s[i] >= target) {
                // // cout << s[l] - s[i] << ">> 区间长度 " << l - i << endl;
                ans = min(ans, l - i);
                // !  l - i + 1 是 s 数组的长度，不加 1 是 a 数组的长度
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};


class Solution_暴力解法 {
   public:  // O(n^2)
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum >= s) {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

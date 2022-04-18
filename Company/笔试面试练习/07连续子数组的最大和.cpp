// Problem: 连续子数组的最大和
// Contest: AcWing
// url:  https://www.acwing.com/problem/content/50/
// date: 2022-04-09 19:36:59
// Memory Limit: 64 MB
// Time Limit:   1000 ms


// #define d(a)  // https://github.com/fengwei2002/Algorithm
// #define dline // konng0120@gmail.com
// #define dendl // 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> f(n + 1, -1e8); 
        for (int i = 1; i <= n; i++) {
            f[i] = max(f[i - 1] + nums[i - 1], nums[i - 1]); 
        }
        return *max_element(f.begin(), f.end()); 
    }
};
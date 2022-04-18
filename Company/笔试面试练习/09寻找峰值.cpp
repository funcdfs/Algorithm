// Problem: 寻找峰值
// Contest: AcWing
// url:  https://www.acwing.com/problem/content/1613/
// date: 2022-04-09 19:45:32
// Memory Limit: 64 MB
// Time Limit:   1000 ms

// Forward declaration of queryAPI.
// int query(int x);
// return int means nums[x].

class Solution {
public:
    int findPeakElement(int n) {
        int l = 0; 
        int r = n - 1; 
        while (l < r) {
            int mid = (l + r + 1) >> 1; 
            if (query(mid) > query(mid - 1)) {
                l = mid;  
            } else {
                r = mid - 1; 
            }
        }
        return l;
    }
};
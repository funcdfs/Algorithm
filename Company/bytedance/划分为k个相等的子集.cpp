#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

class Solution {
public: 
   bool canPartitionKSubsets(vector<int>& nums, int k) {
      int sum = accumulate(nums.begin(), nums.end(), 0); 
      if (sum % k) return false; 
      int edgeLength = sum / k; 
      
      int n = nums.size(); 
      vector<bool> st(n, false); 
      sort(nums.begin(), nums.end(), [](const int& a, const int& b) {
         return b > a; 
      }); 
      
      function<bool(int, int, int)> dfs = [&](int startIndex, int nowLength, int nowCount) -> bool {
         if (nowCount == k - 1) {
            return true; 
         }
         if (nowLength == edgeLength) {
            return dfs(0, 0, nowCount + 1); 
         } 
         
         for (int i = startIndex; i < nums.size(); i++) {
            if (st[i] == true) continue; 
            if (nowLength + nums[i] <= edgeLength) {
               st[i] = true; 
               if (dfs(i + 1, nowLength + nums[i], nowCount)) {
                  return true; 
               }
               st[i] = false; 
            }
            if (nowLength == 0 || nowLength == edgeLength) {
               return false; 
            } 
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++; 
         }
         return false; 
      };
      
      return dfs(0, 0, 0); 
   }
};

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   Solution* s = new Solution(); 
   vector<int> test{4, 3, 2, 3, 5, 2, 1}; 
   int k = 4; 
   cout << s->canPartitionKSubsets(test, k); 

   return 0;
}


/*

划分为k个相等的子集



*/
/*
 * @lc app=leetcode.cn id=1007 lang=cpp
 *
 * [1007] 行相等的最少多米诺旋转
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2022-01-01-17-42*/

// https://github.com/fengwei2002/Algorithm
// solution link:
//

// @lc code=start
class Solution {
   public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        const int INF = 0x3f3f3f3f;
        int ans = INF, n = tops.size();
        int value[] = {tops[0], bottoms[0]};
        for (auto x : value) {
            int t = 0;
            for (int i = 0; i < n; i++) {
                if (tops[i] != x) {
                    if (bottoms[i] != x) {
                        t = INF;
                    } else {
                        t++;
                    }
                }
            }
            ans = min(ans, t);

            t = 0;
            for (int i = 0; i < n; i++) {
                if (bottoms[i] != x) {
                    if (tops[i] != x) {
                        t = INF;
                    } else {
                        t++;
                    }
                }
            }
            ans = min(ans, t);
        }
        
        if (ans == INF) {
            ans = -1;
        }

        return ans;
    }
};
// @lc code=end

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-01-19-11*/

//from https://github.com/fengwei2002/Algorithm
/* 
 !
 !
 * 同 leetcode 2016
 *
 */


class LongestDistance {
public:
    int getDis(vector<int> nums, int n) {
        int minItem = nums[0], ans = 0;

        for (int i = 1; i < n; i++) {
            if (minItem < nums[i])
                ans = max(ans, nums[i] - minItem);

            minItem = min(minItem, nums[i]);
        }

        return ans;

    }
};

// https://www.nowcoder.com/practice/1f7675ae7a9e40e4bd04eb754b62fd00?tpId=128&&tqId=33768&rp=1&ru=/ta/exam-meituan&qru=/ta/exam-meituan/question-ranking
/* @ https://github.com/fengwei2002/Algorithm */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void nextPermutation(vector<int>& nums);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> a(6, 0);
    for (int i = 0; i < 6; i++) {
        a[i] = i + 1;
    }
    for (auto x : a) {
        cerr << x << ' ';
    }
    cerr << endl;
    nextPermutation(a);
    for (auto x : a) {
        cerr << x << ' ';
    }
    cerr << endl;
    for (int i = 0; i < 5; i++) {
        next_permutation(a.begin(), a.end());
        for (auto x : a) {
            cerr << x << ' ';
        }
        cerr << endl;
    }

    return 0;
}

void nextPermutation(vector<int>& nums) {
    int k = nums.size() - 1;
    while (k > 0 && nums[k - 1] >= nums[k]) k--;
    if (k <= 0) {
        reverse(nums.begin(), nums.end());
    } else {
        int t = k;
        while (t < nums.size() && nums[t] > nums[k - 1]) t++;
        swap(nums[t - 1], nums[k - 1]);
        reverse(nums.begin() + k, nums.end());
    }
}

// https://leetcode.cn/problems/next-permutation/solution/lc-fengwei2002-zhao-gui-lu-by-fengwei200-w72c/
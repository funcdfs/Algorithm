class Solution {
   public:
    int maximumGood(vector<vector<int>>& s) {
        int n = s.size();
        int mask = (1 << n);
        int ans = 0;
        for (int i = 0; i < mask; i++) {  // 考虑 0 到 2^n - 1 种情况中的值
            bool flag = true;
            for (int j = 0; j < n; j++) { // 对于每一个值考虑每一位具体是 0 还是 1 
                if ((i >> j) & 1) {       // 如果 i 的第 j 位等于 1, 就说明这种 mask 中的这一位存在
                                          // j 是好人的情况下，根据 statesment[j][k] 计算其他人是好人还是坏人
                    for (int k = 0; k < s[j].size(); k++) {
                        if (s[j][k] == 2) continue;
                        if ((s[j][k] == 1 && ((i >> k) & 1) == 0) ||
                            (s[j][k] == 0 && ((i >> k) & 1) == 1)) {
                                          // 如果出现了陈述的状态和当前 mask 表示的状态不同的情况
                            flag = false;
                            break;        // 就可以快进到下一种情况
                        }
                    }
                }
            }
            if (flag) {                   // 如果存在一种 mask 正确的遍历完成的话
                ans = max(ans, __builtin_popcount(i));
            }
        }
        return ans;
    }
};
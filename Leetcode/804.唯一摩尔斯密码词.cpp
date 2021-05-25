/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩尔斯密码词
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> set;
        vector<string> record{".-",   "-...", "-.-.", "-..",  ".",    "..-.",
                              "--.",  "....", "..",   ".---", "-.-",  ".-..",
                              "--",   "-.",   "---",  ".--.", "--.-", ".-.",
                              "...",  "-",    "..-",  "...-", ".--",  "-..-",
                              "-.--", "--.."};

        for (auto s : words) {  //对于woeds中的每个单词s
            string c;
            for (int i = 0; i < s.size(); i++) {
                c += record[s[i] - 'a'];
            }
            set.insert(c);  // set的直接插入不会插入相同的元素
        }
        return (int)set.size();
    }
};
// @lc code=end

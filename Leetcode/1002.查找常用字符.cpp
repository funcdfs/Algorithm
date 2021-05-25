/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> out;
        int num[100][26] = {0};
        //建立一个二维数组，用来标记所有出现的字母次数
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[i].size(); j++)
                num[i][(A[i][j] - 'a')]++;
        //统计每一个单词的每一个字母出现的次数 (非 0 的)
        for (int j = 0; j < 26; j++)
            for (int i = 1; i < A.size(); i++)
                num[0][j] = min(num[0][j], num[i][j]);
        //现在就出现了一个网格了
        //然后把第一行的每一个数值改为对应列的最小值就行了
        string str;
        //按照第一行保存的次数输出相应字母
        for (int i = 0; i < 26; i++) {
            while (num[0][i]--) {
                str.clear();
                str.push_back('a' + i);
                out.push_back(str);
            }
        }
        //因为要求是返回字符串，所以还得将 char 转为 string
        return out;
    }
};
// @lc code=end

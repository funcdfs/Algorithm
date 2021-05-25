/*
 * @lc app=leetcode.cn id=1160 lang=cpp
 *
 * [1160] 拼写单词
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int countCharacters(vector<string>& words, string chars) {
        //统计 chars 中的字符个数，统计每一个 words 的个数
        int chars_total[26] = {0};

        int result = 0;

        //统计字母表的每一个个数  小写字母 a 为 97
        for (int i = 0; i < chars.length(); i++) {
            chars_total[chars.at(i) - 97]++;
        }

        //统计字符串数组每一个字符出现的次数
        for (int i = 0; i < words.size(); i++) {
            int words_total[26] = {0};
            //每次进入下一个单词的时候将对应的表置为0

            for (int j = 0; j < words.at(i).size(); j++) {
                words_total[words.at(i).at(j) - 97]++;
            }

            //一个单词的每个字母统计数完成后与模板表进行比对，若为子集就累加到长度中
            int eqsum = 0;
            for (int k = 0; k < 26; k++) {
                //记录字母表相等的次数
                if (chars_total[k] >= words_total[k]) {
                    eqsum++;  //遇到子集就执行++
                } else {
                    break;
                }
            }

            //相等次数等于字母表长度，将单词长度列入正确结果中
            if (eqsum == 26) {
                for (int k = 0; k < 26; k++) {
                    result += words_total[k];
                }
            }
        }
        return result;
    }
};
// @lc code=end

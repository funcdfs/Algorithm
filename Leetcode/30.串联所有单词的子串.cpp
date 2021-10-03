/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*2021-10-03-13-29*/

// from https://github.com/fengwei2002/Algorithm

// @lc code=start
class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) return ans;

        int m = words.size(), wordLength = words[0].size();
        // 字符串总长度 n ， m 是单词的个数， wordLength 是长度

        unordered_map<string, int> wordsCount;
        for (auto& word : words) wordsCount[word]++;
        //枚举 words 中的每一单词， 统计每个单词出现的次数

        for (int i = 0; i < wordLength; i++) {
            // 按照起始位置对于 wordlenght 的余数分组起始位置

            unordered_map<string, int> window;
            int sameCount = 0;
            // 开辟滑动窗口

            for (int j = i; j + wordLength <= s.size(); j += wordLength) {
                // 对于每一组起始位置 （ j 的位置是实际 下标 多一位）

                if (j >= i + m * wordLength) {
                    // 如果大于等于滑动窗口的大小

                    auto word = s.substr(j - m * wordLength, wordLength);
                    window[word]--;  // 减去滑动窗口前面的那个单词的对应哈希表值
                    // 代表前面的一个单词从滑动窗口中去除

                    if (window[word] < wordsCount[word]) sameCount--;
                    // 如果滑动窗口中的某一个单词对应的数量，小于标准数量
                    // 相同单词数量就可以减去 1
                }

                auto word = s.substr(j, wordLength);  // 取出后面的一个单词
                window[word]++;  // 后面那个单词，在滑动窗口中的计数加一

                if (window[word] <= wordsCount[word]) sameCount++;
                // 如果说放入一个单词后的滑动窗口中的某一个单词
                // 它的计数数量  小于 等于  标准数量， 相同单词数量就可以加上一

                if (sameCount == m) {
                    ans.push_back(j - (m - 1) * wordLength);
                }
                // 如果某一个滑动窗口的 相同单词数量，等于单词的个数，
                // 说明这是一个答案，将这个滑动窗口的起始位置放入结果中
                // 结束时，j 的位置是分组中倒数第二个边界的位置，所以 j - (m - 1) * wordLength
                // 而不是 j - m * wordLength
            }
        }

        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

/*2021-12-04-19-56*/

// https://github.com/fengwei2002/Algorithm
// solution link: 
// https://leetcode-cn.com/problems/word-ladder/solution/lc127-fengwei2002-by-kycu-g7g3/


// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans = 0;

        unordered_set<string> S;            // 用来存储哪些字符串出现过
        unordered_map<string, int> dist;    // 存储起点字符串到每个字符串的距离
        queue<string> q;                    // 创建 BFS 的队列
        dist[beginWord] = 1;                

        q.push(beginWord);                          // 将起始字符串放入队列中，以便进行 BFS
        for (auto word : wordList) S.insert(word); // 将不冲突的字符串放入 set 中，方便查找字符串是否存在

        while (q.size() > 0) {
            string origin = q.front();      // 取出队列首部的元素
            q.pop();
            string changed = origin;

            for (int i = 0; i < origin.size(); i++) {
                changed = origin;
                for (char j = 'a'; j <= 'z'; j++) { // 遍历字符串中的这一位可能变成的所有结果
                    if (origin[i] != j) {
                        changed[i] = j;

                        if (S.count(changed) && dist.count(changed) == 0) {
                            // 如果变一个字符之后的字符串存在，并且它的距离没有被更新过
                            // 那么他就是图中下一步的可达点

                            dist[changed] = dist[origin] + 1;
                            if (changed == endWord) {
                                return dist[changed];
                                // / 先遍历到的结果，就是最终路径中单词的数量
                            }

                            q.push(changed);
                            // 如果还没有到根节点，将根节点放入队列中，继续进行 BFS
                        }
                    }
                }
            }
        }

        return ans;
    }
};
// @lc code=end


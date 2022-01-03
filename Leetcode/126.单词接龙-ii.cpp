/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

/*2021-12-04-21-16*/

// https://github.com/fengwei2002/Algorithm
// solution link: 
// https://leetcode-cn.com/problems/word-ladder-ii/solution/lc126-fengwei2002-by-kycu-5lcn/

// @lc code=start
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;

    string beginWord, endWord;
    unordered_set<string> S;
    unordered_map<string, int> dist;
    queue<string> q; 


    vector<vector<string>> findLadders(string _beginWord, string _endWord, vector<string>& wordList) {
        beginWord = _beginWord; 
        endWord = _endWord;
        for (auto word : wordList) S.insert(word); 

        dist[beginWord] = 0;
        q.push(beginWord); 

        while (q.size() > 0) {
            auto origin = q.front();
            q.pop();
            string changed = origin;

            for (int i = 0; i < origin.size(); i++) { 
                changed = origin; 
                for (char j = 'a'; j <= 'z'; j++) {
                    changed[i] = j;
                    if (S.count(changed) && dist.count(changed) == 0) {
                        dist[changed] = dist[origin] + 1;
                        if (changed == endWord) break;
                        q.push(changed);
                    }
                }
            }
        }

        if (dist.count(endWord) == 0) {
            return ans;
        }

        path.push_back(endWord);
        dfs(endWord);
        return ans;
    }

    void dfs(string word) {
        if (word == beginWord) { 
            reverse(begin(path), end(path));
            ans.push_back(path);
            reverse(begin(path), end(path));
        } else {
            string changed = word;
            string origin = word;

            for (int i = 0; i < changed.size(); i++) {
                origin = changed;

                for (char j = 'a'; j <= 'z'; j++) {
                    origin[i] = j;
                    if (dist.count(origin) && dist[origin] + 1 == dist[changed]) {
                        path.push_back(origin);
                        dfs(origin);
                        path.pop_back();
                    }
                }
            }
        }
    }
};
// @lc code=end


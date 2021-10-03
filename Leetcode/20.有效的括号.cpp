/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

/*2021-10-02-01-12*/

// from https://github.com/fengwei2002/Algorithm

// @lc code=start
class Solution {
   public:
    bool isValid(string s) {
        stack<char> stk;
        // 小括号对于小括号，差值为 1，中括号和大括号的 ASCII 码差值是 2 
        // 由于数据的特殊性，所以可以简写
        
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{')
                stk.push(c);
            else {  
                if (stk.size() && (stk.top() - c == -1 || stk.top() - c == -2))
                    stk.pop();
                else
                    return false;
            }
        }

        return stk.empty();
    }
};
// @lc code=end
class Solution_官方题解_哈希表 {
   public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) return false;

        unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};

        stack<char> stk;

        for (char ch : s) {
            if (pairs.count(ch)) {  // value key 键值对， count 返回 key ，
                                    // 等于右括号的时候进入 if
                if (stk.empty() || stk.top() != pairs[ch]) {
                    return false;
                }
                stk.pop();
            } else {
                stk.push(ch);
                // 左括号就放入栈中
            }
        }
        return stk.empty();
    }
};

class Solution_不用哈希表存储 {
   public:
    bool isValid(string s) {
        bool ans;
        stack<char> stk;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else if (s[i] == ')') {
                if (stk.empty() || stk.top() != '(') return false;
                stk.pop();
            } else if (s[i] == ']') {
                if (stk.empty() || stk.top() != '[') return false;
                stk.pop();
            } else {
                if (stk.empty() || stk.top() != '{') return false;
                stk.pop();
            }
        }

        ans = stk.empty();

        return ans;
    }
};
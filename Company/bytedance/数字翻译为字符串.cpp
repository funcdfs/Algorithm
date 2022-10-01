#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   string num = "";
   cin >> num;

   vector<vector<string>> ans;
   vector<string> path;
   function<void(int)> dfs = [&](int idx) {
      if (idx == num.size()) {
         ans.push_back(path);
         return;
      }
      if (idx > num.size()) {
         return;
      }

      string st1 = num.substr(idx, 1);
      string st2 = num.substr(idx, 2);

      path.push_back(st1);
      dfs(idx + 1);
      path.pop_back();

      int val = stoi(st2);
      if (val >= 10 && val <= 26) {
         path.push_back(st2);
         idx += 2;
         dfs(idx);
         idx -= 2;
         path.pop_back();
      }
      return;
   };

   dfs(0);

   for (auto& x : ans) {
      for (auto& y : x) {
         string t = y;
         int val = stoi(t);
         char c = val + 'a';
         cout << c;
         // cout << y << ' ' << '|' << ' ';
      }
      cout << '\n';
   }

   return 0;
}

/*

数字翻译为字符串


给定一个数字，我们按照如下规则把它翻译为字符串：
0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成
“z”。一个数字可能有多个翻译。
请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> f(n + 1, 0);
        f[0] = 1;

        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1];
            if (i < 2) continue;
            int t = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            if (t >= 10 && t <= 25) {
                f[i] += f[i - 2];
            }
        }

        return f[n];
    }
};
输出不同翻译方法的具体方案

例如 12258 有 5 种不同的翻译，它们分别是 bccfi、bwfi、bczi、mcfi 和 mzi。

1 | 2 | 2 | 5 | 8 |
1 | 2 | 25 | 8 |
1 | 22 | 5 | 8 |
12 | 2 | 5 | 8 |
12 | 25 | 8 |
bccfi
bczi
bwfi
mcfi
mzi


*/
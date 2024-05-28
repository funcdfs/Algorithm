/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-04 23:39:50
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0;
   cin >> n;

   vector<string> ans;
   string t = "0";
   ans.push_back(t);
   for (int i = 1; i <= n; i++) {
      string s = t;
      t.append(to_string(i));
      ans.push_back(t);
   }
   for (int i = 1; i < (int)ans.size(); i++) {
      string s = ans[i];
      s.pop_back();
      reverse(s.begin(), s.end());
      ans[i].append(s);
   }
   auto ansCopy = ans;
   ansCopy.pop_back();
   reverse(ansCopy.begin(), ansCopy.end());
   ans.insert(ans.end(), ansCopy.begin(), ansCopy.end());
   ansCopy.clear();
   for (auto& line : ans) {
      string lt = "";
      for (auto c : line) {
         lt.push_back(c);
         lt.push_back(' ');
      }
      lt.pop_back();
      ansCopy.push_back(lt);
   }
   ans = ansCopy;

   vector<string> zeroString;
   zeroString.push_back(string(n * 2, ' '));
   for (int i = 0; i < n; i++) {
      zeroString.push_back(zeroString.back().substr(0, (int)zeroString.back().size() - 2));
   }
   auto zeroStringCopy = zeroString;
   zeroStringCopy.pop_back();
   reverse(zeroStringCopy.begin(), zeroStringCopy.end());
   zeroString.insert(zeroString.end(), zeroStringCopy.begin(), zeroStringCopy.end());

   for (int i = 0; i < (int)ans.size(); i++) {
      cout << zeroString[i];
      cout << ans[i] << '\n';
   }

   return 0;
}
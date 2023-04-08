/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-11 19:54:27
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(int st, vector<int>& edge) {
   auto root = new(TreeNode);
   root->val = st;
   unordered_map<int, TreeNode*> tr;
   tr[root->val] = root;

   unordered_map<int, int> cnt;
   for (int i = 0; i < (int)edge.size(); i++) {
      int x = edge[i];
      if (cnt[x] == 0) {
         cnt[x] += 1;
         auto p = new(TreeNode);
         p->val = i + 2;
         tr[x]->left = p;
         tr[p->val] = p;
      } else if (cnt[x] == 1) {
         cnt[x] += 1;
         auto p = new(TreeNode);
         p->val = i + 2;
         tr[x]->right = p;
         tr[p->val] = p;
      }
   }
   dbg(tr.size());
   return tr[root->val];
}

unordered_map<int, pair<int, int>> hs;
pair<int, int> dfs(TreeNode* root, string& s) {
   if (root->left == nullptr and root->right == nullptr) {
      if (s[root->val - 1] == 'R') {
         return {1, 0};
      }
      if (s[root->val - 1] == 'B') {
         return {0, 1};
      }
   }
   pair<int, int> t(0, 0);
   if (root->left) {
      auto tt = dfs(root->left, s);
      t.first += tt.first;
      t.second += tt.second;
   }
   if (root->right) {
      auto tt = dfs(root->right, s);
      t.first += tt.first;
      t.second += tt.second; 
   }
   hs[root->val] = t;
   return t;
}

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   int n = 0;
   cin >> n;
   string s = "";
   cin >> s;
   vector<int> edge(n - 1, 0);
   for (int i = 0; i < n - 1; i++) {
      cin >> edge[i];
   }
   auto root = buildTree(1, edge);
   dfs(root, s);

   int ans = 0;
   for (int i = 0; i < n; i++) {
      if (hs[i].first == hs[i].second) {
         ans += 1;
      }
   }
   cout << ans << '\n';
   return 0;
}
/*

*/
// link: https://codeforces.com/problemset/problem/1181/B B. Split a Number
// time: 2024/7/5 13:11:00 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h> 
using namespace std; using int32 = signed; using uint32 = unsigned; using float32 = double; using int64 = long long; using uint64 = unsigned long long; using float64 = long double; 
template <class T> istream &operator>> (istream &cin,  vector<T>           &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin,  valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
struct _INIT_IO_END { _INIT_IO_END() { cout << fixed << setprecision(   15   );  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs; 
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define endl           '\n'
#define print(...)     cout << format(__VA_ARGS__)
#define println(...)   cout << format("{0}\n", __VA_ARGS__)
#define dbg(...)      ;
#define eprint(...)   ;
#define eprintln(...) ;
#endif
auto solve() -> void; /* main --> */ int32 main() {      solve(); return 0; }
#pragma endregion github_funcdfs   // clang-format on

// -------------------------------------------------------------------

string num_min(string A, string B) {
   if (A.size() < B.size() || (A.size() == B.size() && A < B)) {
      return A;
   }
   return B;
}

string add(string A, string B) {
   bool carry = false;
   string ans;
   while (A != "" || B != "" || carry) {
      int next = 0;
      if (A != "") {
         next += A.back() - '0';
         A.pop_back();
      }
      if (B != "") {
         next += B.back() - '0';
         B.pop_back();
      }
      if (carry) {
         next++;
      }
      ans += '0' + next % 10;
      if (next >= 10) {
         carry = true;
      } else {
         carry = false;
      }
   }
   reverse(ans.begin(), ans.end());
   return ans;
}

auto solve() -> void {
   int l = 0;
   cin >> l;
   string n;
   cin >> n;
   string ans = n;
   for (int i = l / 2 + 1; i < l; i++) {
      if (n[i] != '0') {
         ans = num_min(ans, add(n.substr(0, i), n.substr(i)));
         break;
      }
   }
   for (int i = l / 2; i >= 0; i--) {
      if (n[i] != '0') {
         ans = num_min(ans, add(n.substr(0, i), n.substr(i)));
         break;
      }
   }
   println(ans);
   return;
}

// -------------------------------------------------------------------

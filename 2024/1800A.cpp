// link: https://codeforces.com/contest/1800/problem/A A. Is It a Cat?
// time: 2024/7/2 16:30:51 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h> 
/* using golang types */ using namespace std; using int32 = signed; using uint32 = unsigned; using float32 = double; using int64 = long long; using uint64 = unsigned long long; using float64 = long double; 
/* vec<(any)> cincout */ template <class T> istream &operator>> (istream &cin,  vector<T> &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin,  valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
#define endl '\n' /* Use '\n' instead of std::endl to avoid unnecessary buffer flushes for performance */ 
#define print(...)  cout << format(__VA_ARGS__) /* the format string is printed to the standard output */ 
#define println(...) cout << format("{0}\n", __VA_ARGS__); /* print single value and appends a newline */
struct _init_end { _init_end() { cout << fixed << setprecision(      15      /* float output precision */);  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs; 

#ifdef LOCAL /* for local debugging purposes */ 
#include "algo/dbg.h"
#else /* link of dbg.h: https://gist.github.com/funcdfs */
#define dbg(...)    ; /* dbg(any); */
#define eprint(...) ; /* eprint("{} {}\n", x, y);*/
#endif

auto solve(int _case) -> void; int32 main() {       int testCaseCnt = 0; cin >> testCaseCnt; for (int _case = 1; _case <= testCaseCnt; _case++) { solve(_case); } return 0; }
#pragma endregion github_funcdfs   // clang-format on

// -------------------------------------------------------------------
auto solve(int _case) -> void {
   dbg(_case);

   int n = 0;
   cin >> n;
   string s;
   cin >> s;
   string t = string(1, s[0]);

   unordered_map<char, char> hs;
   hs['m'] = 'M';
   hs['M'] = 'm';
   hs['e'] = 'E';
   hs['E'] = 'e';
   hs['o'] = 'O';
   hs['O'] = 'o';
   hs['w'] = 'W';
   hs['W'] = 'w';

   for (int i = 1; i < n; i++) {
      if (s[i] != s[i - 1] && s[i] != hs[s[i - 1]]) {
         if (s[i] >= 'A' && s[i] <= 'Z') {
            t.push_back(char(s[i] - ('A' - 'a')));
         } else {
            t.push_back(s[i]);
         }
      }
   }
   if (t == "Meow" || t == "meow") {
      println("YES");
   } else {
      println("NO");
   }

   return;
}

// -------------------------------------------------------------------

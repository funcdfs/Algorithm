// link: https://codeforces.com/contest/1931/problem/C C. Make Equal Again
// time: 2024/9/21 18:59:36 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h> 
/* using golang types */ using namespace std; using int32 = signed; using uint32 = unsigned; using float32 = double; using int64 = long long; using uint64 = unsigned long long; using float64 = long double; 
/* vec<(any)> cincout */ template <class T> istream &operator>> (istream &cin,  vector<T> &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>			  &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin,  valarray<T>			&a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>			&a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>	&a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
#define endl '\n'	 /* Use '\n' instead of std::endl to avoid unnecessary buffer flushes for performance */ 
#define print(...)   std::cout << __VA_ARGS__ 			  /* C++23 std::print()	-> the format string is printed to the standard output */ 
#define println(...) std::cout << __VA_ARGS__ << '\n' /* C++23 std::println() -> to print a single value and append a newline */
struct _init_end { _init_end() { cout << fixed << setprecision(		15		/* float output precision */);  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs; 

#ifdef LOCAL /* For local debugging purposes */ 
#include "algo/dbg.h"
#else
#define dbg(...)		;
#define eprint(...)	;
#define eprintln(...) ;
#endif

auto solve(int _case) -> void; int32 main() { int testCaseCnt = 0; cin >> testCaseCnt; for (int _case = 1; _case <= testCaseCnt; _case++) { solve(_case); } return 0; }
#pragma endregion github_funcdfs	// clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------


auto solve(int _case) -> void {
   dbg(_case);

   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   cin >> a;
   
   int maxFreq = 1;
   int maxFreqNum = a[0];
   unordered_map<int, int> hs;
   for (int i = 0; i < n; i++) {
      hs[a[i]] += 1;
   }
   for (const auto& [k, v] : hs) {
      if (v > maxFreq) {
         maxFreq = v;
         maxFreqNum = k;
      }
   }
   if (maxFreq == n) {
      println(0);
      return;
   }

   dbg(a, maxFreqNum);

   int startIdx = 0, endIdx = 0;
   auto it= find_if(a.begin(), a.end(), [&](const int& val) {
      return val != maxFreqNum;
   });
   startIdx = distance(a.begin(), it);

   for (int i = n-1; i >= 0; i--) {
      if (a[i] != maxFreqNum) {
         endIdx = i;
         break;
      }
   }

   dbg(startIdx, endIdx);

   int ans1 = endIdx - startIdx + 1;
   // println(endIdx - startIdx + 1);

   int cnt1 = 1;
   for (int i = 0; i+1 < n ;i++) {
      if (a[i] == a[i+1]) {
         cnt1 += 1;
      } else {
         break;
      }
   }

   int cnt2 = 1;
   for (int i = n-1; i > 0; i--) {
      if (a[i] == a[i-1]) {
         cnt2 += 1;
      } else {
         break;
      }
   }

dbg(cnt1, cnt2);
   int ans2 = 0;
   if (a[0] == a.back()) {
      int len = cnt1 + cnt2;
      ans2 = n - len;
   } else {
      int len = max(cnt1, cnt2);
      ans2 = n - len;
   }

   println(min(ans1, ans2));

   
   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------

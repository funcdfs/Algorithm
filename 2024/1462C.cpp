// link: https://codeforces.com/contest/1462/problem/C C. Unique Number
// time: 2024/9/20 12:59:56 https://github.com/funcdfs

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

   // every digits's sum == n 
   // find the smallest number

   if (n <= 9) {
      println(n);
      return;
   }
/*
// ac:, but ugly
   int lastNum = 9;
   int initn = n;
   string ans; 
   unordered_map<int, bool> st;
   int now = 0;
   while (true) { 
      dbg(n, lastNum, ans);
      if (n >= lastNum) {
         ans += string(1, '0' + lastNum);
         n -= lastNum;
         now += lastNum;
         st[lastNum] = true;
         lastNum -= 1;
      } else {
         if (n == 0) {
            reverse(ans.begin(), ans.end());
            println(ans);
            return;
         } else {
            if (st[n] == false) {
               ans += string(1, '0' + n);
               now += n;
               reverse(ans.begin(), ans.end());
               println(ans);
               return;
            }
            println(-1);
            return;
         }
      }
      if (now == initn) {
         reverse(ans.begin(), ans.end());
         println(ans);
         return;
      }
      if (lastNum == 0) {
         println(-1);
         return;
      }
   }
*/


   // int cnt = n / 9;
   // int left = n % 9;

   // string s;
   // s += string(1, '0' + left);
   // s += string(cnt, '0' + 9);

   // println(s);


// better: https://codeforces.com/contest/1462/submission/101265333

   if (n > 45) {
      println(-1);
      return;
   }

   int lastNum = 9;
   string ans;

   while (n > 0) {
      int thisLoopNum = min(n, lastNum);
      ans += string(1, '0' + thisLoopNum);
      n -= thisLoopNum;
      lastNum = lastNum - 1;
   }

   reverse(ans.begin(), ans.end());
   println(ans);
   
   
   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------

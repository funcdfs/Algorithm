// link: https://codeforces.com/contest/1520/problem/B -> B. Ordinary Numbers
// time: 2025/2/14 16:57:05 https://github.com/funcdfs

#pragma region headers_and_definitions // clang-format off
#include <bits/stdc++.h>
using namespace std; /* golang types */
/* int  int8  int16   int32   int64  */ using int8 = signed char; using int16 = short; using int32 = int; using int64 = long long;
/* uint uint8 uint16  uint32  uint64 */ using uint8 = unsigned char; using uint16 = unsigned short; using uint32 = unsigned int; using uint64 = unsigned long long;
/* byte rune  float32 float64        */ using byte = unsigned char; using rune = int; using float32 = float; using float64 = double;
template <class T> istream &operator>> (istream &cin , vector<T>           &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin , valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
struct __init_io { __init_io() { std::cout << fixed << setprecision(       15   ); cin.tie(nullptr); cin.exceptions(ios::badbit | ios::failbit); ios::sync_with_stdio(false);  }} _github_funcdfs; // Global instance
#define endl '\n'
auto solve(int _case) -> void; int32 main() { int testCaseCnt = 0; cin >> testCaseCnt; for (int _case = 1; _case <= testCaseCnt; _case++) { solve(_case); } return 0; }
#ifdef LOCAL
#include <algo/dbg.h>
#else
#define dbg(...)      ;
#define eprint(...)   ;
#define eprintln(...) ;
#endif
template<class T1, class T2> bool Min(T1& a, const T2& b) { return b < a ? a = b, true : false; }
template<class T1, class T2> bool Max(T1& a, const T2& b) { return a < b ? a = b, true : false; }
#pragma endregion headers_and_definitions       // clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------

/*

1 2 3 4 5 6 7 8 9
11 22 33 44 55 66 77 88 99
111 222 333 444 555 666 777 888 999
1111 2222 3333 4444 5555 6666 7777 8888 9999
11111 22222 33333 44444 55555 66666 77777 88888 99999
111111 222222 333333 444444 555555 666666 777777 888888 999999
1111111 2222222 3333333 4444444 5555555 6666666 7777777 8888888 9999999
11111111 22222222 33333333 44444444 55555555 66666666 77777777 88888888 99999999

*/

auto solve(int _case) -> void {

   string n;
   cin >> n;
   int maxDigit = n[0]-'0';
   int ans = (ssize(n)-1)*9;
   string x = string(ssize(n), n[0]);
   dbg(n, x, ans);
   if (n >= x) {
      ans += maxDigit;
   } else {
      ans += maxDigit-1;
   }
   cout << ans << endl;

   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------

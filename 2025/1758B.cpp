// link: https://codeforces.com/contest/1758/problem/B -> B. XOR = Average
// time: 2025/1/4 19:43:50 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h>
using namespace std; /* golang types */
/* int  int8  int16   int32   int64  */ using int8 = signed char; using int16 = short; using int32 = int; using int64 = long long;
/* uint uint8 uint16  uint32  uint64 */ using uint8 = unsigned char; using uint16 = unsigned short; using uint32 = unsigned int; using uint64 = unsigned long long;
/* byte rune  float32 float64        */ using byte = unsigned char; using rune = int; using float32 = float; using float64 = double;
template <class T> istream &operator>> (istream &cin, vector<T>            &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin,  valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
struct __init_io { __init_io() { std::cout << fixed << setprecision(       15   ); cin.tie(nullptr); ios::sync_with_stdio(false);  }} __author_github_funcdfs; // Global instance of __init_io to apply I/O settings.
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
#pragma endregion github_funcdfs       // clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------

#define BitCount(a)      (int)__builtin_popcount(a)
#define BitCountInt64(a) (int)__builtin_popcountll(a)
#define BitAt(x, i)      (((x)>>(i))&1)
#define Bit(x)           (bitset<32>(x))
constexpr inline int     Log2(int64 x) { return x == 0 ? -1 : sizeof(int64) * 8 - 1 - __builtin_clzll(x); }


auto solve(int _case) -> void {

   int n = 0;
   cin >> n;

   // xor sum == average value
   // construct a array

   // a^a == 0
   // a^0 == a

   if (n%2 == 1) {
      for (int i = 0; i < n; i++) {
         print("{} ", n);
      }
      println("");
   } else if (n%2 == 0) {
      // 2==1^3
      if (n == 2) {
         print("{} {}\n", 1, 3);
      } else if (n > 2) {
         int cnt = n - 2;
         for (int i = 0; i < cnt; i++) {
            print("{} ", 2);
         }
         print("{} {}\n", 1, 3);
      }
   }

   // dbg(Bit(1), Bit(2), Bit(3));
   // 1^3 == 2


   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------

// link: https://atcoder.jp/contests/abc381/tasks/abc381_a -> A - 11/22 String
// time: 2024/12/7 16:58:11 https://github.com/funcdfs

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
void solve(); int32 main() { solve(); return 0; }

#ifdef LOCAL
#define eprint(...)    std::cerr << format(__VA_ARGS__)
#define eprintln(...)  std::cerr << format(__VA_ARGS__) << '\n'
#else
#define eprint(...)   ;
#define eprintln(...) ;
#endif

#define print(...)    std::cout << format(__VA_ARGS__)
#define println(...)  std::cout << format(__VA_ARGS__) << '\n'
template<class T1, class T2> bool Min(T1& a, const T2& b) { return b < a ? a = b, true : false; }
template<class T1, class T2> bool Max(T1& a, const T2& b) { return a < b ? a = b, true : false; }
#pragma endregion github_funcdfs   // clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------


void solve() {
   int n = 0;
   cin >> n;
   string s;
   cin >> s;
   assert(ssize(s) == n);

   auto check = [&]() -> bool {
      if (n % 2 == 0) {
         return false;
      } else {
         if (n == 1 and s == "/") {
            return true;
         }
         if (s[ssize(s) / 2] != '/') {
            return false;
         } else {
            for (int i = 0; i < n/2; i++) {
               if (s.begin()[i] != '1' || s.rbegin()[i] != '2') {
                  return false;
               }
            }
         }
         return true;
      }
   };

   if (check() == true) {
      // println("Yes");
      cout << "Yes" << endl;
   } else {
      // println("No");
      cout << "No" << endl;
   }

   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------

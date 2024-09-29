// link: https://codeforces.com/problemset/problem/5/C C. Longest Regular Bracket Sequence
// time: 2024/9/29 16:46:23 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h>
/* ----------------------------- using golang types ----------------------------- */
/* int  int8  int16   int32   int64  */ using int8 = signed char; using int16 = short; using int32 = int; using int64 = long long; using namespace std;
/* uint uint8 uint16  uint32  uint64 */ using uint8 = unsigned char; using uint16 = unsigned short; using uint32 = unsigned int; using uint64 = unsigned long long;
/* byte rune  float32 float64        */ using byte = unsigned char; using rune = int; using float32 = float; using float64 = double;
/* ----------------------------- Macro Functions ----------------------------- */
template<class T1, class T2> bool Min(T1& a, const T2& b) { return b < a ? a = b, true : false; }  // For diff types: If b is less than a, update a and return true.
template<class T1, class T2> bool Max(T1& a, const T2& b) { return a < b ? a = b, true : false; }  // For diff types: If b is greater than a, update a and return true.
/* ----------------------------- Debugging tools ----------------------------- */
#ifdef LOCAL             // for local builds; disabled in online builds
#include "algo/dbg.h"    // Include debugging utilities when running locally.
#else
#define dbg(...)      ;  // Disable debug output in non-local builds.
#define eprint(...)   ;  // Disable error printing in non-local builds.
#define eprintln(...) ;  // Disable error printing with newline in non-local builds.
#endif
/* ----------------------------- Define efficient I/O macros ----------------------------- */
#define endl '\n'     // Use '\n' instead of std::endl to avoid flushing the output buffer, improving performance.
#define print(...)    std::cout << format(__VA_ARGS__)           /* C++23 std::print()   -> the format string is printed to the standard output */
#define println(...)  std::cout << format("{0}\n", __VA_ARGS__); /* C++23 std::println() -> to print a single value and append a newline */
template <class T> istream &operator>> (istream &cin, vector<T>            &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin,  valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
struct __init_io { __init_io() { std::cout << fixed << setprecision(       15   /* Set the floating-point precision */); cin.tie(nullptr); ios::sync_with_stdio(false);  }} __author_github_funcdfs; // Global instance of __init_io to apply I/O settings.
void solve(); int32 main() { solve(); return 0; }
#pragma endregion github_funcdfs       // clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------


void solve() {

   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------

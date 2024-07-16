// link: https://codeforces.com/contest/118/problem/D D. Caesar's Legions
// time: 2024/7/4 12:50:27 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h> 
using namespace std; using int32 = signed; using uint32 = unsigned; using float32 = double; using int64 = long long; using uint64 = unsigned long long; using float64 = long double; 
template <class T> istream &operator>> (istream &cin,  vector<T>           &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin,  valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
#define endl           '\n'
#define print(...)     cout << format(__VA_ARGS__)
#define println(...)   cout << format("{0}\n", __VA_ARGS__)
struct _INIT_IO_END { _INIT_IO_END() { cout << fixed << setprecision(   15   );  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs; 
#ifdef  LOCAL //  dbg
#include "algo/dbg.h"
#else
#define dbg(...)    ;
#define eprint(...) ;
#endif
auto solve() -> void; /* main --> */ int32 main() {      solve(); return 0; }
#pragma endregion github_funcdfs       // clang-format on

#pragma region Modular_DefineCode // clang-format off

template <typename T> T inverse(T a, T m) { T u = 0, v = 1; while (a != 0) { T t = m / a; m -= t * a; swap(a, m); u -= t * v; swap(u, v); } assert(m == 1); return u; }
template <typename T>
class Modular {
 public: using Type = typename decay<decltype(T::value)>::type;
  constexpr Modular() : value() {}
  template <typename U> Modular(const U& x) { value = normalize(x); }
  template <typename U> static Type normalize(const U& x) { Type v; if (-mod() <= x && x < mod()) v = static_cast<Type>(x); else v = static_cast<Type>(x % mod()); if (v < 0) v += mod(); return v; }
  const Type& operator()() const { return value; }
  template <typename U> explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }
  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }
  template <typename U = T> typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value)); return *this; }
  template <typename U = T> typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type& operator*=(const Modular& rhs) {
    long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod()); value = normalize(value * rhs.value - q * mod()); return *this; }
  template <typename U = T> typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value); return *this; }
  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
  friend const Type& abs(const Modular& x) { return x.value; }
  template <typename U> friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
  template <typename U> friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
  template <typename V, typename U> friend V& operator>>(V& stream, Modular<U>& number);
 private: Type value;
};
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }
template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template<typename T, typename U> Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0); Modular<T> x = a, res = 1; U p = b; while (p > 0) { if (p & 1) res *= x; x *= x; p >>= 1; } return res; }
template <typename T> bool IsZero(const Modular<T>& number) { return number() == 0; }
template <typename T> string to_string(const Modular<T>& number) { return to_string(number()); }
template <typename U, typename T> U& operator<<(U& stream, const Modular<T>& number) { return stream << number(); }
template <typename U, typename T> U& operator>>(U& stream, Modular<T>& number) { typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x; number.value = Modular<T>::normalize(x); return stream; }
// inverse(a, m);     power(a, b);      C(n, k);
#pragma endregion Modular_DefineCode   // clang-format on


// using ModType = int; /* old c++ */
// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& md = VarMod::value =  ...  ;
// using Mint = Modular<VarMod>;


constexpr int md = 100000000;   // 1000000007 998244353
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

// vector<Mint> fact(1, 1);
// vector<Mint> inv_fact(1, 1);
// Mint C(int n, int k) {
//	if (k < 0 || k > n) {
//	  return 0;
//	}
//	while ((int) fact.size() < n + 1) {
//	  fact.push_back(fact.back() * (int) fact.size());
//	  inv_fact.push_back(1 / fact.back());
//	}
//	return fact[n] * inv_fact[k] * inv_fact[n - k];
// }

// -------------------------------------------------------------------
auto solve() -> void {
   int n1, n2, k1, k2;
   cin >> n1 >> n2 >> k1 >> k2;
   vector f(n1 + 1, vector(n2 + 1, vector(max(k1, k2) + 1, vector<Mint>(2, 0))));
   f[1][0][1][0] = 1, f[0][1][1][1] = 1;
   for (int i = 0; i <= n1; i++) {
      for (int j = 0; j <= n2; j++) {
         if (i > 0) {
            for (int k = 2; k <= k1; k++) {
               f[i][j][k][0] = f[i - 1][j][k - 1][0];
            }
            for (int k = 1; k <= k2; k++) {
               f[i][j][1][0] += f[i - 1][j][k][1];
            }
         }
         if (j > 0) {
            for (int k = 2; k <= k2; k++) {
               f[i][j][k][1] = f[i][j - 1][k - 1][1];
            }
            for (int k = 1; k <= k1; k++) {
               f[i][j][1][1] += f[i][j - 1][k][0];
            }
         }
      }
   }
   Mint ans = 0;
   for (int i = 1; i <= k1; i++) {
      ans += f[n1][n2][i][0];
   }
   for (int i = 1; i <= k2; i++) {
      ans += f[n1][n2][i][1];
   }
   cout << ans << endl;
   return;
}

// -------------------------------------------------------------------

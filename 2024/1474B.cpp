// link: https://codeforces.com/contest/1474/problem/B B. Different Divisors
// time: 2024/7/4 18:43:13 https://github.com/funcdfs

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
#pragma endregion github_funcdfs       // clang-format on


#pragma region Modular_DefineCode // clang-format off
template <typename T> T inverse(T a, T m) {
    T u = 0, v = 1; while (a != 0) { T t = m / a;
    m -= t * a; swap(a, m); u -= t * v; swap(u, v); }
    assert(m == 1); return u; }
template <typename T> class Modular { public:
    using Type = typename decay<decltype(T::value)>::type;
    constexpr Modular() : value() {}
    template <typename U> Modular(const U& x) { value = normalize(x); }
    template <typename U> static Type normalize(const U& x) { Type v; 
        if (-mod() <= x && x < mod()) { v = static_cast<Type>(x); }
        else {v = static_cast<Type>(x % mod());} if (v < 0) v += mod(); return v; }
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

    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value)); return *this; }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type& operator*=(const Modular& rhs) {
        long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod()); return *this; }
    template <typename U = T>
    typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
        value = normalize(value * rhs.value); return *this; }
    Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
    friend const Type& abs(const Modular& x) { return x.value; }
    template <typename U> friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
    template <typename U> friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
    template <typename V, typename U> friend V& operator>>(V& stream, Modular<U>& number);

 private:
  Type value;
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
    assert(b >= 0); Modular<T> x = a, res = 1; U p = b;
    while (p > 0) { if (p & 1) res *= x; x *= x; p >>= 1; } return res; }
template <typename T> bool IsZero(const Modular<T>& number) {
    return number() == 0; }
template <typename T> string to_string(const Modular<T>& number) {
    return to_string(number()); }

// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T> U& operator<<(U& stream, const Modular<T>& number) {
    return stream << number(); }
// U == std::istream? but done this way because of fastinput
template <typename U, typename T> U& operator>>(U& stream, Modular<T>& number) {
    typename common_type<typename Modular<T>::Type, long long>::type x;
    stream >> x; number.value = Modular<T>::normalize(x); return stream; }

// inverse(a, m);	  power(a, b);		C(n, k);		Fact(n); 

#pragma endregion Modular_DefineCode   // clang-format on


// using ModType = int; /* old c++ */
// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& md = VarMod::value =  ...  ;
// using Mint = Modular<VarMod>;


constexpr int md = 2147483647;   // 1000000007	998244353	2147483647	4294967295	9223372036854775807
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

// vector<Mint> fact(1, 1);
// vector<Mint> inv_fact(1, 1);
// Mint C(int n, int k) {
// 	if (k < 0 || k > n) {
// 	  return 0;
// 	}
// 	while ((int) fact.size() < n + 1) {
// 	  fact.push_back(fact.back() * (int) fact.size());
// 	  inv_fact.push_back(1 / fact.back());
// 	}
// 	return fact[n] * inv_fact[k] * inv_fact[n - k];
// }


// vector<Mint> fact(1, 1);
// Mint F(int n) {
//	 while (int(fact.size()) < n + 1) {
//		 fact.push_back(fact.back() * (int)fact.size());
//	 }
//	 return fact[n];
// }


#pragma region factorizer_DefineCode // clang-format off

namespace factorizer {	// 质数因子分解器
    template <typename T> struct FactorizerVarMod { static T value; };
    template <typename T> T FactorizerVarMod<T>::value;

    template <typename T> 
    bool IsPrime(T n, const vector<T>& bases) {
        if (n < 2) { return false; } vector<T> small_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        for (const T& x:small_primes){if(n%x==0){return n==x;}}if(n<31*31){return true; }
        int s = 0; T d = n - 1; while ((d & 1) == 0) { d >>= 1; s++; }
        FactorizerVarMod<T>::value = n; for (const T& a : bases) { if (a % n == 0) { continue; }
        Modular<FactorizerVarMod<T>> cur=a;cur=power(cur,d);if(cur==1){continue;}bool witness = true;
        for (int r = 0; r < s; r++) { if (cur == n - 1) { witness = false; break; } cur *= cur; }
        if (witness) { return false; } } return true;
    }
    // 判断一个数是否为质数的函数 for int64
    bool IsPrime(int64_t n) { return IsPrime(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});}
    // 判断一个数是否为质数的函数 for int32
    bool IsPrime(int32_t n) { return IsPrime(n, {2, 7, 61}); }

    // but if you really need uint64_t version...
    /*
    bool IsPrime(uint64_t n) {
        if (n < 2) { return false; }
        vector<uint32_t> small_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        for (uint32_t x : small_primes) { if (n == x) { return true; } if (n % x == 0) { return false; } }
        if (n < 31 * 31) { return true; } uint32_t s = __builtin_ctzll(n - 1); uint64_t d = (n - 1) >> s;
        function<bool(uint64_t)> witness = [&n, &s, &d](uint64_t a) {
            uint64_t cur = 1, p = d; while (p > 0) { if (p & 1) { cur = (__uint128_t) cur * a % n; }
            a = (__uint128_t) a * a % n; p >>= 1; } if (cur == 1) { return false; }
            for (uint32_t r = 0; r < s; r++) { if (cur == n - 1) { return false; } cur = (__uint128_t) cur * cur % n;}
            return true;
        }; vector<uint64_t> bases_64bit = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
        for (uint64_t a : bases_64bit) { if (a % n == 0) { return true; } if (witness(a)) { return false;}}
        return true;
    }
    */
    vector<int> primes;	// 存储范围内的所有的质数 
    vector<int> least = {0, 1};  int precalculated = 1;
    
    // 使用线性筛法筛选质数
    void RunLinearSieve(int n) {
        n = max(n, 1); least.assign(n + 1, 0); primes.clear();
        for (int i = 2; i <= n; i++) { if (least[i] == 0) { least[i] = i; primes.push_back(i); }
            for (int x : primes) { if (x > least[i] || i * x > n) { break; } least[i * x] = x; } }
        precalculated = n;
    }
    
    // 使用慢速筛法筛选质数
    void RunSlowSieve(int n) {
        n = max(n, 1); least.assign(n + 1, 0);
        for (int i = 2; i * i <= n; i++) { if (least[i] == 0) { for (int j = i * i; j <= n; j += i) {
        if (least[j] == 0) { least[j] = i; } } } } primes.clear(); for (int i = 2; i <= n; i++) {
        if (least[i] == 0) { least[i] = i; primes.push_back(i); } } precalculated = n;
    }
    
    // 筛选范围内的所有质数
    void RunSieve(int n) {
        RunLinearSieve(n);
        // RunSlowSieve(n);
    }
    int PrimesSize() { return int(factorizer::primes.size()); }
    
    // 合并两个质因数分解结果
    template <typename T> 
    vector<pair<T, int>> MergeFactors(const vector<pair<T, int>>& a, const vector<pair<T, int>>& b) {
        vector<pair<T, int>> c; int i = 0; int j = 0;
        while (i < (int)a.size() || j < (int)b.size()) { if (i < (int)a.size() && j < (int)b.size() 
        &&a[i].first==b[j].first){c.emplace_back(a[i].first,a[i].second+b[j].second);++i;++j; continue; }
        if (j == (int)b.size() || (i < (int)a.size() && a[i].first < b[j].first)) { c.push_back(a[i++]); } 
        else { c.push_back(b[j++]); }} return c;
    }

    // 使用 Pollard's rho 算法进行质因数分解.
    template <typename T>
    vector<pair<T, int>> RhoC(const T& n, const T& c) { if (n <= 1) { return {}; }
        if ((n & 1) == 0) { return MergeFactors( { {2, 1} }, RhoC(n / 2, c)); }
        if (IsPrime(n)) {return{{n,1}};}FactorizerVarMod<T>::value = n; Modular<FactorizerVarMod<T>> x = 2; 
        Modular<FactorizerVarMod<T>> saved = 2; T power = 1; T lam = 1; while (true) { x = x * x + c;
            T g=__gcd((x-saved)(),n);if(g!=1){return MergeFactors(RhoC(g,c+1),RhoC(n/g,c+1));}
            if (power == lam) { saved = x; power <<= 1; lam = 0; } lam++;
        } return {};
    }

    // 给定一个整数 N ，试快速找到它的一个因数。使用 Pollard's rho 算法进行质因数分解.
    template <typename T>
    vector<pair<T, int>> Rho(const T& n) { return RhoC(n, static_cast<T>(1)); }

    // 质因数分解函数
    template <typename T>
    vector<pair<T, int>> Factorize(T x) {
        if (x <= 1) { return {}; } if (x <= precalculated) { vector<pair<T, int>> ret;
        while (x > 1) { if (!ret.empty() && ret.back().first == least[x]) { ret.back().second++;
        } else { ret.emplace_back(least[x], 1); } x /= least[x]; }return ret; }
        if (x <= static_cast<int64_t>(precalculated) * precalculated) {
        vector<pair<T, int>> ret; if (!IsPrime(x)){for(T i:primes){T t=x/i;if(i>t){break;}
        if (x == t * i) { int cnt = 0; while (x % i == 0) { x /= i; cnt++; } ret.emplace_back(i, cnt);
        if(IsPrime(x)){break;}}}}if(x>1){ret.emplace_back(x,1);}return ret;}return Rho(x);
    }

    // 根据质因数构建所有因数
    template <typename T>
    vector<T> BuildDivisorsFromFactors(const vector<pair<T, int>>& factors) {
        vector<T> divisors = {1}; for (auto& p : factors) { int sz = (int)divisors.size();
        for (int i = 0; i < sz; i++) { T cur = divisors[i]; for (int j = 0; j < p.second; j++) {
        cur*=p.first;divisors.push_back(cur);}}}sort(divisors.begin(),divisors.end());return divisors;
    }
}	// namespace factorizer

#pragma endregion factorizer_DefineCode   // clang-format on

// -------------------------------------------------------------------
auto solve(int _case) -> void {
   dbg(_case);

   int d = 0;
   cin >> d;

   factorizer::RunSieve(20011);

   auto find = [&](int x) -> int {
      int l = 0, r = factorizer::PrimesSize() - 1;
      while (l < r) {
         int mid = (l + r) >> 1;
         if (factorizer::primes[mid] >= x) {
            r = mid;
         } else {
            l = mid + 1;
         }
      }
      return factorizer::primes[l];
   };
   // dbg(factorizer::primes);
   /**
    * {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101,
    * 103, 107,
    *
    */
   // 1, x, y, a  -> a = x * y, find(min( x >= d+1 ))  find(min( y >= x+d )) 
  
   int a = find(d+1);
   int b = find(a+d);

   dbg(d, a, b, b-a); 

   cout << a * b << endl;

   return;
}

// -------------------------------------------------------------------

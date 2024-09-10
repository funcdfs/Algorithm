#include <bits/stdc++.h>
using namespace std;

std::string cpp_standard() {
   auto VER = __cplusplus;
   if (VER < 201103) {
      return "C++98";
   } else if (VER == 201103) {
      return "C++11";
   } else if (VER == 201402) {
      return "C++14";
   } else if (VER == 201703) {
      return "C++17";
   } else {
      return "C++20";
   }
}

std::string ver_string(int a, int b, int c) {
   std::ostringstream ss;
   ss << a << '.' << b << '.' << c;
   return ss.str();
}

std::string true_cxx =
#ifdef __clang__
   "Clang++";
#else
   "G++";
#endif

std::string true_cxx_ver =
#ifdef __clang__
   ver_string(__clang_major__, __clang_minor__, __clang_patchlevel__);
#else
   ver_string(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#endif

signed main() {
   cout << true_cxx << ' ' << true_cxx_ver << '\n';
   cout << "Now C++ standard: " << cpp_standard();
}
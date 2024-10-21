#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   std::println(a);
   return 0;
}
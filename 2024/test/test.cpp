#include <bits/stdc++.h>
#include <dbg.h>
using namespace std;

int main() {
   dbg("hello world");
   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   dbg(n, a);
   sort(a.begin(), a.end());
   cout << format("{}", a);
   dbg(a);
   return 0;
}

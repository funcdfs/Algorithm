
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>	// Common file
#include <ext/pb_ds/tree_policy.hpp>		 // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
   Tree<int> X;	// ordered set only contains unique values

   X.insert(1);
   X.insert(2);
   X.insert(4);
   X.insert(8);
   X.insert(16);

   cout << *X.find_by_order(0) << endl;	// 1
   cout << *X.find_by_order(1) << endl;	// 2
   cout << *X.find_by_order(2) << endl;	// 4
   cout << *X.find_by_order(4) << endl;	// 16

   // finding number of elements smaller than value
   cout << X.order_of_key(-5) << endl;	 // 0
   cout << X.order_of_key(1) << endl;	  // 0
   cout << X.order_of_key(3) << endl;	  // 2
   cout << X.order_of_key(4) << endl;	  // 2
   cout << X.order_of_key(400) << endl;	// 5

   // lower bound -> first element >= X in the set
   cout << "Lower Bound of 6: " << *X.lower_bound(6) << endl;
   // Lower Bound of 6: 8
   cout << "Lower Bound of 2: " << *X.lower_bound(2) << endl;
   // Lower Bound of 2: 2
   cout << endl;


   // Upper bound -> first element > X in the set
   cout << "Upper Bound of 6: " << *X.upper_bound(6) << endl;
   // Upper Bound of 6: 8
   cout << "Upper Bound of 1: " << *X.upper_bound(1) << endl;
   // Upper Bound of 1: 2
   if (X.upper_bound(16) == end(X)) {
      cout << "not find" << endl;	// last node is end(X) == nil
   } else {
      cout << *X.upper_bound(16) << endl;
   }
   cout << endl;

   // Remove elements
   X.erase(1);
   X.erase(11);	// element that is not present is not affected

   // X contains X = 2 4 8 16
   cout << "X = ";
   for (auto i : X) {
      cout << i << " ";
   }
   cout << endl;
   cout << endl;
   return 0;
}

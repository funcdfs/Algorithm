#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif
/*-----------------------*/

int solve(int n, string& a, string& b) {
	int ans = 0; 
	
	for (int i = 0; i < n; i++) {
		if (b[i] == '1') {
			if (a[i] == '0') {
				a[i] = '*';
				ans++; 
			} else if (i && a[i-1]  == '1') {
				a[i-1] = '*'; // dead pawns 
				ans++; 
			} else if (i+1 < n && a[i+1] == '1') {
				a[i+1] = '*'; 
				ans++; 
			}
		}
	} 
	
	return ans; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt = 0; 
    cin >> tt; 
    
    while (tt--) {
    	int n = 0; 
    	cin >> n; 
    	string a = "", b = ""; 
    	cin >> a >> b; 
    	
    	cout << solve(n, a, b) << endl; 
    }

    return 0;
}

/*

hints1: 每个国王的落点非常的有限（目的地的三个格子） 
hints2: 贪心解决

从左向右枚举棋子，
对于当前的一个棋子
	若能向前移动到顶就移动到顶，(当前行的空地只有当前行的能利用，所以直接考虑向前移动)
	否则若左边有敌方棋子就向左，(由于是从左往右枚举，则一旦过了这一格就再也没有棋子能利用这一格了，所以也直接利用)
	最后考虑右边有敌方棋子则向右移动。
	(0101 虽然会占用第二个棋子向左移动的方案，但是就算把目的地的第一个1给国王的第二个1，这个1也就是提供了一种方案
	 1010) 但是额外占用了一个后面拥有更多可能性的国王的棋子，前面反而剩下了一个没有榨干全部价值的棋子 

*/
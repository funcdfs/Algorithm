/*
 @ KONNG
 @ 2022-01-25-16-54-08
 @ https://github.com/fengwei2002/Algorithm
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 0x3f3f3f3f
typedef long long ll;

using namespace std;

const int N = 55;
char g[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	int t = 0;
	cin >> t;
	
	while (t--) {
		int n, m, r, c;
		cin >> n >> m >> r >> c;
		
		bool existBlack = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> g[i][j];
				if (g[i][j] == 'B') {
					existBlack = true;
				}
			}
		}
		
		r--, c--;
		
		if (g[r][c] == 'B') {
			cout << 0 << endl;
			continue;
		}
		
		if (existBlack == false) {
			cout << -1 << endl;
			continue;
		}
		
		existBlack = false;
		

		
		for (int i = 0; i < n; i++) {
			if (g[i][c] == 'B') {
				existBlack = true;
			}
		}
		
		for (int j = 0; j < m; j++) {
			if (g[r][j] == 'B') {
				existBlack = true;
			}
		}
		
		if (existBlack == true) {
			cout << 1 << endl;
		} else {
			cout << 2 << endl;
		}
	}

    return 0;
}





































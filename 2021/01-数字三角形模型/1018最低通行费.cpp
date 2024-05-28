#include <iostream>
#include <cstring>

using namespace std;

const int N = 110, MAX = 1e6;
int g[N][N], f[N][N];
int n;

int main() {
	cin >> n;
	memset(f, MAX, sizeof f);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!i && !j) f[i][j] = g[i][j];
			if (i) f[i][j] = min(f[i][j], f[i - 1][j] + g[i][j]);
			if (j) f[i][j] = min(f[i][j], f[i][j - 1] + g[i][j]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << f[i][j] << ' ';
		}
		cout << endl;
	}
	
	cout << f[n - 1][n - 1] << endl;
	
	return 0;
}
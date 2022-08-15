// Problem: 樱桃网
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/916/
// date: 2022-07-26 19:21:36
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std; 

const int N = 1e5+10; 
int n, m; 
int p[N]; 

int find(int x) {
	if (p[x] != x) p[x] = find(p[x]); 
	return p[x]; 
} 

int main() {
	int T; 
	cin >> T; 
	for (int C = 1; C <= T; C++) {
		cin >> n >> m; 
		for (int i = 1; i <= n; i++) p[i] = i; 
		
		int k = 0; 
		while (m--) {
			int a, b; 
			cin >> a >> b; 
			if (find(a) != find(b)) {
				p[find(a)] = p[find(b)]; 
				k++; 
			}
		} 
		
		printf("Case #%d: %d\n", C, k*1 + (n-1-k)*2);  
	}
}
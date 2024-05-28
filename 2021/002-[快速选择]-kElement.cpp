#include <algorithm>
#include <iostream>

using namespace std;
const int N = 1e6 + 10;

int n, k, q[N];

int quickSelect(int q[], int l, int r, int k) {
    if (l >= r) return q[l]; 
    int x = q[(l + r) >> 1]; 
    int i = l - 1; 
    int j = r + 1; 

    while (i < j) {
        do i++; while (q[i] < x); 
        do j--; while (q[j] > x); 
        if (i < j) swap(q[j], q[i]); 
    }
    if (k <= (j - l + 1)) return quickSelect(q, l, j, k); 
    return quickSelect(q, j + 1, r, k - (j - l + 1)); 
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> q[i]; 

    quickSelect(q, 0, n - 1, k); 

    cout << q[k - 1] << endl; 

    return 0; 
}
/*
 @ konng0120@gmail.com$
 @ 2022-03-21-13-06-51
 @ https://github.com/fengwei2002/Algorithm
*/

#include <algorithm>
#include <iostream>
#include <vector>

#define INF 0x3f3f3f3f
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    string h;
    cin >> h;

    for (int j = 1; j <= t; j++) {
        for (int i = 0; i < n; i++) {
            if (h[i] == 'B' && h[i + 1] == 'G') {
                swap(h[i], h[i + 1]);
                i++;
            }
        }
    }
    cout << h;
}

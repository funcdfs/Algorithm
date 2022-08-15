// #define d(a)  // https://github.com/fengwei2002/Algorithm
// #define dline // konng0120@gmail.com
// #define dendl // https://www.acwing.com/activity/content/problem/content/1978/

#define d(a)  cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#define LL  long long
#define ULL unsigned long long
#define PII pair<int, int>
#define INF 0x3f3f3f3f

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 1e5 + 10; 
int n; 
int a[N]; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n; 
    for (int i = 0; i < n; i++) cin >> a[i]; 
    
    sort(a, a + n); 
    
    int ans = 0; 
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - a[n / 2]); 
    }
    
    cout << ans << endl; 
    
    return 0;
}
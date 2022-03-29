#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std; 

int m, n; 
const int M = 1010; 
const int N = 2010; 

int a[M][N]; 

int main() {
    int T = 0; 
    cin >> T;
    while (T--) {
        int m, n; 
        cin >> m >> n; 
        vector<priority_queue<int, vector<int>, function<bool(int&, int&)>>> vecPQ; 
        
        for (int i = 0; i < m; i++) {
            function<bool(int&, int&)> compare = [](int& a, int& b) { return a > b; }; 
            priority_queue<int, vector<int>, function<bool(int&, int&)>> minPQ(compare); 
            for (int j = 0; j < n; j++) {
                cin >> a[i][j]; 
                minPQ.push(a[i][j]); 
            }
            vecPQ.push_back(minPQ); 
        }
        
        vector<int> ans; 
        for (auto x : vecPQ) {
            ans.push_back(x.top()); x.pop(); 
        }
        int a = accumulate(ans.begin(), ans.end(), 0); 
        cout << a << endl; 
    }
    
    return 0; 
}
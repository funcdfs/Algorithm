// Problem: 八数码
// Contest: AcWing
// url:  https://www.acwing.com/problem/content/847/
// date: 2022-04-03 16:58:07
// Memory Limit: 64 MB
// Time Limit:   1000 ms
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std; 

int bfs(string start) {
    string end = "12345678x"; 
    if (start == end) return 0; 
    
    queue<string> q; 
    unordered_map<string, int> d; 
    
    int dx[4] = {-1, 0, 1, 0}; 
    int dy[4] = {0, 1, 0, -1}; 
    
    q.push(start); 
    while (q.size()) {
        auto t = q.front(); 
        q.pop(); 
        
        int x, y; 
        for (int i = 0; i < 9; i++) {
            if (t[i] == 'x') {
                x = i / 3; 
                y = i % 3; 
                break; 
            }
        }
        
        for (int i = 0; i < 4; i++) {
            string state = t; 
            int a = x + dx[i]; 
            int b = y + dy[i];
            if (a < 0 || a >= 3 || b < 0 || b >= 3) continue; 
            swap(state[x * 3 + y], state[a * 3 + b]); 
            
            if (d.count(state) == 0) { // 如果之前搜索过不可以的话 之后也不要了 
                d[state] = d[t] + 1; 
                if (state == end) {
                    return d[state]; 
                } else {
                    q.push(state); 
                }
            }
        }
    }
    
    return -1; 
}

int main() {
    string start; char c; 
    while (cin >> c) {
        start += c; 
    }
    cout << bfs(start) << endl; 
    
    return 0; 
}
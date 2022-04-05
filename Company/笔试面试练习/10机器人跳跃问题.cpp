// Problem: 机器人跳跃问题
// Contest: AcWing
// url:  https://www.acwing.com/problem/content/732/
// date: 2022-04-03 16:11:18
// Memory Limit: 64 MB
// Time Limit:   3000 ms

#include <iostream>
using namespace std; 

const int N = 1e5 + 10; 

int n; 
int h[N]; 

bool check(int e) {
    for (int i = 1; i <= n; i++) {
        e = e * 2 - h[i]; 
        if (e >= N) return true; 
        if (e < 0) return false; 
    } 
    
    return true;  // 成功的到达了第 n 个建筑物
}

int main() {
    cin >> n; 
    for (int i = 1; i <= n; i++) cin >> h[i]; 
    
    int l = 0; 
    int r = 1e5; 
    while (l < r) {
        int mid = (l + r) >> 1; 
        if (check(mid)) r = mid; 
        else l = mid + 1; 
    } 
    cout << r << endl; 
}
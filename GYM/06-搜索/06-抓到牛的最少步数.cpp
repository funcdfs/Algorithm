// URL: https://www.acwing.com/problem/content/1102/
// NAME: 抓住那头牛, AcWing
// LIMIT: 64 MB, 1000 ms, DATE: 2022-08-21 15:57:10


#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*----------------------------------*/

const int N = 1e5 + 10; 
int n, k; 
int q[N]; 
int dist[N]; 

int bfs() {
    memset(dist, -1, sizeof dist); 
    dist[n] = 0; 
    
    int hh = 0, tt = -1; 
    q[++tt] = n; 
    
    while (hh <= tt) {
        int t = q[hh++]; 
        if (t == k) return dist[k]; 
        
        if (t + 1 < N && dist[t + 1] == -1) {
            dist[t + 1] = dist[t] + 1; 
            q[++tt] = t + 1; 
        } 
        if (t - 1 >= 0 && dist[t - 1] == -1) {
            dist[t - 1] = dist[t] + 1; 
            q[++tt] = t - 1; 
        } 
        if (t * 2 < N && dist[t * 2] == -1) {
            dist[t * 2] = dist[t] + 1; 
            q[++tt] = t * 2; 
        } 
    } 
    
    return -1; 
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    cin >> n >> k; 
    // catch from n to k 
    
    cout << bfs() << endl; 
    
    return 0;
}


/*

每次可以左右移动一个格子，或者向右跳动两倍距离 

求最终抓住牛的最少耗费的时间 

*/
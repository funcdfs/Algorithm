#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;

const int fx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int fy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
//马可以走到的位置

int bx, by, mx, my;
ll f[40][40];
bool s[40][40]; //判断这个点有没有马拦住
int main(){
    scanf("%d%d%d%d", &bx, &by, &mx, &my);
    bx += 2; by += 2; mx += 2; my += 2;
    //坐标+2以防越界
    f[2][1] = 1;//初始化
    s[mx][my] = 1;//标记马的位置
    for(int i = 1; i <= 8; i++) s[mx + fx[i]][my + fy[i]] = 1;
    for(int i = 2; i <= bx; i++){
        for(int j = 2; j <= by; j++){
            if(s[i][j]) continue; // 如果被马拦住就直接跳过
            f[i][j] = f[i - 1][j] + f[i][j - 1];
            //状态转移方程
        }
    }
    printf("%lld\n", f[bx][by]);
    return 0;
} 
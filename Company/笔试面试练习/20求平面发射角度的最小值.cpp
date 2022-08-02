// Problem: 哈默队长
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/698/
// date: 2022-07-26 11:09:42
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <iostream>
#include <cmath>

#define PI 3.141592653579

using namespace std; 

int main() {
	int T; 
	cin >> T; 
	
	for (int C = 1; C <= T; C++) {
		double v, d; 
		cin >> v >> d; 
		
		double g = 9.8; 
		
		double l = 0, r = 45; 
		
		while (r - l > 1e-8) {
			double mid = (l + r) / 2; 
			if ((v * v * sin(mid / 180 * PI) * cos(mid / 180 * PI) * 2 / g) >= d) {
				r = mid; 
			} else {
				l = mid; 
			}
		}
		
		printf("Case #%d: %.8lf\n", C, r); 
	}
	return 0; 
}

/*

给定飞机的 V （速度）和 D （目的地的具体距离）

求最小的起飞角度 [o]

重力加速度是 9.8 m/s^2

假设 t 秒之后落地
	那么 s = v0 * t * cos[o] (1)

具体什么时候落地取决于竖直方向的速度
	v = v0 - g*t

竖直方向飞行的高度是: 
	h = \积分 0 到 t (v0-gt) dt
	h = v0t - 1/2*g*t^2

落地的话就是 v0t - 1/2*g*t^2 = 0 

解得 t = 0 或者是 t = 2v0/g*sin[0] (因为是竖直方向的速度) （2）

将 2 带入 1 得

s = v0* 2v0/g*sin[0] * cos[o]

s = v0*v0 * sin[0]*cos[0] * 2/g




*/
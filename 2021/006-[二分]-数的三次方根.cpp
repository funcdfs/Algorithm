#include <iostream>

using namespace std;

int main() {
    double x = 0;
    scanf("%lf", &x);

    double l = -100, r = 100;
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x)
            r = mid;
        else
            l = mid;
    }
    
    printf("%.6lf", l);
}

// https://www.acwing.com/activity/content/code/content/1403022/
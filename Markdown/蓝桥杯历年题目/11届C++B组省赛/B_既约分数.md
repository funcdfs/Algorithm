![20210814180324-2021-08-14-18-03-26](https://raw.githubusercontent.com/fengwei2002/Pictures_02/master/images/20210814180324-2021-08-14-18-03-26.png)

``` cpp
#include <algorithm>
#include <iostream>
using namespace std;
int ans;
int main() {
    for (int i = 1; i <= 2020; i++) {
        for (int j = 1; j <= 2020; j++) {
            if (__gcd(i, j) == 1) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
```

答案：2481215

algorithm 中有计算最大公约数的 gcd 函数，用一下即可


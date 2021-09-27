![20210814170840-2021-08-14-17-08-42](https://raw.githubusercontent.com/fengwei2002/Pictures_02/master/images/20210814170840-2021-08-14-17-08-42.png)

考虑数字中 2 出现的次数，写个函数将数字拆分为一个一个的数字，如果等于 2 结果++  
for 循环遍历一遍所有函数(数字)即可


``` cpp 
#include <iostream>
using namespace std;
/*2021-08-14-17-07*/

int sum;
int arr[5];

void cal(int a) {
    for (int i = 1; i <= 4; i++) {
        arr[i] = a % 10;
        a /= 10;
    }
    for (int i = 1; i <= 4; i++) {
        //cout << arr[i];
        if (arr[i] == 2) sum ++;
    }
    for (int i = 1; i <= 4; i++) 
        arr[i] = 0;
    //cout << endl;
}

int main() {
    int n = 2020;
    for (int i = 1; i <= n; i++) {
        cal(i);
    }
    cout << sum << endl;
    return 0;
}
```

答案：624

> 注意写题的时候要想着自己的思路，不要想一种写另一种
#include <algorithm>
#include <iostream>
#include <vector>
// n^2复杂度，炸了TLE
using namespace std;
int main() {
    // Each student can be part of at most one team and
    // it is possible that some students are not selected in any team.
    size_t cases = 0;
    cin >> cases;
    size_t endlNumber = cases;
    int tempRate = 0;
    int ans = 0;
    //笑死，ijk用混，根本找不到bug'''''
    for (size_t i = 0; i < cases; i++) {
        size_t n = 0, k = 0;
        cin >> n >> k;

        vector<int> studentsRating;
        for (size_t j = 0; j < n; j++) {
            cin >> tempRate;
            studentsRating.push_back(
                tempRate);  //这里可以直接开辟n个数据的空间，然后读入即可
        }
        sort(studentsRating.begin(), studentsRating.end());  //必须排序后操作，
        //因为简单的从前到后遍历回出现两位选手的和值不刚好匹配的情况，不是最佳抉择

        vector<bool> flag(n, true);
        //由于学生只能进入一个team，所以创建一个boolvector来标记

        for (size_t j = 0; j < n; j++) {
            //寻找单人组队选手
            if (studentsRating.at(j) >= k && flag.at(j) == true) {
                flag.at(j) = false;
                ans += 1;
            }
            //-------------------------------------------------------
            //寻找双人组队选手，注意不能自己ratingx2，没有分身术呜呜呜
            if (flag.at(j) == true && studentsRating.at(j) < k) {
                for (size_t m = j; m < n; m++) {
                    int tempSum = studentsRating.at(j) + studentsRating.at(m);
                    if (m != j && flag.at(m) == true && tempSum >= k) {
                        flag.at(j) = false;
                        flag.at(m) = false;
                        ans = ans + 1;
                        break;  //这里也不能分身 5 8 || 5 2 3 5 1
                                //答案应该是1而不是2，找到就退出继续寻找的循环块
                    }
                }
            }
            //---------------------------------------------------------
        }
        cout << ans;
        ans = 0;
        if (endlNumber > 1) {
            endlNumber -= 1;
            cout << endl;
        }
        //满满的细节，这input示例真的强啊！
    }
    return 0;
}
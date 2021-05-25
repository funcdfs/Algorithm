/*
 * @lc app=leetcode.cn id=1476 lang=cpp
 *
 * [1476] 子矩形查询
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class SubrectangleQueries {
   public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        int L = rectangle.at(0).size();
        this->heng = L;
        this->shu = rectangle.size();
        //使用两次new创建同样大小的空间
        this->mem = new int*[L];
        for (int i = 0; i < L; i++) {
            this->mem[i] = new int[rectangle.size()];
        };
        //进行元素的复制
        for (int i = 0; i < rectangle.size(); i++) {
            for (int j = 0; j < L; j++) {
                mem[i][j] = rectangle.at(i).at(j);
            }
        }
    }

    void updateSubrectangle(int row1,
                            int col1,
                            int row2,
                            int col2,
                            int newValue) {
        for (int i = row1; i < row2; i++) {
            for (int j = col1; j < col2; i++) {
                this->mem[i][j] = newValue;
            }
        }
    }

    int getValue(int row, int col) { return mem[row][col]; }

   private:
    int** mem;
    int heng;
    int shu;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
// @lc code=end

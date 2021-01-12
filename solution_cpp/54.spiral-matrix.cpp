/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (33.09%)
 * Likes:    1949
 * Dislikes: 523
 * Total Accepted:    334K
 * Total Submissions: 1M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */
#include <iostream>
#include <climits>
#include <map>
#include <cstdio>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return {};

        int i1(0), i2(matrix.size()-1), j1(0), j2(matrix[0].size()-1);
        vector<int> result(matrix.size() * matrix[0].size());
        int p = -1;
        while (i1<=i2 && j1<=j2){
            for (int j=j1; j<=j2; ++j)
                result[++p] = matrix[i1][j];
            if (i1==i2)
                break;
            ++i1;
            for (int i=i1; i<=i2; ++i)
                result[++p] = matrix[i][j2];
            if (j1==j2)
                break;
            --j2;
            for (int j=j2; j>=j1; --j)
                result[++p] = matrix[i2][j];
            --i2;
            for (int i=i2; i>=i1; --i)
                result[++p] = matrix[i][j1];
            ++j1;
        }
        return result;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9,10,11,12}};
    for (int i : Solution().spiralOrder(matrix)){
        cout << i <<  " ";
    }
    cout << endl;
    matrix = {{3}, {2}};
    for (int i : Solution().spiralOrder(matrix)){
        cout << i <<  " ";
    }
    cout << endl;
    return 0;
}

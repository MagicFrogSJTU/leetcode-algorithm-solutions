/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 *
 * https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
 *
 * algorithms
 * Hard (38.22%)
 * Likes:    984
 * Dislikes: 74
 * Total Accepted:    50.9K
 * Total Submissions: 132.8K
 * Testcase Example:  '[[1,0,1],[0,-2,3]]\n2'
 *
 * Given a non-empty 2D matrix matrix and an integer k, find the max sum of a
 * rectangle in the matrix such that its sum is no larger than k.
 * 
 * Example:
 * 
 * 
 * Input: matrix = [[1,0,1],[0,-2,3]], k = 2
 * Output: 2 
 * Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is
 * 2,
 * and 2 is the max number no larger than k (k = 2).
 * 
 * Note:
 * 
 * 
 * The rectangle inside the matrix must have an area > 0.
 * What if the number of rows is much larger than the number of columns?
 * 
 */
#include <iostream>
#include <climits>
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
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        vector<vector<int>> accum(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        for (int i=0; i<matrix.size(); ++i){
            for (int j=0; j<matrix[0].size(); ++j){
                accum[i+1][j+1] = accum[i+1][j] + accum[i][j+1] + matrix[i][j] - accum[i][j];
            }
        }
        int res = INT_MIN; 
        for (int i2=0; i2<matrix.size(); ++i2){
            for (int j2=0; j2<matrix[0].size(); ++j2){
                for (int i1=0; i1<=i2; ++i1){
                    for (int j1=0; j1<=j2; ++j1){
                        int value2 = accum[i2+1][j2+1] - accum[i2+1][j1] - accum[i1][j2+1] + accum[i1][j1];
                        if (value2 <= k){
                            res = max(res, value2);
                        }
                    }
                }
            }
        }
        return res;
        
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    vector<vector<int>> matrix = {{1,0,1},{0,-2,3}};
    cout << Solution().maxSumSubmatrix(matrix, 2) << endl;
    matrix = {{2,2,-1}};
    cout << Solution().maxSumSubmatrix(matrix, 3) << endl;
    return 0;
}

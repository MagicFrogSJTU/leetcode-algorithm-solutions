/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (36.03%)
 * Likes:    1627
 * Dislikes: 153
 * Total Accepted:    314.5K
 * Total Submissions: 867.5K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 * 
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m(matrix.size()), n(matrix[0].size());

        int left=(0), right(m), mid;
        while (left<right){
            mid = (left+right)/2;
            if (target > matrix[mid][n-1]) {
                left = mid + 1;
            }else {
                right = mid;
            }
        }
        if (left == m) return false;

        auto &vec = matrix[left];
        left=0;
        right=n;
        while (left<right){
            mid = (left+right)/2;
            if (target > vec[mid]) {
                left = mid + 1;
            }else {
                right = mid;
            }
        }
        return vec[left] == target;
        
        
    }
};
// @lc code=end

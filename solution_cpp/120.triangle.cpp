/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (42.79%)
 * Likes:    1882
 * Dislikes: 227
 * Total Accepted:    241.2K
 * Total Submissions: 555.2K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * 
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * 
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 * 
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dps(triangle.size(), INT_MAX);
        dps[0] = triangle[0][0];
        for (int i=1; i<triangle.size(); ++i){
            for (int j=triangle[i].size()-1; j>0; --j){
                dps[j] = min(dps[j], dps[j-1]) + triangle[i][j];
            }
            dps[0] += triangle[i][0];
        }
        return *min_element(dps.begin(), dps.end());
    }
};
// @lc code=end

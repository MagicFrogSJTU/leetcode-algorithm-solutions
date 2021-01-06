/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (36.36%)
 * Likes:    2560
 * Dislikes: 66
 * Total Accepted:    170.2K
 * Total Submissions: 460.5K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
 * 
 * 
 */
#include<vector>
#include<stack>
#include<iostream>
#include<climits>
using namespace std;

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (!heights.size()) return 0;
        if (heights.size()==1) return heights[0];

        heights.push_back(INT_MIN);
        stack<int> lefts;
        lefts.push(heights.size()-1);

        int max_result=0;
        for (int i=0; i<heights.size(); ++i){
            for (int height = heights[lefts.top()], right_index = lefts.top(); height>heights[i]; height = heights[lefts.top()]){
                lefts.pop();
                max_result = max(max_result, (right_index- (lefts.top() == heights.size()-1 ? -1 : lefts.top()))*height);
            }
            lefts.push(i);
        }
        heights.pop_back();
        return max_result;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (!matrix.size() || !matrix[0].size()) return 0;

        vector<int> current_hist(matrix[0].size(), 0);
        int max_result = 0;
        for (int i=0; i<matrix.size(); ++i){
            for (int j=0; j<matrix[0].size(); ++j){
                if (matrix[i][j] == '1')
                    current_hist[j] += 1;
                else
                    current_hist[j] = 0;
            }
            max_result = max(max_result, largestRectangleArea(current_hist));
        }
        return max_result;
        
    }
};
// @lc code=end
// @lc code=end
int main(int argc, char **argv)
{
    vector<vector<char>> input = {{'0', '1'}, {'1', '0'}};
    cout << Solution().maximalRectangle(input) << endl;
    return -1;
}

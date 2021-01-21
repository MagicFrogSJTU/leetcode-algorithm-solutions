/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (33.84%)
 * Likes:    3389
 * Dislikes: 79
 * Total Accepted:    251.4K
 * Total Submissions: 730.8K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
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
        return max_result;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    vector<int> input = {2,1,5,6,2,3};
    cout << Solution().largestRectangleArea(input) << endl;
    input = {2,1,2};
    cout << Solution().largestRectangleArea(input) << endl;
    return 1;
}

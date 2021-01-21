/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (29.92%)
 * Likes:    2322
 * Dislikes: 126
 * Total Accepted:    248.7K
 * Total Submissions: 823.1K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * Example:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 * ⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * Note:
 * 
 * You can assume that you can always reach the last index.
 * 
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int last=-1, maximum=0;
        while (true){
            if (maximum >= nums.size()-1) return step;
            ++step;
            int new_maximum = 0;
            for (int i=last+1; i<=maximum; ++i){
                new_maximum = max(new_maximum, i + nums[i]);
            }
            last = maximum;
            maximum = new_maximum;
        }
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (58.81%)
 * Likes:    3445
 * Dislikes: 79
 * Total Accepted:    540.6K
 * Total Submissions: 903K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
// 4ms
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> proposal;

        dfs(proposal, ans, 0, nums);
        return ans;
    }

    void dfs(vector<int> &proposal, vector<vector<int>> &ans,
            const int pos, const vector<int> &nums) {
        if (pos == nums.size()) {
            ans.push_back(proposal);
            return;
        }

        proposal.push_back(nums[pos]);
        dfs(proposal, ans, pos+1, nums);
        proposal.pop_back();
        dfs(proposal, ans, pos+1, nums);
    }
};
// @lc code=end

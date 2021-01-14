/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (54.07%)
 * Likes:    3526
 * Dislikes: 109
 * Total Accepted:    516.7K
 * Total Submissions: 941K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()) return {};

        vector<int> proposal;
        vector<vector<int>> solutions;
        DFS(0, proposal, solutions, candidates, target);

        return solutions;
    }

    void DFS(int pos, vector<int> &proposal, vector<vector<int>> &solutions, const vector<int> &candidates, int target){
        if (!target) {
            solutions.push_back(proposal);
            return;
        }else if (target<0 || pos == candidates.size()) {
            return;
        }
        proposal.push_back(candidates[pos]);
        DFS(pos, proposal, solutions, candidates, target-candidates[pos]);
        proposal.pop_back();

        DFS(pos+1, proposal, solutions, candidates, target);
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (52.78%)
 * Likes:    1353
 * Dislikes: 66
 * Total Accepted:    280.4K
 * Total Submissions: 522.7K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */

// @lc code=start
// 8ms
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> proposal(k, 0);

        dfs(proposal, ans, n, k, 0);
        return ans;
    }

    void dfs(vector<int> &proposal, vector<vector<int>> &ans, 
            const int n, const int k, const int pos) {
        if (pos == k) {
            ans.push_back(proposal);
            return;
        }

        int start = pos == 0 ? 1 : proposal[pos-1]+1;
        for (int i=start; i<=(n - (k-pos-1)); ++i) {
            proposal[pos] = i;
            dfs(proposal, ans, n, k, pos+1);
        }
    }
};
// @lc code=end

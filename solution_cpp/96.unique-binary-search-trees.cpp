/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (50.20%)
 * Likes:    3027
 * Dislikes: 109
 * Total Accepted:    273.5K
 * Total Submissions: 537K
 * Testcase Example:  '3'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        if (n<=1) return n;

        vector<size_t> dps(n+1, 0);
        dps[0] = 1;
        dps[1] = 1;
        for (int i=2; i<n+1; ++i){
            for (int j=0; j<i; ++j){
                dps[i] += dps[j] * dps[i-1-j];
            }
        }
        return dps[n];
    }
};
// @lc code=end

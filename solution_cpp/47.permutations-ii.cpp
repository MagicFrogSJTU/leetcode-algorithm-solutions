/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (44.81%)
 * Likes:    1791
 * Dislikes: 60
 * Total Accepted:    339.3K
 * Total Submissions: 746.1K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
#include <iostream>
#include <climits>
#include <map>
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
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        vector<int> proposal(nums.size());
        dfs(0, proposal, nums, visited, res);
        return res;
    }

    void dfs(int pos, vector<int> &proposal, 
                   const vector<int> &nums, 
                   vector<bool> &visited,
                   vector<vector<int>> &res) {
        int n = nums.size();
        if (pos == n) {
            res.push_back(proposal);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (visited[i] || (i>0 && nums[i]==nums[i-1]) && !visited[i-1]) continue;
            proposal[pos] = nums[i];
            visited[i] = true;
            dfs(pos+1, proposal, nums, visited, res);
            visited[i] = false;
        }
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    //vector<int> nums = {1,1,2,2,3};
    vector<int> nums = {1,1,2};
    auto results = Solution().permuteUnique(nums);
    for (auto vec : results){
        for(int i: vec) cout << i << " ";
        cout << endl;
    }
    return 0;
}

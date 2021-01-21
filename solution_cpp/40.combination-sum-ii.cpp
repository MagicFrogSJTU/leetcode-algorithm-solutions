/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (49.54%)
 * Likes:    2370
 * Dislikes: 84
 * Total Accepted:    377.6K
 * Total Submissions: 758.2K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note: The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output: 
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output: 
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
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
// 12ms
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int, int> counter;
        for (int i : candidates){
            ++counter[i];
        }
        vector<vector<int>> solutions;
        vector<int> proposal;
        func(counter.begin(), counter.end(), proposal, target, solutions);

        return solutions;
    }

    void func(map<int, int>::iterator iter, const map<int,int>::iterator &end, vector<int> &proposal, int target, vector<vector<int>> &solutions){
        if (!target){
            solutions.push_back(proposal);
            return;
        }
        if (iter == end || target < 0) return;

        int value=iter->first, count=iter->second;
        ++iter;
        func(iter, end, proposal, target, solutions);
        for (int i=0; i<count; ++i){
            proposal.push_back(value);
            target -= value;
            func(iter, end, proposal, target, solutions);
        }
        for (int i=0; i<count; ++i) proposal.pop_back();
        target += value*count;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    vector<int> candidates = {2,5,2,1,2};
    auto results = Solution().combinationSum2(candidates, 5);
    for (auto vec : results){
        for(int i: vec) cout << i << " ";
        cout << endl;
    }
    return 0;
}

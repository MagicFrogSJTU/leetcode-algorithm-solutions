/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (31.06%)
 * Likes:    3221
 * Dislikes: 767
 * Total Accepted:    320.5K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array, find the smallest missing positive
 * integer.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,0]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * Your algorithm should run in O(n) time and uses constant extra space.
 * 
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i=0; i<nums.size(); ++i){
            int j = i;
            while (nums[j]!=j+1 && nums[j]!=-1){
                if (nums[j]<=0 || nums[j]>nums.size()) nums[j]=-1;
                else {
                    int k=nums[j]-1;
                    if (nums[k]==nums[j]) nums[j]=-1;
                    else {
                        swap(nums[j], nums[k]);
                    }
                }
            }
        }
        for (int i=0; i<nums.size(); ++i){
            if (nums[i] == -1) return i+1;
        }
        return nums.size()+1;
        
    }
};
// @lc code=end

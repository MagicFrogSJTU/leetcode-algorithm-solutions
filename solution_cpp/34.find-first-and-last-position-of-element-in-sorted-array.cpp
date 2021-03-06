/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (35.36%)
 * Likes:    3264
 * Dislikes: 143
 * Total Accepted:    486.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = lower_bound(nums, target);
        int right = lower_bound(nums, target+1)-1;
        if (left==nums.size() || nums[left] != target) return {-1, -1};
        return {left, right};
        
    }
    int lower_bound(const vector<int> &nums, int target) {
        int left=0, right=nums.size();
        while (left<right){
            int mid = (left+right)/2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
// @lc code=end

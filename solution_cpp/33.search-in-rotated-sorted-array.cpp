/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.72%)
 * Likes:    4695
 * Dislikes: 442
 * Total Accepted:    701.4K
 * Total Submissions: 2M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
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
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        return func(0, nums.size()-1, nums, target);
    }

    int func(int left, int right, const vector<int> &nums, int target){
        if (left>right) return -1;
        int mid = (left+right)/2;
        if (nums[mid] == target) return mid;
        if (nums[mid]>=nums[left]){
            if (nums[left]<=target && target<nums[mid]){
                return func(left, mid-1, nums, target);
            }else return func(mid+1, right, nums, target);
        }else{
            if (nums[mid]<target && target<=nums[right]){
                return func(mid+1, right, nums, target);
            }else return func(left, mid-1, nums, target);
        }
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << Solution().search(nums, 0) << endl;
    cout << Solution().search(nums, 3) << endl;
    nums = {1,3};
    cout << Solution().search(nums, 0) << endl;
    cout << Solution().search(nums, 3) << endl;
    return 0;
}

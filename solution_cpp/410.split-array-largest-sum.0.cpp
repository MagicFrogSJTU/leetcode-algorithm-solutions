/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 *
 * https://leetcode.com/problems/split-array-largest-sum/description/
 *
 * algorithms
 * Hard (45.77%)
 * Likes:    2273
 * Dislikes: 84
 * Total Accepted:    109.9K
 * Total Submissions: 238.9K
 * Testcase Example:  '[7,2,5,10,8]\n2'
 *
 * Given an array nums which consists of non-negative integers and an integer
 * m, you can split the array into m non-empty continuous subarrays.
 * 
 * Write an algorithm to minimize the largest sum among these m subarrays.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [7,2,5,10,8], m = 2
 * Output: 18
 * Explanation:
 * There are four ways to split nums into two subarrays.
 * The best way is to split it into [7,2,5] and [10,8],
 * where the largest sum among the two subarrays is only 18.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,4,5], m = 2
 * Output: 9
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,4,4], m = 3
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 10^6
 * 1 <= m <= min(50, nums.length)
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
    int splitArray(vector<int>& nums, int m) {
        if(nums.empty() || m==0) return 0;
        size_t left = 0, right = 0;
        for(size_t n : nums) {
            left = max(left, n); //highest number i.e the max it\'ll go incase of m==nums.size()
            right += n; //total sum i.e the max it can go incase of m==1
        }
        if(m == nums.size()) return left; //edge case
        if(m == 1) return right; //edge case
        while(left < right) {//modified binary search w/ search space b/w highestnum...totalsum
            size_t mid = (left + right) / 2;
            size_t curr_bagsize = 0, curr_m = 1;
            for(auto n : nums) {
                if(curr_bagsize + n > mid) { //bag m is full, try the next bag now
                    curr_m++; 
                    curr_bagsize = 0;
                }
                curr_bagsize += n;
            } 
            if(curr_m > m) //we need a bigger bag size if curr_m > m
                left = mid + 1;
            else //current bag size is sufficient enough, so check for smaller bag sizes
                right = mid;
        }
        return left;
    }
};

// @lc code=end
int main(int argc, char **argv)
{
    vector<int> vec = {7,2,5,10,8};
    cout << Solution().splitArray(vec, 2) << endl;
    vec = {1,4,4};
    cout << Solution().splitArray(vec, 3) << endl;
    return 0;
}

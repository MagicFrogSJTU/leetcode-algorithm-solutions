/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (32.48%)
 * Likes:    5782
 * Dislikes: 193
 * Total Accepted:    421.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int currentMax = nums[0];
        int currentMin = nums[0];
        int maxProduct = nums[0];

        for(size_t i = 1; i < nums.size(); ++i) {
            //calculate our new possibilities for this round
            int p1 = currentMax * nums[i];
            int p2 = currentMin * nums[i];
            //our currentMax will be either p1 or p2 or nums[i] whichever is bigger
            currentMax = max(nums[i], max(p1, p2));
            //our currentMin will be either p1 or p2 or nums[i] whichever is smaller
            currentMin = min(nums[i], min(p1, p2));
            //our maxProduct will be our currentMax or our maxProduct, whichever is bigger.
            maxProduct = max(currentMax, maxProduct);
        }
        return maxProduct;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    vector<int> inputs = {-2, 0, -1};
    cout << Solution().maxProduct(inputs) << endl;
    inputs = {2, 3, -2, 4};
    cout << Solution().maxProduct(inputs) << endl;
    inputs = {-2};
    cout << Solution().maxProduct(inputs) << endl;
    inputs = {3,-1,4};
    cout << Solution().maxProduct(inputs) << endl;
    return 1;
}

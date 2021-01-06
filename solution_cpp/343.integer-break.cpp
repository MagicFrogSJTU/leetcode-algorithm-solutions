/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (50.90%)
 * Likes:    1352
 * Dislikes: 242
 * Total Accepted:    121.4K
 * Total Submissions: 238.2K
 * Testcase Example:  '2'
 *
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 * 
 * 
 */
#include <iostream>
#include <climits>
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
    static vector<int> dps;

    int integerBreak(int n) {
        if (dps[n] == -1){
            if (n==1) {
                dps[n]=1;
            }else{
                int result = -1;
                for (int a=1; a<=n/2; ++a){
                    result = max(result, a*max(n-a, integerBreak(n-a)));
                }
                dps[n] = result;
            }
        }
        return dps[n];
    }
};
vector<int> Solution::dps = vector<int>(59, -1);
// @lc code=end
int main(int argc, char **argv)
{
    cout << Solution().integerBreak(10) << endl;
    return 0;
}

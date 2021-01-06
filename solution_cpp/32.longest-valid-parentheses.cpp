/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (27.99%)
 * Likes:    4184
 * Dislikes: 156
 * Total Accepted:    320.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = ""
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 3 * 10^4
 * s[i] is '(', or ')'.
 * 
 * 
 */
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dps(s.size()+1, 0);
        int count = 0;
        for (int i=1; i<=s.size(); ++i)
        {
            if (s[i-1] == '(') ++count;
            else if (count > 0)
            {
                --count;
                if (s[i-2] == ')') dps[i] = dps[i-1] + 2;
                else dps[i] = 2;
                dps[i] += dps[i-dps[i]];
            }
        }
        return *max_element(dps.begin(), dps.end());
        
    }
};
// @lc code=end
//
int main(int argc, char **argv)
{
    cout << Solution().longestValidParentheses("(()") << endl;
    cout << Solution().longestValidParentheses(")()())") << endl;
    return 1;
}

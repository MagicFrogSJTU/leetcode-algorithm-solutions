/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (42.91%)
 * Likes:    1657
 * Dislikes: 267
 * Total Accepted:    435.8K
 * Total Submissions: 998.6K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 * 
 * Constraints:
 * 
 * 
 * Each string consists only of '0' or '1' characters.
 * 1 <= a.length, b.length <= 10^4
 * Each string is either "0" or doesn't contain any leading zero.
 * 
 * 
 */

// @lc code=start
// 0ms
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i=a.size()-1;
        int j=b.size()-1;
        string ans;
        while (i>=0 || j>=0 || carry){
            if (i>=0) carry += a[i--]-'0';
            if (j>=0) carry += b[j--]-'0';
            ans.push_back(carry%2 + '0');
            carry /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

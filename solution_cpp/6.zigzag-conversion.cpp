/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (35.19%)
 * Likes:    1587
 * Dislikes: 4428
 * Total Accepted:    443.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 *
 * string convert(string s, int numRows);
 *
 * Example 1:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 *
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        string result = s;
        int cycle = 2*numRows-2;
        size_t count = -1;
        for (int i=0; i<numRows; ++i){
            if (i==0 || i==numRows-1){
                for (int j=i; j<s.size(); j+=cycle)
                    result[++count] = s[j];
            }else{
                for (int j=i; j<s.size(); j+=cycle){
                    result[++count] = s[j];
                    int j2 = (j-i)+cycle-i;
                    if (j2 < s.size()) result[++count] = s[j2];
                }
            }
        }
        return result;
    }
};
// @lc code=end

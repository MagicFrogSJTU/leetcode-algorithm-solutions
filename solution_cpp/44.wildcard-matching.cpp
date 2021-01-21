/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (24.21%)
 * Likes:    1831
 * Dislikes: 101
 * Total Accepted:    237.1K
 * Total Submissions: 972K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement wildcard pattern
 * matching with support for '?' and '*'.
 * 
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like ? or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "cb"
 * p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not
 * match 'b'.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "adceb"
 * p = "*a*b"
 * Output: true
 * Explanation: The first '*' matches the empty sequence, while the second '*'
 * matches the substring "dce".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "acdcb"
 * p = "a*c?b"
 * Output: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        if (!p.size()) return !s.size();

        vector<vector<char>> dps(p.size()+1, vector<char>(s.size()+1, false));
        dps[0][0] = true;
        for (int i=1; i<=p.size(); ++i)
        {
            if (p[i-1] == '*') 
                dps[i][0] = dps[i-1][0];
            for (int j=1; j<=s.size(); ++j)
            {
                if (p[i-1] == '*')
                    dps[i][j] = dps[i-1][j] || dps[i][j-1];
                else if (p[i-1] == '?')
                    dps[i][j] = dps[i-1][j-1];
                else
                    dps[i][j] = dps[i-1][j-1] && p[i-1] == s[j-1];
            }
        }
        return dps[p.size()][s.size()];
    }
};
// @lc code=end

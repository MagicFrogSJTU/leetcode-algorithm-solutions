/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.97%)
 * Total Accepted:    900.7K
 * Total Submissions: 3.1M
 * Testcase Example:  '"babad"'
 *
 * <p>Given a string <strong>s</strong>, find the longest palindromic substring
 * in <strong>s</strong>. You may assume that the maximum length of
 * <strong>s</strong> is 1000.</p>
 *
 * <p><strong>Example 1:</strong></p>
 *
 * <pre>
 * <strong>Input:</strong> &quot;babad&quot;
 * <strong>Output:</strong> &quot;bab&quot;
 * <strong>Note:</strong> &quot;aba&quot; is also a valid answer.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre>
 * <strong>Input:</strong> &quot;cbbd&quot;
 * <strong>Output:</strong> &quot;bb&quot;
 * </pre>
 *
 */
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) return "";

        int i(0), max_len(0), max_x;
        while (i<s.size())
        {
            int x(i-1), y(i+1);
            while (y<s.size() && s[y]==s[y-1])
                ++y;
            // Forward.
            i = y;
            while (x>=0 && y<s.size())
            {
                if (s[x] != s[y])
                    break;
                else
                    --x, ++y;
            }
            if ((y-x-1) > max_len){
                max_x = x+1;
                max_len=y-max_x;
            }
        }
        return s.substr(max_x, max_len);
    }
};

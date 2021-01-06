/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (34.25%)
 * Likes:    1602
 * Dislikes: 1914
 * Total Accepted:    674.5K
 * Total Submissions: 2M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;


// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (!needle.size()) return 0;

        vector<int> jumper(needle.size(), 0);
        for (int i=1, j=0; i<needle.size();)
        {
            if (needle[i] == needle[j]) jumper[i++] = ++j;
            else if (j) j = jumper[j-1];
            else ++i;
        }

        for (int i=0, j=0; i<haystack.size();)
        {
            if (haystack[i] == needle[j]){
                ++i; ++j;
                if (j == needle.size()) return i - j;
            }
            else if (j) j = jumper[j-1];
            else ++i;
        }
        return -1;
    }
};
// @lc code=end
//
int main(int argc, char **argv)
{
    cout << Solution().strStr("aaaaa", "bba") << endl;
    cout << Solution().strStr("hello", "ll") << endl;
    return 1;
}

/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 *
 * https://leetcode.com/problems/scramble-string/description/
 *
 * algorithms
 * Hard (33.03%)
 * Likes:    467
 * Dislikes: 677
 * Total Accepted:    107K
 * Total Submissions: 321.3K
 * Testcase Example:  '"great"\n"rgeat"'
 *
 * Given a string s1, we may represent it as a binary tree by partitioning it
 * to two non-empty substrings recursively.
 * 
 * Below is one possible representation of s1 = "great":
 * 
 * 
 * ⁠   great
 * ⁠  /    \
 * ⁠ gr    eat
 * ⁠/ \    /  \
 * g   r  e   at
 * ⁠          / \
 * ⁠         a   t
 * 
 * 
 * To scramble the string, we may choose any non-leaf node and swap its two
 * children.
 * 
 * For example, if we choose the node "gr" and swap its two children, it
 * produces a scrambled string "rgeat".
 * 
 * 
 * ⁠   rgeat
 * ⁠  /    \
 * ⁠ rg    eat
 * ⁠/ \    /  \
 * r   g  e   at
 * ⁠          / \
 * ⁠         a   t
 * 
 * 
 * We say that "rgeat" is a scrambled string of "great".
 * 
 * Similarly, if we continue to swap the children of nodes "eat" and "at", it
 * produces a scrambled string "rgtae".
 * 
 * 
 * ⁠   rgtae
 * ⁠  /    \
 * ⁠ rg    tae
 * ⁠/ \    /  \
 * r   g  ta  e
 * ⁠      / \
 * ⁠     t   a
 * 
 * 
 * We say that "rgtae" is a scrambled string of "great".
 * 
 * Given two strings s1 and s2 of the same length, determine if s2 is a
 * scrambled string of s1.
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "great", s2 = "rgeat"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "abcde", s2 = "caebd"
 * Output: false
 * 
 */
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isScramble(string s1, string s2) {
        unordered_map<string, unordered_map<string, bool>> mapping;
        return run(s1, s2, mapping);
    }

    bool run(const string &s1, const string &s2, unordered_map<string, unordered_map<string, bool>> &mapping)
    {
        if (s1.size()==1) return s1==s2;
        if (mapping.find(s1) != mapping.end()){
            if (mapping[s1].find(s2) != mapping[s1].end()){
                return mapping[s1][s2];
            }
        }

        for (int i=1; i<s1.size(); ++i){
            if ((run(s1.substr(0, i), s2.substr(0, i), mapping) && run(s1.substr(i, s1.size()-i), s2.substr(i, s1.size()-i), mapping)) ||
                    (run(s1.substr(0, i), s2.substr(s1.size()-i, i), mapping) && run(s1.substr(i, s1.size()-i), s2.substr(0, s1.size()-i), mapping))){
                mapping[s1][s2] = true;
                mapping[s2][s1] = true;
                return true;
            }
        }
        mapping[s1][s2] = false;
        mapping[s2][s1] = false;
        return false;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    cout << Solution().isScramble("great", "rgeat") << endl;
    cout << Solution().isScramble("abcde", "caebd") << endl;
    return 1;
}

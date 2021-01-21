/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (35.18%)
 * Likes:    3244
 * Dislikes: 2015
 * Total Accepted:    864.7K
 * Total Submissions: 2.4M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 *
 * Example 1:
 *
 *
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 *
 *
 * Example 2:
 *
 *
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] consists of only lower-case English letters.
 *
 *
 */
#include <string>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs) {
        if (strs.size()==0) return "";
        size_t min_size=INT_MAX;
        for (auto &str: strs)
            min_size = min(min_size, str.size());
        for (int i=0;i<min_size;++i){
            for (auto &str: strs){
                if (str[i] != strs[0][i]){
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0].substr(0, min_size);

    }
};
// @lc code=end
//
//
int main(int args, char **argv){
    cout << Solution().longestCommonPrefix({"fuck", "fuckyou"}) << endl;
    return 1;
}

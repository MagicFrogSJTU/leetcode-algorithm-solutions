/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (23.90%)
 * Likes:    2480
 * Dislikes: 2682
 * Total Accepted:    383.3K
 * Total Submissions: 1.6M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if (!s.size()) return 0;
        int n1 = s[0]!='0';
        int n2=n1;

        for (int i=1; i<s.size(); ++i){
            int n3;
            n3 = s[i] == '0' ? 0 : n2;
            if (s[i-1] != '0'){
                int num = (s[i-1]-'0')*10 + s[i]-'0';
                if (num == 0) return 0;
                else if (num <= 26) {
                    n3 += n1;
                }
            }
            n1 = n2;
            n2 = n3;
        }
        return n2;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    cout << Solution().numDecodings("0") << endl;
    cout << Solution().numDecodings("10") << endl;
    cout << Solution().numDecodings("12") << endl;
    cout << Solution().numDecodings("226") << endl;
    cout << Solution().numDecodings("2101") << endl;
    cout << Solution().numDecodings("01") << endl;
    return 1;
}

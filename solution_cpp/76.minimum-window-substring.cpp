/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (33.72%)
 * Likes:    4214
 * Dislikes: 299
 * Total Accepted:    382.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */
#include <iostream>
#include <climits>
#include <map>
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
    string minWindow(string s, string t) {
        unordered_map<char, int> window, target;
        int letterCounter(t.size());  // Key to avoid comparing two map.
        
        for (char c : t) target[c]++;

        int minLen(INT_MAX), minHead;
        for (int head=0, tail=0; tail<s.size(); ++tail){
            char c = s[tail];
            if (target.find(c) != target.end()) {
                if (window[c] < target[c]) --letterCounter;
                ++window[c];

                while (true) {
                    c = s[head];
                    if (target.find(c) == target.end()) ++head;
                    else if (window[c] > target[c]) {++head; window[c]--;}
                    else break;
                }

                if (!letterCounter) {
                    int length = tail-head+1;
                    if (length < minLen) {
                        minLen = length;
                        minHead = head;
                    }
                }
            }
        }
        if (minLen == INT_MAX) return "";
        else return s.substr(minHead, minLen);
        
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    cout << "result: " << Solution().minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}

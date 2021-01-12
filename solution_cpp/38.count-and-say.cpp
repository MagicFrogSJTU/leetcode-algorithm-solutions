/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (43.54%)
 * Likes:    1231
 * Dislikes: 9255
 * Total Accepted:    387.8K
 * Total Submissions: 881.2K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
 * count-and-say sequence. You can do so recursively, in other words from the
 * previous member read off the digits, counting the number of digits in groups
 * of the same digit.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * Explanation: This is the base case.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * Explanation: For n = 3 the term was "21" in which we have two groups "2" and
 * "1", "2" can be read as "12" which means frequency = 1 and value = 2, the
 * same way "1" is read as "11", so the answer is the concatenation of "12" and
 * "11" which is "1211".
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
    static vector<string> dps;
    string countAndSay(int n) {
        if (!dps[n].size()) {
            if (n==1) dps[1] = "1";
            else {
                string result = countAndSay(n-1);
                string next="";
                char last=result[0];
                int count=1;
                for (int i=1; i<result.size(); ++i){
                    if (result[i] == last) ++count;
                    else{
                        next += to_string(count);
                        next.push_back(last);
                        last = result[i];
                        count = 1;
                    }
                }
                next += to_string(count);
                next.push_back(last);
                dps[n] = next;
            }
        }
        return dps[n];
    }
};
vector<string> Solution::dps = vector<string>(31, "");
// @lc code=end
int main(int argc, char **argv)
{
    cout << Solution().countAndSay(2) << endl;
    cout << Solution().countAndSay(3) << endl;
    cout << Solution().countAndSay(4) << endl;
    cout << Solution().countAndSay(5) << endl;
    cout << Solution().countAndSay(10) << endl;
    return 0;
}

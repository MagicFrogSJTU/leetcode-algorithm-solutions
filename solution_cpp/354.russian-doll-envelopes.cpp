/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 *
 * https://leetcode.com/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (35.90%)
 * Likes:    1480
 * Dislikes: 48
 * Total Accepted:    79.2K
 * Total Submissions: 219.7K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * You have a number of envelopes with widths and heights given as a pair of
 * integers (w, h). One envelope can fit into another if and only if both the
 * width and height of one envelope is greater than the width and height of the
 * other envelope.
 * 
 * What is the maximum number of envelopes can you Russian doll? (put one
 * inside other)
 * 
 * Note:
 * Rotation is not allowed.
 * 
 * Example:
 * 
 * 
 * 
 * Input: [[5,4],[6,4],[6,7],[2,3]]
 * Output: 3 
 * Explanation: The maximum number of envelopes you can Russian doll is 3
 * ([2,3] => [5,4] => [6,7]).
 * 
 * 
 * 
 */
#include <iostream>
#include <climits>
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
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Tricky here.
        auto Cmp = [](const vector<int> &a, const vector<int> &b) { 
            if(a[0] < b[0]) return true;
            if(a[0] == b[0] && a[1] > b[1]) return true;
            return false;
        };
        sort(envelopes.begin(), envelopes.end(), Cmp);
        
        auto Cmp2 = [](const vector<int> &a, const vector<int> &b) { 
            return a[1] < b[1];
        };
        vector<vector<int>> res;
        for(int i=0; i<envelopes.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), envelopes[i], Cmp2);
            if(it == res.end()) res.push_back(envelopes[i]);
            else *it = envelopes[i];
        }
        return res.size();
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
    cout << Solution().maxEnvelopes(envelopes) << endl;
    return 0;
}

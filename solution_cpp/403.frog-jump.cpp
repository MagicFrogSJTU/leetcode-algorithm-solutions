/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 *
 * https://leetcode.com/problems/frog-jump/description/
 *
 * algorithms
 * Hard (40.81%)
 * Likes:    1368
 * Dislikes: 124
 * Total Accepted:    109.2K
 * Total Submissions: 266K
 * Testcase Example:  '[0,1,3,5,6,8,12,17]'
 *
 * A frog is crossing a river. The river is divided into some number of units,
 * and at each unit, there may or may not exist a stone. The frog can jump on a
 * stone, but it must not jump into the water.
 * 
 * Given a list of stones' positions (in units) in sorted ascending order,
 * determine if the frog can cross the river by landing on the last stone.
 * Initially, the frog is on the first stone and assumes the first jump must be
 * 1 unit.
 * 
 * If the frog's last jump was k units, its next jump must be either k - 1, k,
 * or k + 1 units. The frog can only jump in the forward direction.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: stones = [0,1,3,5,6,8,12,17]
 * Output: true
 * Explanation: The frog can jump to the last stone by jumping 1 unit to the
 * 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone,
 * then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the
 * 8th stone.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: stones = [0,1,2,3,4,8,9,11]
 * Output: false
 * Explanation: There is no way to jump to the last stone as the gap between
 * the 5th and 6th stone is too large.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= stones.length <= 2000
 * 0 <= stones[i] <= 2^31 - 1
 * stones[i] == 0
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
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canCross(vector<int>& stones) {
        vector<map<char, bool>> dps(stones.size());
        if (stones[1] != 1) return false;
        return func(1, 1, stones, dps);
    }

    bool func(int pos, int last_k, const vector<int> &stones, vector<map<char, bool>> &dps) {
        auto &dp = dps[pos];
        if (dp.find(last_k) == dp.end()){
            if (pos == stones.size()-1) {
                dp[last_k] = true;
            }else {
                dp[last_k] = false;
                for (int i=last_k-1; i<last_k+2; ++i){
                    if (i <= 0) continue;
                    int next_stone = stones[pos] + i;
                    auto hit = lower_bound(stones.begin(), stones.end(), next_stone);
                    if (hit != stones.end() && *hit == next_stone){
                        if (func(hit-stones.begin(), i, stones, dps)){
                            dp[last_k] = true;
                            break;
                        }
                    }
                }
            }
            
        }
        return dp[last_k];
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    vector<int> stones = {0,1,2,3,4,8,9,11};
    cout << Solution().canCross(stones) << endl;
    stones = {0,1,3,5,6,8,12,17};
    cout << Solution().canCross(stones) << endl;

    return 0;
}

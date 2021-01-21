/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (47.35%)
 * Likes:    6592
 * Dislikes: 115
 * Total Accepted:    489.3K
 * Total Submissions: 1M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
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
// naive solution: 8ms.
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n<3) return 0;

        vector<int> left_most(n), right_most(n);
        left_most[0]=height[0];
        for (int i=1; i<n; ++i){
            left_most[i] = max(left_most[i-1], height[i]);
        }
        right_most[n-1]=height[n-1];
        for (int i=n-2; i>=0; --i){
            right_most[i] = max(right_most[i+1], height[i]);
        }

        int water(0);
        for (int i=1; i<n-1; ++i) {
            water += max(min(left_most[i-1], right_most[i+1]) - height[i], 0);
        }
        return water;
    }
};
// @lc code=end
/* Interesting.
int trap(vector<int>& height) {
    int l = 0, r = height.size()-1, level = 0, water = 0;
    while (l < r) {
        int lower = height[height[l] < height[r] ? l++ : r--];
        level = max(level, lower);
        water += level - lower;
    }
    return water;
}
*/

int main(int argc, char **argv)
{
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << Solution().trap(v) << endl;
    return 0;
}

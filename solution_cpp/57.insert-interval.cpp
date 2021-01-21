/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (32.81%)
 * Likes:    1386
 * Dislikes: 155
 * Total Accepted:    230.8K
 * Total Submissions: 702.5K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {newInterval};
        auto left_bound = upper_bound(intervals.begin(), intervals.end(), newInterval, [](const vector<int> &a, const vector<int> &b){return a[0]<b[0];});

        vector<vector<int>> result;
        for (auto iter=intervals.begin(); iter!=left_bound; ++iter) result.push_back(*iter);
        if (result.empty()){
            result.push_back(newInterval);
        }else{
            auto &item = result.back();
            if (item[1] >= newInterval[0]){
                if (item[1] < newInterval[1]) item[1] = newInterval[1];
            }else{
                result.push_back(newInterval);
            }
        }
        if (left_bound != intervals.end()){
            vector<int> target = result.back();
            target[0] = target[1];
            auto right_bound = upper_bound(left_bound, intervals.end(), target, [](const vector<int> &a, const vector<int> &b){return a[0]<b[0];});
            if (right_bound != left_bound){
                auto &item = result.back();
                auto last = *(right_bound-1);
                if (item[1] < last[1]) item[1] = last[1];
            }
            if (right_bound != intervals.end()){
                for (auto iter=right_bound; iter!=intervals.end(); ++iter) result.push_back(*iter);
            } 
        }
        return result;

        
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval={2,5};
    auto r = Solution().insert(intervals, newInterval);
    for (auto &i : r)
        for (auto &j : i)
            cout << j << " ";
    cout << endl;

    intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    newInterval = {4,8};
    r = Solution().insert(intervals, newInterval);
    for (auto &i : r)
        for (auto &j : i)
            cout << j << " ";
    cout << endl;

    intervals = {{1,5}};
    newInterval = {0,3};
    r = Solution().insert(intervals, newInterval);
    for (auto &i : r)
        for (auto &j : i)
            cout << j << " ";
    cout << endl;
    return 0;
}

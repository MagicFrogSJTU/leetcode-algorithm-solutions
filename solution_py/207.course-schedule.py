#
# @lc app=leetcode id=207 lang=python3
#
# [207] Course Schedule
#
# https://leetcode.com/problems/course-schedule/description/
#
# algorithms
# Medium (42.53%)
# Likes:    3819
# Dislikes: 175
# Total Accepted:    418.1K
# Total Submissions: 977.6K
# Testcase Example:  '2\n[[1,0]]'
#
# There are a total of numCourses courses you have to take, labeled from 0 to
# numCourses-1.
# 
# Some courses may have prerequisites, for example to take course 0 you have to
# first take course 1, which is expressed as a pair: [0,1]
# 
# Given the total number of courses and a list of prerequisite pairs, is it
# possible for you to finish all courses?
# 
# 
# Example 1:
# 
# 
# Input: numCourses = 2, prerequisites = [[1,0]]
# Output: true
# Explanation: There are a total of 2 courses to take. 
# To take course 1 you should have finished course 0. So it is possible.
# 
# 
# Example 2:
# 
# 
# Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
# Output: false
# Explanation: There are a total of 2 courses to take. 
# To take course 1 you should have finished course 0, and to take course 0 you
# should
# also have finished course 1. So it is impossible.
# 
# 
# 
# Constraints:
# 
# 
# The input prerequisites is a graph represented by a list of edges, not
# adjacency matrices. Read more about how a graph is represented.
# You may assume that there are no duplicate edges in the input
# prerequisites.
# 1 <= numCourses <= 10^5
# 
# 
#

# @lc code=start
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        depends = {}
        allows = {}
        for i in range(numCourses):
            depends[i] = set()
            allows[i] = set()
        for t, f in prerequisites:
            depends[t].add(f)
            allows[f].add(t)
        
        while depends:
            has_removed = False 
            for t in list(depends.keys()):
                froms = depends[t]
                if len(froms) == 0:
                    has_removed = True
                    depends.pop(t)
                    for t_reduced in allows.pop(t):
                        depends[t_reduced].remove(t)
            if not has_removed and depends:
                return False
        return True
        
# @lc code=end


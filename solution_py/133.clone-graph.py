#
# @lc app=leetcode id=133 lang=python3
#
# [133] Clone Graph
#
# https://leetcode.com/problems/clone-graph/description/
#
# algorithms
# Medium (33.68%)
# Likes:    1639
# Dislikes: 1328
# Total Accepted:    328K
# Total Submissions: 973K
# Testcase Example:  '[[2,4],[1,3],[2,4],[1,3]]'
#
# Given a reference of a node in a connected undirected graph.
# 
# Return a deep copy (clone) of the graph.
# 
# Each node in the graph contains a val (int) and a list (List[Node]) of its
# neighbors.
# 
# 
# class Node {
# ⁠   public int val;
# ⁠   public List<Node> neighbors;
# }
# 
# 
# 
# 
# Test case format:
# 
# For simplicity sake, each node's value is the same as the node's index
# (1-indexed). For example, the first node with val = 1, the second node with
# val = 2, and so on. The graph is represented in the test case using an
# adjacency list.
# 
# Adjacency list is a collection of unordered lists used to represent a finite
# graph. Each list describes the set of neighbors of a node in the graph.
# 
# The given node will always be the first node with val = 1. You must return
# the copy of the given node as a reference to the cloned graph.
# 
# 
# Example 1:
# 
# 
# Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
# Output: [[2,4],[1,3],[2,4],[1,3]]
# Explanation: There are 4 nodes in the graph.
# 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
# 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
# 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
# 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val =
# 3).
# 
# 
# Example 2:
# 
# 
# Input: adjList = [[]]
# Output: [[]]
# Explanation: Note that the input contains one empty list. The graph consists
# of only one node with val = 1 and it does not have any neighbors.
# 
# 
# Example 3:
# 
# 
# Input: adjList = []
# Output: []
# Explanation: This an empty graph, it does not have any nodes.
# 
# 
# Example 4:
# 
# 
# Input: adjList = [[2],[1]]
# Output: [[2],[1]]
# 
# 
# 
# Constraints:
# 
# 
# 1 <= Node.val <= 100
# Node.val is unique for each node.
# Number of Nodes will not exceed 100.
# There is no repeated edges and no self-loops in the graph.
# The Graph is connected and all nodes can be visited starting from the given
# node.
# 
# 
#

"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""
# @lc code=start

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None

        graph_dict = {}
        def func(n):
            v = n.val
            if v in graph_dict:
                return graph_dict[v]
            graph_dict[v] = Node(v)
            graph_dict[v].neighbors = [func(nei) for nei in n.neighbors]
            return graph_dict[v]
        return func(node)
            




# @lc code=end



class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None:
            return node
        graph_dict = {}
        stack = [node]
        while stack:
            n = stack.pop()
            new_n = graph_dict.setdefault(n.val, Node(n.val))
            for neighbor in n.neighbors:
                if neighbor.val not in graph_dict:
                    stack.append(neighbor)
                    graph_dict[neighbor.val] = Node(neighbor.val)
            new_n.neighbors = [graph_dict[i.val] for  i  in n.neighbors]
        return graph_dict[node.val]

        


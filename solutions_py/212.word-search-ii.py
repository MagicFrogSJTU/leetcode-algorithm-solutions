#
# @lc app=leetcode id=212 lang=python3
#
# [212] Word Search II
#
# https://leetcode.com/problems/word-search-ii/description/
#
# algorithms
# Hard (33.30%)
# Likes:    2533
# Dislikes: 110
# Total Accepted:    213.9K
# Total Submissions: 619.9K
# Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
#
# Given a 2D board and a list of words from the dictionary, find all words in
# the board.
#
# Each word must be constructed from letters of sequentially adjacent cell,
# where "adjacent" cells are those horizontally or vertically neighboring. The
# same letter cell may not be used more than once in a word.
#
#
#
# Example:
#
#
# Input:
# board = [
# ⁠ ['o','a','a','n'],
# ⁠ ['e','t','a','e'],
# ⁠ ['i','h','k','r'],
# ⁠ ['i','f','l','v']
# ]
# words = ["oath","pea","eat","rain"]
#
# Output: ["eat","oath"]
#
#
#
#
# Note:
#
#
# All inputs are consist of lowercase letters a-z.
# The values of words are distinct.
#
#
#

# @lc code=start
class Solution:
  def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
    if not len(board) or not len(board[0]):
      return []

    class Node:
      def __init__(self):
        self.nodes = defaultdict(Node)
        self.count = 0
        self.is_end = False

    null_head = Node()
    for word in words:
      curr = null_head
      for s in word:
        curr = curr.nodes[s]
        curr.count += 1
      curr.is_end = True

    satisfied = []
    def search(node, i, j, prefix):
      if not node.count:
        return
      if node.is_end:
        satisfied.append(prefix)
        curr = null_head
        for s in prefix:
          curr = curr.nodes[s]
          curr.count -= 1
        curr.is_end = False
      board[i][j] = -1
      for iDiff, jDiff in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
        if not node.count:
          break
        iNext = i + iDiff
        jNext = j + jDiff
        if 0<=iNext<len(board) and 0<=jNext<len(board[0]):
          for s, node_next in node.nodes.items():
            if node_next.count and board[iNext][jNext] == s:
              search(node_next, iNext, jNext, prefix+s)
      board[i][j] = prefix[-1]

    if null_head.is_end:
      satisfied.append("")
    for i in range(len(board)):
      for j in range(len(board[0])):
        for s, node in null_head.nodes.items():
          if board[i][j] == s:
            search(node, i, j, s)

    return satisfied



# @lc code=end


#
# @lc app=leetcode id=127 lang=python3
#
# [127] Word Ladder
#
# https://leetcode.com/problems/word-ladder/description/
#
# algorithms
# Medium (28.87%)
# Likes:    2954
# Dislikes: 1131
# Total Accepted:    412.1K
# Total Submissions: 1.4M
# Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
#
# Given two words (beginWord and endWord), and a dictionary's word list, find
# the length of shortest transformation sequence from beginWord to endWord,
# such that:
# 
# 
# Only one letter can be changed at a time.
# Each transformed word must exist in the word list.
# 
# 
# Note:
# 
# 
# Return 0 if there is no such transformation sequence.
# All words have the same length.
# All words contain only lowercase alphabetic characters.
# You may assume no duplicates in the word list.
# You may assume beginWord and endWord are non-empty and are not the same.
# 
# 
# Example 1:
# 
# 
# Input:
# beginWord = "hit",
# endWord = "cog",
# wordList = ["hot","dot","dog","lot","log","cog"]
# 
# Output: 5
# 
# Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
# "dog" -> "cog",
# return its length 5.
# 
# 
# Example 2:
# 
# 
# Input:
# beginWord = "hit"
# endWord = "cog"
# wordList = ["hot","dot","dog","lot","log"]
# 
# Output: 0
# 
# Explanation: The endWord "cog" is not in wordList, therefore no possible
# transformation.
# 
# 
# 
# 
# 
#

# @lc code=start
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        def get_connections(words):
            connections = {}
            for word in words:
                for i in range(len(word)):
                    connections.setdefault(word[:i] + "_" + word[i+1:], []).append(word)
            pairs = {}
            for word in words:
                myset = set()
                for i in range(len(word)):
                    myset.update(connections[word[:i] + "_" + word[i+1:]])
                myset.discard(word)
                pairs[word] = myset
            return pairs
        
        pairs = get_connections(wordList + [beginWord])
            
        begins = [beginWord]
        visited = set()
        i = 1
        while True:
            i += 1
            nexts = []

            for word in begins:
                for linked in pairs[word]:
                    if linked not in visited:
                        if linked == endWord:
                            return i
                        visited.add(linked)
                        nexts.append(linked)
            if not len(nexts):
                break
            begins = nexts
        return 0




        
# @lc code=end


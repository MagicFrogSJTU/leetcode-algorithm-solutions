#
# @lc app=leetcode id=211 lang=python3
#
# [211] Add and Search Word - Data structure design
#
# https://leetcode.com/problems/add-and-search-word-data-structure-design/description/
#
# algorithms
# Medium (36.14%)
# Likes:    1772
# Dislikes: 89
# Total Accepted:    185.9K
# Total Submissions: 508.3K
# Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n' +
  '[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
#
# Design a data structure that supports the following two operations:
# 
# 
# void addWord(word)
# bool search(word)
# 
# 
# search(word) can search a literal word or a regular expression string
# containing only letters a-z or .. A . means it can represent any one letter.
# 
# Example:
# 
# 
# addWord("bad")
# addWord("dad")
# addWord("mad")
# search("pad") -> false
# search("bad") -> true
# search(".ad") -> true
# search("b..") -> true
# 
# 
# Note:
# You may assume that all words are consist of lowercase letters a-z.
# 
#

# @lc code=start
class Node:
    def __init__(self):
        self.nodes = defaultdict(Node)
        self.isend = False

class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.internal = Node()
        

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        curr = self.internal
        for s in word:
            curr = curr.nodes[s]
        curr.isend = True
            
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        stack = [self.internal]
        for s in word:
            if not len(stack):
                return False
            new_stack = []
            for curr in stack:
                if s == ".":
                    new_stack.extend(curr.nodes.values())
                elif s in curr.nodes:
                    new_stack.append(curr.nodes[s])
            stack = new_stack
        for node in stack:
            if node.isend:
                return True
        return False

        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
# @lc code=end


#!/usr/bin/env python
# This is a follow up of Shortest Word Distance. The only difference is now
# you are given the list of words and your method will be called repeatedly
# many times with different parameters. How would you optimize it?
# Design a class which receives a list of words in the constructor, and implements
# a method that takes two words word1 and word2 and return the shortest distance
# between these two words in the list.
# For example,
# Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
# Given word1 = "coding", word2 = "practice", return 3.
# Given word1 = "makes", word2 = "coding", return 1.
# Note:
# You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

class WordDistance(object):
    def __init__(self, words):
        """
        initialize your data structure here.
        :type words: List[str]
        """
        self.w_dict = {}
        for i, word in enumerate(words):
            self.w_dict[word] = self.w_dict.get(word, []) + [i] # append doesn't return new list

    def shortest(self, word1, word2):
        """
        Adds a word into the data structure.
        :type word1: str
        :type word2: str
        :rtype: int
        """
        return min([abs(i - j) for i in self.w_dict[word1] for j in self.w_dict[word2]])


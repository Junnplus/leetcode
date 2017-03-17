class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        s_dic = self.statistics(s)
        t_dic = self.statistics(t)
        return s_dic == t_dic

    def statistics(self, words):
        dic = {}
        for c in words:
            dic.setdefault(c, 0)
            dic[c] += 1
        return dic

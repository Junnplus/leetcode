class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        words = str.split()
        if len(words) != len(pattern):
            return False
        if len(set(words)) != len(set(pattern)):
            return False
        pattern_map = {}
        for i, p in enumerate(pattern):
            if p not in pattern_map:
                pattern_map[p] = words[i]
            else:
                if pattern_map[p] != words[i]:
                    return False
        return True


if __name__ == '__main__':
    assert Solution().wordPattern("abba", "dog cat cat dog") is True
    assert Solution().wordPattern("abba", "dog cat cat fish") is False
    assert Solution().wordPattern("abba", "dog dog dog dog") is False

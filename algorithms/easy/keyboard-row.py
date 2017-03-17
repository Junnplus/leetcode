class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        return filter(lambda w: not self.is_one_row(w), words)

    def is_one_row(self, word):
        KEYBOARD = (
            "qwertyuiop",
            "asdfghjkl",
            "zxcvbnm"
        )
        for k in KEYBOARD:
            if set(k) >= set(word.lower()):
                break
        else:
            return True
        return False


if __name__ == '__main__':
    inp = ["Hello", "Alaska", "Dad", "Peace"]
    oup = ["Alaska", "Dad"]
    assert Solution().findWords(inp) == oup
    inp = ["adsdf", "sfd"]
    oup = ["adsdf", "sfd"]
    assert Solution().findWords(inp) == oup
    inp = ["asdfghjkl", "qwertyuiop", "zxcvbnm"]
    oup = ["asdfghjkl", "qwertyuiop", "zxcvbnm"]
    assert Solution().findWords(inp) == oup

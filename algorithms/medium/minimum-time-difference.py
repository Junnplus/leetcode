class Solution(object):
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        from datetime import datetime
        times = map(lambda t: datetime.strptime(t, '%H:%M'), sorted(timePoints))
        tmin = None
        for i in range(len(times) - 1):
            t1 = (times[i + 1] - times[i]).seconds / 60
            t2 = (times[i] - times[i - 1]).seconds / 60
            t = min(t1, t2)
            if tmin is None:
                tmin = t
            elif t < tmin:
                tmin = t
        return tmin


if __name__ == '__main__':
    assert Solution().findMinDifference(["23:59", "00:00"]) == 1

class MinStack(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self._top = -1
        self._stack = []
        self.min_stack = []

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self._stack.append(x)
        _min = self.getMin()
        if _min is None or _min > x:
            self.min_stack.append(x)
        else:
            self.min_stack.append(_min)
        self._top += 1

    def pop(self):
        """
        :rtype: nothing
        """
        if self._top == -1:
            return
        self._stack.pop()
        self.min_stack.pop()
        self._top -= 1

    def top(self):
        """
        :rtype: int
        """
        return self._stack[self._top] if self._top >= 0 else None

    def getMin(self):
        """
        :rtype: int
        """
        return self.min_stack[self._top] if self._top >= 0 else None


if __name__ == '__main__':
    min_stack = MinStack()
    min_stack.push(-2)
    min_stack.push(0)
    min_stack.push(-3)
    assert min_stack.getMin() == -3
    min_stack.pop()
    assert min_stack.top() == 0
    assert min_stack.getMin() == -2


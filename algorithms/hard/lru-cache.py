class LinkNode(object):
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None


class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.curruent_capacity = 0
        self._dict = {}
        self.head = None
        self.tail = None

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key in self._dict:
            node = self._dict[key]
            self.swap_head(node)
            return node.val
        else:
            return -1

    def swap_head(self, node):
        if node is self.head:
            return node.val
        if node is self.tail:
            self.tail = self.tail.prev
            self.tail.next = None
            self.head.prev = node
            node.next = self.head
            self.head = node
            return node.val
        node.prev.next, node.next.prev = node.next, node.prev
        self.head.prev = node
        node.next = self.head
        self.head = node

    def pop_tail(self):
        if self.tail is None:
            return
        del self._dict[self.tail.key]
        if self.tail is self.head:
            self.tail = self.head = None
        else:
            self.tail = self.tail.prev
            self.tail.next = None
        self.curruent_capacity -= 1

    def put_head(self, key, value):
        if self.head is None:
            return
        node = LinkNode(key, value)
        self.head.prev = node
        node.next = self.head
        self.head = node
        self._dict[key] = node
        self.curruent_capacity += 1

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if self.capacity <= 0:
            return
        if self.curruent_capacity == 0:
            self._dict[key] = self.head = self.tail = LinkNode(key, value)
            self.curruent_capacity += 1
            return
        if key in self._dict:
            node = self._dict[key]
            node.val = value
            self.swap_head(node)
        else:
            if self.curruent_capacity == self.capacity:
                self.pop_tail()
                return self.put(key, value)
            self.put_head(key, value)


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)


if __name__ == '__main__':
    cache = LRUCache(2)
    cache.put(1, 1)
    cache.put(2, 2)
    assert cache.get(1) == 1
    cache.put(3, 3)
    assert cache.get(2) == -1
    cache.put(4, 4)
    assert cache.get(1) == -1
    assert cache.get(3) == 3
    assert cache.get(4) == 4

    cache = LRUCache(1)
    cache.put(2, 1)
    assert cache.get(2) == 1
    cache.put(3, 2)
    assert cache.get(2) == -1
    assert cache.get(3) == 2

    cache = LRUCache(2)
    cache.put(2, 1)
    cache.put(2, 2)
    assert cache.get(2) == 2
    cache.put(1, 1)
    cache.put(4, 1)
    assert cache.get(2) == -1

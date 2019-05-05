class LinkNode(object):
    def __init__(self, key, value, prev=None, next=None):
        self.key = key
        self.value = value
        self.next = next
        self.prev = prev
        if prev:
            prev.next = self
        if next:
            next.prev = self


class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.cap = capacity
        self._dict = {}
        self.head = None
        self.len = 0
        self.tail = None

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        node = self.get_node(key)
        return node and node.value or -1

    def get_node(self, key):
        if key not in self._dict:
            return
        node = self._dict[key]
        if self.head == node:
            return node
        if node.prev:
            node.prev.next = node.next
        if node.next:
            node.next.prev = node.prev
        else:
            self.tail = self.tail.prev
        node.prev = None
        node.next = self.head
        self.head.prev = node
        self.head = node
        return node

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        if self.cap <= 0:
            return
        node = self.get_node(key)
        if node:
            node.value = value
            return
        if self.len == self.cap:
            if self.tail:
                self._dict.pop(self.tail.key)
            self.tail = self.tail.prev
            if self.tail:
                self.tail.next = None
            self.len -= 1
        node = LinkNode(key, value, None, self.head)
        self.head = node
        if not self.tail:
            self.tail = node
        self._dict[key] = node
        self.len += 1
        

def main():
    cache = LRUCache(2)
    cache.put(1, 1)
    cache.put(2, 2)
    print(cache.get(1))
    cache.put(3, 3)
    print(cache.get(2))
    cache.put(4, 4)
    print(cache.get(1))
    print(cache.get(3))
    print(cache.get(4))


if __name__ == '__main__':
    main()

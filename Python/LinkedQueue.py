class Empty(Exception):
    pass

class LinkedQueue:

    class _Node:
        __slots__ = '_item', '_next'

        def __init__(self, item, next):
            self._item = item
            self._next = next

    def __init__(self):
        self._head = None
        self._tail = None
        self._size = 0

    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size == 0

    def enqueue(self, item):
        old_tail = self._tail
        self._tail = self._Node(item, None)
        if self.is_empty():
            self._head = self._tail
        else:
            old_tail._next = self._tail
        self._size += 1

    def dequeue(self):
        if self.is_empty():
            raise Empty('Queue is empty')

        item = self._head._item
        self._head = self._head._next
        self._size -= 1
        if self.is_empty():
            self._tail = None
        return item

    def first(self):
        if self.is_empty():
            raise Empty('Queue is empty')
        return self._head._item
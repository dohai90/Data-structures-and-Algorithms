class Empty(Exception):
    pass

class CircularQueue:

    class _Node:
        __slots__ = '_item', '_next'

        def __init__(self, item, next):
            self._item = item
            self._next = next

    def __init__(self):
        self._cursor = None
        self._size = 0

    def __len__(self):
        return self._size

    def is_empty(self):

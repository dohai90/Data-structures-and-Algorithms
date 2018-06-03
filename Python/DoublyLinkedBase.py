class _DoublyLinkedBase:

    class _Node:
        __slots__ = '_item', '_prev', '_next'

        def __init__(self, item, prev, next):
            self._item = item
            self._prev = prev
            self._next = next

    def __init__(self):
        self._header = self._Node(None, None, None)
        self._trailer = self._Node(None, None, None)
        self._header._next = self._trailer
        self._trailer._prev = self._header
        self._size = 0

    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size == 0

    def _insert_between(self, item, predecessor, successor):
        newnode = self._Node(item, predecessor, successor)
        predecessor._next = newnode
        successor._prev = newnode
        self._size += 1
        return newnode

    def _delete_node(self, node):
        predecessor = node._prev
        successor = node._next
        predecessor._next = successor
        successor._prev = predecessor
        self._size -= 1
        item = node._item
        node._item = node._prev = node._next = None
        return item
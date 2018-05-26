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
        return self._size == 0

    def _advance(self):
        self._cursor = self._cursor._next

    def enqueue(self, item):
        newnode = self._Node(item, None)
        if self.is_empty():
            newnode._next = newnode
            self._cursor = newnode
        else:
            newnode._next = self._cursor._next
            self._cursor._next = newnode
            self._advance()
        self._size += 1

    def dequeue(self):
        if self.is_empty():
            raise Empty('Queue is empty')

        head = self._cursor._next
        item = head._item
        self._size -= 1
        if self.is_empty():
            self._cursor = None
        else:
            self._cursor._next = head._next

        return item

    def front(self):
        return self._cursor._next._item


if __name__ == '__main__':
    q = CircularQueue()
    q.enqueue(2)
    q.enqueue(4)
    q.enqueue(6)
    print(q.dequeue())
    q.enqueue(9)
    print(q.front())
    print(q.dequeue())
    q.dequeue()
    q.dequeue()




class Empty(Exception):
    pass

class LinkedStack:

    class _Node:
        __slots__ = '_item', '_next'

        def __init__(self, item, next):
            self._item = item
            self._next = next

    def __init__(self):
        self._head = None
        self._size = 0

    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size == 0

    def push(self, item):
        self._head = self._Node(item, self._head)
        self._size += 1

    def pop(self):
        if self.is_empty():
            raise Empty('Stack is empty')

        item = self._head._item
        self._head = self._head._next
        self._size -= 1
        return item

    def top(self):
        if self.is_empty():
            raise Empty('Stack is empty')
        return self._head._item


if __name__ == '__main__':
    stack = LinkedStack()
    stack.push(2)
    stack.push(3)
    stack.top()
    stack.pop()
from DoublyLinkedBase import _DoublyLinkedBase


class Empty(Exception):
    pass


class LinkedDeque(_DoublyLinkedBase):

    def first(self):
        if self.is_empty():
            raise Empty('Deque is empty')

        return self._header._next._item

    def last(self):
        if self.is_empty():
            raise Empty('Deque is empty')

        return self._trailer._prev._item

    def insert_first(self, item):
        self._insert_between(item, self._header, self._header._next)

    def insert_last(self, item):
        self._insert_between(item, self._trailer._prev, self._trailer)

    def remove_first(self):
        if self.is_empty():
            raise Empty('Deque is empty')
        return self._delete_node(self._header._next)

    def remove_last(self):
        if self.is_empty():
            raise Empty('Deque is empty')
        return self._delete_node(self._trailer._prev)


if __name__ == '__main__':
    deque = LinkedDeque()
    deque.insert_first(1)
    deque.insert_first(2)
    deque.insert_last(3)
    deque.insert_last(4)
    print(deque.remove_first())
    print(deque.remove_last())
    print(len(deque))
    print(deque.is_empty())
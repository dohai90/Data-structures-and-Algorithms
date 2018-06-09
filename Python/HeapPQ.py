from PriorityQueueBase import PriorityQueueBase
from random import *


class Empty(Exception):
    pass


class HeapPQ(PriorityQueueBase):
    """ Array base heap priority queue """

    def __init__(self):
        self._data = []

    """ non-public methods """
    def __len__(self):
        return len(self._data)

    def __iter__(self):
        for item in self._data:
            yield item

    def _parent(self, idx):
        return (idx - 1) // 2

    def _left(self, idx):
        return 2*idx + 1

    def _has_left(self, idx):
        return self._left(idx) < len(self._data)

    def _right(self, idx):
        return 2*idx + 2

    def _has_right(self, idx):
        return self._right(idx) < len(self._data)

    def _swap(self, i, j):
        self._data[i], self._data[j] = self._data[j], self._data[i]

    def _upheap(self, idx):
        parent = self._parent(idx)
        if idx > 0 and self._data[idx] < self._data[parent]:
            self._swap(idx, parent)
            self._upheap(parent)

    def _downheap(self, idx):
        if self._has_left(idx):
            left = self._left(idx)
            smallest = left
            if self._has_right(idx):
                right = self._right(idx)
                if self._data[left] > self._data[right]:
                    smallest = right

            if self._data[idx] > self._data[smallest]:
                self._swap(idx, smallest)
                self._downheap(smallest)

    """ public methods """
    def add(self, k, v):
        self._data.append(self._Item(k, v))
        self._upheap(len(self._data) - 1)

    def min(self):
        if self.is_empty():
            raise Empty("Priority queue is empty!")

        item = self._data[0]
        return item._key, item._val

    def remove_min(self):
        if self.is_empty():
            raise Empty("Priority queue is empty!")

        self._swap(0, len(self._data) - 1)
        item = self._data.pop()
        self._downheap(0)
        return item._key, item._val


if __name__ == "__main__":
    pq = HeapPQ()
    for i in range(100):
        k = v = randint(1, 1000)
        pq.add(k, v)

    print("After adding items")
    for item in pq:
        print(item.key(), item.value())

    print("Remove min")
    for i in range(8):
        print(pq.remove_min())

    print("After removing items")
    for item in pq:
        print(item.key(), item.value())
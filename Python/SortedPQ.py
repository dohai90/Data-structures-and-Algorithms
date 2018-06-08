from PositionalList import PositionalList
from PriorityQueueBase import PriorityQueueBase
from random import *


class Empty(Exception):
    pass


class SortedPQ(PriorityQueueBase):
    """ Sorted priority queue"""

    def __init__(self):
        self._data = PositionalList()

    def __len__(self):
        return len(self._data)

    def add(self, k, v):
        newest = self._Item(k, v)
        walk = self._data.last()
        while walk is not None and newest < walk.item():
            walk = self._data.before(walk)
        if walk is None:
            self._data.add_first(newest)
        else:
            self._data.add_after(newest, walk)

    def min(self):
        item = self._data.first().item()
        return item._key, item._val

    def remove_min(self):
        p = self._data.first()
        item = p.item()
        self._data.delete(p)
        return item._key, item._val

    def __iter__(self):
        for item in self._data:
            yield item


if __name__ == "__main__":
    pq = SortedPQ()
    for i in range(5):
        k = v = randint(1, 100)
        pq.add(k, v)

    print("After adding items")
    for item in pq:
        print(item.key(), item.value())

    print(pq.remove_min())
    print(pq.remove_min())

    print("After removing items")
    for item in pq:
        print(item.key(), item.value())
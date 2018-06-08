from PositionalList import PositionalList
from PriorityQueueBase import PriorityQueueBase
from random import *


class Empty(Exception):
    pass


class UnsortedPQ(PriorityQueueBase):
    """ Unsorted priority queue """
    def __init__(self):
        self._data = PositionalList()

    def __len__(self):
        return len(self._data)

    def _find_min(self):

        if self.is_empty():
            raise Empty("Queue is empty!")
        min = self._data.first()
        walker = self._data.after(min)
        while walker is not None:
            if min.item() > walker.item():
                min = walker
            walker = self._data.after(walker)
        return min

    def min(self):
        p = self._find_min()
        return p.item()._key, p.item()._val

    def remove_min(self):
        p = self._find_min()
        item = p.item()
        self._data.delete(p)
        return item._key, item._val

    def add(self, k, v):
        self._data.add_last(self._Item(k, v))

    def __iter__(self):
        for item in self._data:
            yield item


if __name__ == "__main__":
    pq = UnsortedPQ()
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


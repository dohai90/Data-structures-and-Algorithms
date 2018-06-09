from MapBase import MapBase
from random import *


class UnsortedTableMap(MapBase):
    """ Concrete implementation of Map base class """

    def __init__(self):
        self._table = []        # store item in a python list

    def __len__(self):
        return len(self._table)

    def __setitem__(self, key, value):
        for item in self._table:
            if item._key == key:
                item._val = value     # search hit -> update existing key
                return
        self._table.append(self._Item(key, value))

    def __getitem__(self, key):
        for item in self._table:
            if item._key == key:
                return item._val        # search hit -> return value associated with key

        raise KeyError('Key error: ' + repr(key))

    def __delitem__(self, key):
        for i in range(len(self._table)):
            if self._table[i]._key == key:
                self._table.pop(i)      # search hit -> delete key-value pair
                return

        raise KeyError('Key error: ' + repr(key))

    def __iter__(self):
        for item in self._table:
            yield item._key


if __name__ == '__main__':
    umap = UnsortedTableMap()
    for i in range(10):
        k = v = i
        umap[k] = v

    print("After adding items")
    for key in umap:
        print(umap[key])

    print("Deleting:")
    for key in umap:    # why doesn't it iterate all keys in umap???
        print(key)
        del umap[key]

    print("After removing items: ", len(umap))
    for key in umap:
        print(umap[key])


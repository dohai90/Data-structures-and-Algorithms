from MapBase import MapBase
from random import randrange


class HashMapBase(MapBase):
    """ Abstract base class for map using hash-table with MAD compression """

    def __int__(self, cap=11, p=109345121):
        self._table = [None] * cap
        self._n = 0
        self._prime = p
        self._scale = 1 + randrange(p - 1)
        self._shift = randrange(p)

    def __len__(self):
        return self._n

    def _hash_function(self, key):
        return (hash(key)*self._scale + self._shift) % self._prime % len(self._table)

    def __setitem__(self, key, value):
        idx = self._hash_function(key)
        self._bucket_setitem(idx, key, value)
        if self._n > len(self._table) // 2:
            self._resize(2 * len(self._table) - 1)

    def __getitem__(self, key):
        idx = self._hash_function(key)
        return self._bucket_getitem(idx, key)

    def __delitem__(self, key):
        idx = self._hash_function(key)
        self._bucket_delitem(idx, key)
        self._n -= 1

    def _resize(self, c):
        old = list(self.items())
        self._table = [None] * c
        self._n = 0
        for (k, v) in old:
            self[k] = v
from HashMapBase import HashMapBase
from UnsortedTableMap import UnsortedTableMap


class ChainHashMap(HashMapBase):
    """ Hash Map implementation using separate chaining technique to solve collision """

    def __init__(self):
        super().__int__(cap=11, p=109345121)

    def _bucket_getitem(self, idx, key):
        bucket = self._table[idx]
        if bucket is None:
            raise KeyError('Key Error: ' + repr(key))
        return bucket[key]

    def _bucket_setitem(self, idx, key, value):
        bucket = self._table[idx]
        if bucket is None:
            bucket = UnsortedTableMap()
        old = len(bucket)
        bucket[key] = value
        if len(bucket) > old:
            self._n += 1
        self._table[idx] = bucket

    def _bucket_delitem(self, idx, key):
        bucket = self._table[idx]
        if bucket is None:
            raise KeyError('Key Error: ' + repr(key))
        del bucket[key]

    def __iter__(self):
        for bucket in self._table:
            if bucket is not None:
                for key in bucket:
                    yield key


if __name__ == "__main__":
    hmap = ChainHashMap()
    hmap["John"] = 10
    hmap["Alice"] = 52
    hmap["David"] = 12
    hmap["Bob"] = 26
    hmap["Chris"] = 74

    for key, value in hmap.items():
        print(key, value)

    del hmap["John"]
    del hmap["Alice"]
    del hmap["David"]
    del hmap["Bob"]
    del hmap["Chris"]

    print("After deleting: ", len(hmap))


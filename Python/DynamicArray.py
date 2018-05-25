import ctypes


class DynamicArray:
    def __init__(self):
        self._n = 0
        self._cap = 1
        self._A = self._make_array(self._cap)

    def __len__(self):
        return self._n

    def __getitem__(self, k):
        if not 0 <= k < self._n:
            raise IndexError('Index out of bounce')
        return self._A[k]

    def append(self, obj):
        if self._n == self._cap:
            self._resize(2 * self._cap)
        self._A[self._n] = obj
        self._n += 1

    def _resize(self, newcap):
        B = self._make_array(newcap)
        for i in range(self._n):
            B[i] = self._A[i]
        self._cap = newcap
        self._A = B

    def _make_array(self, cap):
        return (cap * ctypes.py_object)()


if __name__ == '__main__':
    a = DynamicArray()
    for i in range(10):
        a.append(i)

    for i in range(10):
        print(a[i])
class Empty(Exception):
    pass


class ArrayQueue:
    MAX_CAP = 2

    def __init__(self):
        self._data = [None] * ArrayQueue.MAX_CAP
        self._size = 0
        self._front = 0

    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size == 0

    def _resize(self, newcap):
        old = self._data
        self._data = [None] * newcap
        walk = self._front
        for i in range(len(old)):
            self._data[i] = old[walk]
            walk = (walk + 1) % len(old)
        self._front = 0

    def enqueue(self, item):
        if self._size == len(self._data):
            self._resize(2*len(self._data))

        avail = (self._front + self._size) % len(self._data)
        self._data[avail] = item
        self._size += 1

    def dequeue(self):
        if self.is_empty():
            raise Empty('Dequeue on empty queue exception!')

        item = self._data[self._front]
        self._data[self._front] = None
        self._front = (self._front + 1) % len(self._data)
        self._size -= 1

        if 0 < self._size < len(self._data) // 4:
            self._resize(len(self._data) // 2)

        return item

    def front(self):
        return self._data[self._front]


if __name__ == '__main__':

    q = ArrayQueue()
    q.enqueue(3)
    q.enqueue(4)
    q.enqueue(5)
    q.enqueue(6)
    q.dequeue()
    q.enqueue(7)
    q.dequeue()
    q.dequeue()
    for i in range(4):
        q.enqueue(i+5)

    print(len(q))


class PriorityQueueBase:
    """ Base class for priority queue """

    class _Item:
        """ Items in a priority queue """
        def __init__(self, k, v):
            self._key = k
            self._val = v

        def __lt__(self, other):
            return self._key < other._key

        def key(self):
            return self._key

        def value(self):
            return self._val

    def is_empty(self):
        return len(self) == 0
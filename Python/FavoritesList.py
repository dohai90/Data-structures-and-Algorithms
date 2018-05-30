from PositionalList import PositionalList


class FavoritesList:

    class _Item:

        def __init__(self, val):
            self._value = val
            self._count = 0

    def __init__(self):
        self._data = PositionalList()

    """ nonpublic utilities """
    def _find_position(self, val):
        walker = self._data.first()
        while walker is not None and walker.item()._value != val:
            walker = self._data.after(walker)
        return walker

    def _move_up(self, p):
        if p != self._data.first():
            walker = self._data.before(p)
            cnt = p.item()._count
            if cnt > walker.item()._count:
                while walker != self._data.first() and cnt > self._data.before(walker).item()._count:
                    walker = self._data.before(walker)

                self._data.add_before(self._data.delete(p), walker)

    """ public methods"""
    def __len__(self):
        return len(self._data)

    def is_empty(self):
        return len(self._data) == 0

    def access(self, val):
        p = self._find_position(val)
        if p is None:
            p = self._data.add_last(self._Item(val))
        p.item()._count += 1
        self._move_up(p)

    def access_item(self, item):
        val = item._value
        p = self._find_position(val)
        if p is None:
            p = self._data.add_last(item)
        self._move_up(p)

    def remove(self, val):
        p = self._find_position(val)
        if p is not None:
            self._data.delete(p)

    def top(self, k):
        if not 1 <= k <= len(self):
            raise ValueError('Illegal value for k')
        walker = self._data.first()
        for i in range(k):
            yield walker.item()._value
            walker = self._data.after(walker)


if __name__ == '__main__':
    fl = FavoritesList()
    for i in range(3):
        fl.access(3)

    for i in range(1):
        fl.access(1)

    for i in range(9):
        fl.access(9)

    for i in range(7):
        fl.access(7)

    for value in fl.top(2):
        print(value, end=' ')

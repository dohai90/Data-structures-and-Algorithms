from FavoritesList import FavoritesList


class FavoritesListMTF(FavoritesList):
    """ Implement Favorites List with move-to-front heuristic """

    def _move_up(self, p):
        if p != self._data.first():
            self._data.add_first(self._data.delete(p))

    def top(self, k):
        """ search k time in temp list because the original list is not sorted any longer"""
        if not 1 <= k <= len(self):
            raise ValueError('Illegal k value')

        temp = FavoritesList()
        for item in self._data:
            temp.access_item(item)

        for value in temp.top(k):
            yield value

    def __iter__(self):
        walker = self._data.first()
        while walker is not None:
            yield walker.item()._value
            walker = self._data.after(walker)


if __name__ == '__main__':
    fl = FavoritesListMTF()
    for i in range(3):
        fl.access(3)

    for i in range(1):
        fl.access(1)

    for i in range(9):
        fl.access(9)

    for i in range(7):
        fl.access(7)

    print('Value in favorites list:')
    for value in fl:
        print(value, end=' ')
    print()

    print('Top count:')
    for value in fl.top(4):
        print(value, end=' ')
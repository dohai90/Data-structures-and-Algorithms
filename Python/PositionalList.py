from DoublyLinkedBase import _DoublyLinkedBase


class PositionalList(_DoublyLinkedBase):

    class Position:

        def __init__(self, container, node):
            self._container = container
            self._node = node

        def item(self):
            return self._node._item

        def __eq__(self, other):
            return type(other) is type(self) and other._node is self._node

        def __ne__(self, other):
            return not (self == other)

    def _validate(self, p):
        if not isinstance(p, self.Position):
            raise TypeError('p must be proper Position type')
        if p._container is not self:
            raise ValueError('p does not belong to this container')
        if p._node._next is None:
            raise ValueError('p no longer valid')
        return p._node

    def _make_position(self, node):
        if node is self._header or node is self._trailer:
            return None
        else:
            return self.Position(self, node)

    """ Accessors """
    def first(self):
        return self._make_position(self._header._next)

    def last(self):
        return self._make_position(self._trailer._prev)

    def before(self, p):
        node = self._validate(p)
        return self._make_position(node._prev)

    def after(self, p):
        node = self._validate(p)
        return self._make_position(node._next)

    def __iter__(self):
        cursor = self.first()
        while cursor is not None:
            yield cursor.item()
            cursor = self.after(cursor)

    """ Mutators """
    def _insert_between(self, item, predecessor, successor):
        node = super()._insert_between(item, predecessor, successor)
        return self._make_position(node)

    def add_first(self, item):
        return self._insert_between(item, self._header, self._header._next)

    def add_last(self, item):
        return self._insert_between(item, self._trailer._prev, self._trailer)

    def add_before(self, item, p):
        node = self._validate(p)
        return self._insert_between(item, node._prev, node)

    def add_after(self, item, p):
        node = self._validate(p)
        return self._insert_between(item, node, node._next)

    def delete(self, p):
        node = self._validate(p)
        return self._delete_node(node)

    def replace(self, item, p):
        node = self._validate(p)
        old_value = node._item
        node._item = item
        return old_value


def insertion_sort(L):
    """ Insertion sort on Positional List"""
    if len(L) > 1:          # otherwise, don't need to sort
        marker = L.first()

        while marker != L.last():
            pivot = L.after(marker)
            value = pivot.item()
            if value >= marker.item():
                marker = pivot
            else:
                walker = marker
                while walker != L.first() and value < L.before(walker).item():
                    walker = L.before(walker)

                L.delete(pivot)
                L.add_before(value, walker)


if __name__ == '__main__':
    pl = PositionalList()
    p1 = pl.add_first(1)
    p2 = pl.add_first(2)
    p3 = pl.add_last(3)
    p4 = pl.add_last(4)
    p5 = pl.add_before(5, p4)
    p6 = pl.add_after(6, p2)

    for item in pl:
        print(item, end=' ')
    print()

    print(pl.delete(p6))
    print(pl.replace(7, p5))

    print('New list:')
    for item in pl:
        print(item, end=' ')
    print()

    insertion_sort(pl)
    print('Sorted list:')
    for item in pl:
        print(item, end=' ')
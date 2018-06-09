from collections import MutableMapping

class MapBase(MutableMapping):
    """ Map base class inherites from Mutable Mapping class """
    class _Item:
        """ Item is included in Map base """
        def __init__(self, k, v):
            self._key = k
            self._val = v

        def __eq__(self, other):
            return self._key == other._key

        def __ne__(self, other):
            return not (self._key == other._key)

        def __lt__(self, other):
            return self._key < other._key
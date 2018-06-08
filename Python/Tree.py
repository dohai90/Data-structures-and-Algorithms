from LinkedQueue import LinkedQueue


class Tree:
    """ Abstract base class representing a tree structure """

    #---------------------nested Position class--------------
    class Position:
        """ Abstract class repsenting a location of an element in a tree """
        def element(self):
            raise NotImplementedError('must be implemented by subclass')

        def __eq__(self, other):
            raise NotImplementedError('must be implemented by subclass')

        def __ne__(self, other):
            raise not (self == other)

    #---------abstract methods that subclass must support----------
    def root(self):
        raise NotImplementedError('must be implemented by subclass')

    def parent(self, p):
        raise NotImplementedError('must be implemented by subclass')

    def num_children(self, p):
        raise  NotImplementedError('must be implemented by subclass')

    def children(self, p):
        raise NotImplementedError('must be implemented by subclass')

    def __len__(self):
        raise NotImplementedError('must be implemented by subclass')

    #--------concrete methods implemented in this class-------------
    def is_root(self, p):
        return self.parent(p) == None

    def is_leaf(self, p):
        return self.num_children(p) == 0

    def is_empty(self):
        return len(self) == 0

    def depth(self, p):
        if self.is_root(p):
            return 0
        return 1 + self.depth(self.parent(p))

    def _height(self, p):
        if self.is_leaf(p):
            return 0
        return 1 + max(self._height(c) for c in self.children(p))

    def height(self, p=None):
        if p is None:
            p = self.root()
        return self._height(p)

    def preorder(self):
        """ Generate a preorder iteration of positions in the tree"""
        if not self.is_empty():
            for p in self._subtree_preorder(self.root()):
                yield p

    def _subtree_preorder(self, p):
        """ Generate a preorder iteration of positions of a subtree rooted at p """
        yield p
        for c in self.children(p):
            for other in self._subtree_preorder(c):
                yield other

    def postorder(self):
        """ Generate a postorder iteration of positions in the tree"""
        if not self.is_empty():
            for p in self._subtree_postorder(self.root()):
                yield p

    def _subtree_postorder(self, p):
        """ Generate a postorder iteration of positions of a subtree rooted at p """
        for c in self.children(p):
            for other in self._subtree_postorder(c):
                yield other
        yield p

    def breathfirst(self):
        """ Generate a breath first iteration of positions in the tree """
        if not self.is_empty():
            q = LinkedQueue()
            q.enqueue(self.root());
            while not q.is_empty():
                p = q.dequeue()
                yield p
                for c in self.children(p):
                    q.enqueue(c)

    def positions(self):
        """ Generate all positions in a given tree """
        return self.preorder()
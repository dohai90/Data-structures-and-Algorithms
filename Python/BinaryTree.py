from Tree import Tree


class BinaryTree(Tree):
    """ An abstract base class representing a binary tree"""

    def left(self, p):
        """ Return a Position of a left child of p
            or None if p has no left child """
        raise NotImplementedError('must be implemented by subclass')

    def right(self, p):
        """ Return a Position of a right child of p
            or None if p has no right child """
        raise NotImplementedError('must be implemented by subclass')

    def sibling(self, p):
        """ Return the sibling of p"""
        parent = self.parent(p)
        if parent is None:
            return None         # p is root
        else:
            if p == self.left(parent):
                return self.right(parent)
            else:
                return self.left(parent)

    def children(self, p):
        """ Return an iteration of Positions representing p's children"""
        if self.left(p) is not None:
            yield self.left(p)
        if self.right(p) is not None:
            yield self.right(p)
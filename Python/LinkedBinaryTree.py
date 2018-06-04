from BinaryTree import BinaryTree


class LinkedBinaryTree(BinaryTree):
    """ Linked representation of a binary tree structure """

    class _Node:
        __slots__ = '_element', '_parent', '_left', '_right'

        def __init__(self, element, parent=None, left=None, right=None):
            self._element = element
            self._parent = parent
            self._left = left
            self._right = right

    class Position(BinaryTree.Position):

        def __init__(self, container, node):
            self._container = container
            self._node = node

        def element(self):
            return self._node._element

        def __eq__(self, other):
            return type(self) is type(other) and self._node is other._node

    def _validate(self, p):
        if not isinstance(p, self.Position):
            raise TypeError('p must be proper Position type')
        if p._container is not self:
            raise ValueError('p does not belong to this container')
        if p._node._parent is p._node:
            raise ValueError('p is no longer valid')
        return p._node

    def _make_position(self, node):
        """ Return Position instance of a given node (or None if no node) """
        return self.Position(self, node) if node is not None else None

    #---Linked Binary Tree constructor---------------------------------
    def __init__(self):
        self._root = None
        self._size = 0

    #----accessors-----------------------------------------------------
    def __len__(self):
        """ Return the number of elements in the Tree"""
        return self._size

    def root(self):
        """ Return the root Position of the tree """
        return self._make_position(self._root)

    def parent(self, p):
        """ Return the Position of p's parent (or None if p is root) """
        node = self._validate(p)
        return self._make_position(node._parent)

    def left(self, p):
        """ Return the Position of p's left child (or None if p is external) """
        node = self._validate(p)
        return self._make_position(node._left)

    def right(self, p):
        """ Return the Position of p's right child (or None if p is external) """
        node = self._validate(p)
        return self._make_position(node._right)

    def num_children(self, p):
        """ Return the number of children of Position p"""
        count = 0
        node = self._validate(p)
        if node._left is not None:
            count += 1
        if node._right is not None:
            count += 1
        return count

    def _add_root(self, e):
        """ Add an element e to the root of tree. """
        if self._root is not None:
            raise ValueError('Root exists')
        self._root = self._Node(e)
        self._size = 1
        return self._make_position(self._root)

    def _add_left(self, p, e):
        node = self._validate(p)
        if node._left is not None:
            raise ValueError('Left child exists')
        node._left = self._Node(e, node)
        return self._make_position(node._left)

    def _add_right(self, p, e):
        node = self._validate(p)
        if node._right is not None:
            raise ValueError('Right child exits')
        node._right = self._Node(e, node)
        return self._make_position(node._right)

    def _replace(self, p, e):
        node = self._validate(p)
        old = node._element
        node._element = e
        return old

    def _delete(self, p):
        """ Delete node at Position p
            :raise ValueError if p is not valid or p has 2 children
            :return element stored in deleted Position
        """
        node = self._validate(p)
        if self.num_children(p) == 2:
            raise ValueError('p has 2 children')
        child = node._left if node._left else node._right # child may be None
        if child is not None:
            child._parent = node._parent
        if node is self._root:
            self._root = child
        else:
            parent = node._parent
            if node is parent._left:
                parent._left = child
            else:
                parent._right = child

        self._size -= 1
        node._parent = node     # convention for deprecated node
        return node._element

    def _attach(self, p, t1, t2):
        """ Attach tree t1 and t2 as left and right subtree of external p"""
        node = self._validate(p)
        if not self.is_leaf(p):
            raise ValueError('p must be external node')
        if not type(self) is type(t1) is type(t2):
            raise TypeError('Tree types must match')

        self._size += len(t1) + len(t2)
        if not t1.is_empty():
            t1._root._parent = node
            node._left = t1._root       # t1 becomes left child of p
            t1._root = None
            t1._size = 0
        if not t2.is_empty():
            t2._root._parent = node
            node._right = t2._root      # t2 becomes right child of p
            t2._root = None
            t2._size = 0



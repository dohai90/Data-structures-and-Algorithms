from Graph import Graph


class DepthFirstPaths:
    """ Path finding using depth first search algorithm """
    def __init__(self, G, s):
        self._s = s
        self._marked = [False] * G.V()
        self._edgeTo = [None] * G.V()
        self._dfs(G, s)

    def _dfs(self, G, v):
        self._marked[v] = True
        for w in G.adj(v):
            if not self._marked[w]:
                self._edgeTo[w] = v
                self._dfs(G, w)

    def has_path_to(self, v):
        return self._marked[v]

    def path_to(self, v):
        path = []
        x = v
        while x != self._s:
            path.insert(0, x)
            x = self._edgeTo[x]
        path.insert(0, self._s)

        for w in path:
            yield w


if __name__ == '__main__':
    G = Graph('./data/tinyCG.txt')
    s = 0
    dfp = DepthFirstPaths(G, s)
    for v in range(G.V()):
        if dfp.has_path_to(v):
            print(s, 'to', v, ': ', end='')
            for w in dfp.path_to(v):
                if w == s:
                    print(w, end='')
                else:
                    print('-', w, sep='', end='')
            print()

from Graph import Graph


class BreathFirstPaths:
    """ Path finding using breath first search algorithm """

    def __init__(self, G, s):
        self._s = s
        self._marked = [False] * G.V()
        self._edgeTo = [None] * G.V()
        self._bfs(G, s)

    def _bfs(self, G, s):
        q = []
        self._marked[s] = True
        q.insert(0, s)
        while len(q) != 0:
            v = q.pop(0)
            for w in G.adj(v):
                if not self._marked[w]:
                    self._edgeTo[w] = v
                    self._marked[w] = True
                    q.append(w)

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
    bfp = BreathFirstPaths(G, s)
    for v in range(G.V()):
        if bfp.has_path_to(v):
            print(s, 'to', v, ': ', end='')
            for w in bfp.path_to(v):
                if w == s:
                    print(w, end='')
                else:
                    print('-', w, sep='', end='')
            print()

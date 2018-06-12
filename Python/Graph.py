class Graph:
    """ Graph data structure """

    def __init__(self, filename):
        with open(filename) as f:
            lines = f.readlines()
        lines = [x.strip() for x in lines]
        self._V = int(lines[0])
        self._E = 0
        self._adj = [[] for i in range(self._V)]
        for i in range(int(lines[1])):
            line = lines[i+2].split(' ')
            self._add_edge(int(line[0]), int(line[1]))

    def V(self):
        return self._V

    def E(self):
        return self._E

    def _add_edge(self, v, w):
        self._adj[v].insert(0, w)
        self._adj[w].insert(0, v)
        self._E += 1

    def adj(self, v):
        return self._adj[v]

    def __str__(self):
        s = str(self._V) + ' vertices, ' + str(self._E) + ' edges\n'
        for v in range(self._V):
            s += str(v) + ': '
            for w in self.adj(v):
                s += str(w) + ' '
            s += '\n'
        return s


if __name__ == '__main__':
    G = Graph('./data/tinyG.txt')
    print(G)



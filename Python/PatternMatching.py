def find_brute_force(T, P):
    """ Return the lowest index of T at which substring P begins (or else -1)."""
    n, m = len(T), len(P)
    for i in range(n-m+1):
        k = 0
        while k < m and T[i+k] == P[k]:
            k += 1
        if k == m:
            return i
    return -1


def find_boyer_moore(T, P):
    """ Return the lowest index of T at which substring P begins (or else -1)."""
    n, m = len(T), len(P)
    if m == 0:
        return 0
    last = {}       # create "last" dictionary
    for k in range(m):
        last[P[k]] = k
    i = m - 1       # an index into T
    k = m - 1       # an index into P
    while i < n:
        if T[i] == P[k]:
            if k == 0:
                return i
            else:
                i -= 1
                k -= 1
        else:
            j = last.get(T[i], -1)
            i += m - min(k, j + 1)
            k = m - 1
    return -1


def compute_kmp_fail(P):
    """ Utility that computes and return KMP 'fail' list."""
    m = len(P)
    fail = [0] * m
    j = 1
    k = 0
    while j < m:
        if P[j] == P[k]:
            fail[j] = k + 1
            j += 1
            k += 1
        elif k > 0:
            k = fail[k - 1]
        else:
            j += 1

    return fail


def find_kmp(T, P):
    """ Return the lowest index of T at which substring P begins (or else -1)."""
    n, m = len(T), len(P)
    if m ==0:
        return 0        # trivial search for empty string
    fail = compute_kmp_fail(P)
    j = 0               # index into T
    k = 0               # index into P
    while j < n:
        if T[j] == P[k]:
            if k == m - 1:
                return j - m + 1
            j += 1
            k += 1
        elif k > 0:
            k = fail[k-1]
        else:
            j += 1
    return -1

if __name__ == "__main__":
    T = 'abacaabadcabacabaabb'
    T1 = 'abdfljkamalgamationfkd'
    P1 = 'amalgamation'
    P = 'abacab'
    print(find_brute_force(T, P))
    print((find_boyer_moore(T, P)))
    print((find_kmp(T1, P1)))
def rank(a, k, lo, hi):
    if lo > hi:
        return lo
    mid = lo + (hi - lo)//2
    if k < a[mid]:
        return rank(a, k, lo, mid - 1)
    elif k > a[mid]:
        return rank(a, k, mid + 1, hi)
    else:
        return mid


if __name__ == '__main__':
    a = [2, 4, 5, 7, 8, 9, 12, 14, 17, 19, 22, 25, 27, 28, 33, 37]
    k = 38
    i = rank(a, k, 0, len(a)-1)
    if 0 <= i <= len(a) - 1 and a[i] == k:
        print(i)
    else:
        print('not found', i)
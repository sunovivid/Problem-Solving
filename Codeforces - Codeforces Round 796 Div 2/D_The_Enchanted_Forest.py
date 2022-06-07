# D. The Enchanted Forest
from typing import Iterable


def ssum(x):
    return x * (x + 1) // 2


def answer(a: Iterable[int], k):
    d = len(a)
    l = max(0, k // d)
    r = None
    if k < d:
        r = ssum(k)
    # r = ssum(l - k % d) - ssum(l - d)
    # print(d, l, k, r)
    if k >= d:
        return sum(a) + r
    else:
        return sum(sorted(a, reverse=True)[:k]) + r

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = tuple(map(int, input().split()))
    print(answer(a, k))

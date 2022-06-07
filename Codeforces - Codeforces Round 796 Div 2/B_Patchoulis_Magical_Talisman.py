# B. Patchouli's Magical Talisman
from typing import List, Iterable


def p(x):
    b = bin(x)
    return len(b) - 1 - b.rindex('1')


def answer(a: Iterable[int]):
    evens = tuple(p(x) for x in a if x % 2 == 0)
    if not evens:
        return 0
    if any(x % 2 == 1 for x in a):
        return len(evens)
    return min(evens) + len(evens) - 1


t = int(input())
for _ in range(t):
    input()
    _a = tuple(map(int, input().split()))
    print(answer(_a))

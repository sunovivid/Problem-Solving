# B. Shoe Shuffling
import itertools
from collections import deque
from typing import Dict


def answer(a):
    groups = tuple(len(tuple(v)) for k, v in itertools.groupby(sorted(a)))
    if any((len_v == 1 for len_v in groups)):
        yield -1
        return

    size_indices: Dict[deque] = {}
    for i, size in enumerate(a):
        size_indices.setdefault(size, deque()).append(i)

    for indices in size_indices.values():
        indices.rotate(1)

    for size in a:
        yield size_indices[size].popleft() + 1

t = int(input())
for _ in range(t):
    input()
    a = tuple(map(int, input().split()))
    print(' '.join(map(str, answer(a))))
# 17626 Four Squares
import itertools

MAX = 50_000


def answer(n):
    squares = [i * i for i in range(1, int(n ** 0.5) + 1) if i * i < MAX]
    if n in squares:
        return 1
    for x in squares:
        if n - x in squares:
            return 2
    for x, y in itertools.combinations(squares, 2):
        if n - (x + y) in squares:
            return 3
    return 4


n = int(input())
print(answer(n))

# C. Sum of Substrings
from itertools import tee


def pairwise(iterable):
    # pairwise('ABCDEFG') --> AB BC CD DE EF FG
    a, b = tee(iterable)
    next(b, None)
    return zip(a, b)


def f(s):
    return sum(10 * int(a) + int(b) for a, b in pairwise(s))


def answer(s, k):
    f_val = f(s)
    if '1' not in s:
        return f_val

    one_used = False
    rswap_cost = len(s) - 1 - s.rindex('1')
    if s[-1] == '0' and rswap_cost <= k:
        f_val -= 10
        k -= rswap_cost
        one_used = True

    lswap_cost = s.index('1')
    one_usable = not one_used or s.count('1') >= 2
    if one_usable and s[0] == '0' and lswap_cost <= k:
        f_val -= 1
    return f_val


t = int(input())
for _ in range(t):
    _, k = map(int, input().split())
    s = input()
    print(answer(s, k))

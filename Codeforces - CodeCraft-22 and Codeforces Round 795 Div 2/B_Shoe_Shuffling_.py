# B. Shoe Shuffling
def answer(a):
    if len(a) == len(set(a)):
        return -1
    found = {}
    duplicated = set()
    for i, x in enumerate(a):
        if x not in found:
            found[x] = i
        else:
            duplicated.add(found[x])
            duplicated.add(i)

    for i in range(len(a)):
        if i not in duplicated:
            yield a
        else:
            yield tuple(duplicated - {i})[0]

t = int(input())
for _ in range(t):
    input()
    a = tuple(map(int, input().split()))
    print(' '.join(map(str, answer(a))))
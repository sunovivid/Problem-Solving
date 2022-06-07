# B. Shoe Shuffling
def answer(a):
    if len(a) == len(set(a)):
        yield -1
        return

    found = {}
    duplicated = set()
    for i, x in enumerate(a):
        if x not in found:
            found[x] = i
        elif not duplicated:
            duplicated.add(found[x])
            duplicated.add(i)

    for i in range(len(a)):
        if i not in duplicated:
            yield i + 1
        else:
            yield tuple(duplicated - {i})[0] + 1


t = int(input())
for _ in range(t):
    input()
    a = tuple(map(int, input().split()))
    print(' '.join(map(str, answer(a))))

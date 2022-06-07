# A. Cirno's Perfect Bitmasks Classroom
def answer(x):
    if x == 1:
        return 3

    b = bin(x)[2:]
    if b.count('1') == 1:
        return x + 1

    return 2 ** (len(b) - 1 - b.rindex('1'))


t = int(input())
for _ in range(t):
    print(answer(int(input())))

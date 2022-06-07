# A. Beat The Odds

def answer(a):
    return min(len([x for x in a if x % 2 == 0]), len([x for x in a if x % 2 == 1]))

t = int(input())
for _ in range(t):
    input()
    print(answer(tuple(map(int, input().split()))))
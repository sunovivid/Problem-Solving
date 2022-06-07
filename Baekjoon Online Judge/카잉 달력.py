# 6064 카잉 달력
def answer(m, n, x, y):
    mx = max(m, n)
    mn = min(m, n)
    possible_k_list = [i * max(m, n) + y for i in range(max(m, n))]  # 가능한 k 최댓값이 m * n 이므로 n으로 나눈 나머지가 y인 수들의 목록을 만든다.
    # print(possible_k_list)
    for possible_k in possible_k_list:
        if possible_k % min(m, n) == x % min(m, n):
            return possible_k
    return -1

t = int(input())
for _ in range(t):
    print(answer(*map(int, input().split())))

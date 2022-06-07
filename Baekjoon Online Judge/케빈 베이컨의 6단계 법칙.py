# 케빈 베이컨의 6단계 법칙

INF = 5000 + 10


def answer(n, dist):
    for mid in range(n):
        for start in range(n):
            for end in range(n):
                dist[start][end] = min(dist[start][end], dist[start][mid] + dist[mid][end])

    kevin_num = [sum(dist[i]) for i in range(n)]
    return min(range(n), key=lambda i: kevin_num[i])


n, m = map(int, input().split())
dist = [[INF for _ in range(n)] for _ in range(n)]
for _ in range(m):
    a, b = map(lambda x: int(x) - 1, input().split())
    dist[a][b] = 1
    dist[b][a] = 1
print(answer(n, dist) + 1)

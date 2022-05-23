# 1107 리모컨
MAX = 500_000

def answer(n, broken):
    def possible(x):
        if x < 0 or x > MAX:
            return False
        for c in str(x):
            if c in broken:
                return False
        return True

    def jump_and_move():
        low_ch = n
        high_ch = n
        count = 0
        while low_ch >= 0 or high_ch <= MAX:
            # print(low_ch, high_ch, count)
            if possible(low_ch) or possible(high_ch):
                return min(len(str(low_ch)), len(str(high_ch))) + count
            count += 1
            low_ch -= 1
            high_ch += 1

    return min(jump_and_move(), abs(100 - n))

# 입출력
n = int(input())
m = int(input())
broken = set(input().split()) if m != 0 else set()
print(answer(n, broken))
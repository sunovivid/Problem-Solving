# 1107 리모컨
"""
답 = |목표 수 - 만들 수 있는 가장 가까운 수|
만들 수 있는 가장 가까운 수
2,3,5,8을 쓸 수 있을 때
5823 -> (5222, 3888), 4096 -> (5222, 3888), 1327 -> (2222, (0)888)
가장 큰 자릿수는 가까운 숫자 넣고, 나머지는 가장 크거나 작은 수로 채우기
"""
from typing import List


def answer(n, broken) -> int:
    leftmost: int = int(str(n)[0])
    possible_buttons: List[int] = [i for i in range(0, 9) if i not in broken]

    lower_buttons = [i for i in possible_buttons if i < leftmost]
    nearest_leftmost_lower = str(max(lower_buttons)) if lower_buttons else '0'
    nearest_lower = int(nearest_leftmost_lower + str(max(possible_buttons)) * (len(str(n)) - 1))

    upper_buttons = [i for i in possible_buttons if i > leftmost]
    if upper_buttons:
        nearest_leftmost_upper = str(min(upper_buttons))
        nearest_upper = int(nearest_leftmost_upper + str(min(possible_buttons)) * (len(str(n)) - 1))
    else:
        nearest_upper = int(str(min(possible_buttons)) * (len(str(n)) + 1))
    print(nearest_lower, nearest_upper)
    return min(n - nearest_lower, nearest_upper - n)

print(answer(5457, [6,7,8]))
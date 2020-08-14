//반례: x기준으로 정렬하고 자기보다 작은 인덱스 중에서 y가 큰 애들만 골랐는데, 인덱스 작은 거 하면 '작거나 같다' 도 포함!!

#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 51

using namespace std;

/* 문제 정의
partial order의 순서 매기기?
자기보다 (x,y)가 큰 사람 수 구하기
N <= 50, x,y <= 200
 */

/* 해결 알고리즘 생각
1.
x,y 내림차순 정렬 O(nlgn)
자신보다 작은 인덱스 (자신보댜 x가 큰 애들) 중에서 y도 큰 애들 찾기 O(n^2)

2.
2차원 배열 만들어서 나보다 인덱스 왼쪽 위에 있는 애들 개수 구하기 -> DP

N <= 50이라 1로 충분
*/

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<pair<pair<int, int>, int>> arr;
    int n, x, y, cnt, order[MAX];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        arr.push_back({{-x, -y}, i});
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        for (int j = 0; j < i; j++)
        {
            if (-arr[j].first.first > -arr[i].first.first && -arr[j].first.second > -arr[i].first.second)
            {
                cnt++;
            }
        }
        order[arr[i].second] = cnt + 1;
    }

    for (int i = 0; i < n; i++)
        cout << order[i] << ' ';

    return 0;
}

/*legacy



*/
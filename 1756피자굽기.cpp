#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

#define MAX 300010

using namespace std;

/* 문제 정의
오븐 반지름 순열, 피자 반지름 순열 -> 마지막 피자의 위치
D, N <= 3*10^5 
 */

/* 해결 알고리즘 생각
오븐 반지름 순열을 (깊이, 반지름)에서 (반지름, 깊이)로 정렬
반죽 순서대로 최대 들어갈 수 있는 깊이까지 넣기
    걸리는 경우 -> 반죽 인덱스는 오븐 반지름이 자신보다 작은 최초 인덱스 -1
    걸리지 않을경우 = 반죽에 막혀서 쌓이는 경우 -> 최근 반죽의 인덱스 - 1
DlgD * lgN
이분탐색 초과 기준: 자신보다 크거나 (걸리는 경우), 
last_depth를 초과한 경우 (반죽에 막혀서 쌓이는 경우)
*/

/*의사코드
oven = [반지름, 깊이]
oven 반지름 기준 내림차순 정렬
for 반지름 in pizza:
    이분탐색 {
        high = last_depth - 1
        while (low > high)
            mid = (low + high) / 2
            if (oven[mid].first >= 반지름)
                low = mid + 1
            else
                high = mid - 1
        last_depth = oven[low].second - 1;
    }
*/

bool desc(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int depth, n, pizza[MAX], low, high, mid;
    pair<int, int> oven[MAX]; //반지름, 깊이 인덱스
    cin >> depth >> n;
    oven[0] = {INT_MAX, 0};
    for (int i = 1; i <= depth; i++)
    {
        cin >> oven[i].first;
        oven[i].second = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pizza[i];
    }

    sort(oven, oven + depth + 1, desc);

    int last_radius_index = depth + 1;
    int radius = 0;
    int last_depth = depth + 1;
    int result;
    for (int i = 0; i <= depth; i++)
    {
        // cout << "radius: " << oven[i].first << ", depth(index): " << oven[i].second << endl;
    }
    for (int i = 0; i < n; i++)
    {
        radius = pizza[i];
        low = 0;
        high = last_radius_index - 1;
        //내림차순 배열에서 이진탐색
        //반복문 불변식 low < high, a[low] < x < a[high]
        // cout << "pizza radius: " << radius << endl;
        while (low <= high)
        {
            mid = (low + high) / 2;
            // cout << " r[mid]: " << oven[mid].first << " depth[mid]: " << oven[mid].second << " mid 갱신: " << mid << " low: " << low << " high: " << high << endl;
            if (oven[mid].first >= radius)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        // cout << " r[mid]: " << oven[mid].first << " depth[mid]: " << oven[mid].second << " mid 갱신: " << mid << " low: " << low << " high: " << high << endl;
        if (last_radius_index == low)
        {
            //안걸린경우
            last_radius_index -= 1;
            result = last_depth - 1;
            if (result <= 0)
            {
                cout << 0;
                return 0;
            }
            last_depth = last_depth - 1;
            // cout << "쌓였음. 쌓인 위치: " << result << endl;
        }
        else
        {
            //걸린경우
            last_radius_index = low; //oven[low].second - 1;
            result = oven[last_radius_index].second - 1;
            // cout << "걸렸음. 걸린 위치: " << result << endl;
            last_depth = oven[last_radius_index].second - 1;
        }
    }
    cout << result << endl;
    return 0;
}

/*legacy



*/
//2	18556034	2	skykimjh	1112	0	C++	955	1달 전
/*queue자료구조 대신 직접 배열에서 tail, head 증가시켜 가며 사용
(큐에 들어가는 원소 개수가 최대 10000개로 제한되어 있으므로
BFS를 customize하여 한 반복에서 큐에 들어 있는 모든 노드 확장
반복 단위별로 step_cnt를 늘릴 수 있음*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 102

using namespace std;

/* 문제 정의
NxM 0/1배열 -> 경로
 */

/* 해결 알고리즘 생각
BFS
arr[M+2][N+2]*/

typedef struct
{
    int y;
    int x;
} Point;

char map[101][102];

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, hd = 0, tl = 0, st = 0, go = 1;

    Point Q[10000];

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> map[i] + 1;

    Q[hd++] = {1, 1};
    map[1][1] = 0;

    while (go)
    {
        // 큐의 모든 내용물 꺼내는 것을 한 작업으로
        int sz = hd - tl, y, x;
        Point p;
        st++;

        for (int i = 0; i < sz; i++)
        {
            //hd = head, tl = tail;
            p = Q[tl++]; //pop
            y = p.y, x = p.x;
            if (y == n && x == m)
            {
                go = 0;
                break;
            }

            int dy[] = {-1, 0, 0, 1};
            int dx[] = {0, -1, 1, 0};
            for (int j = 0; j < 4; j++) //pushes
            {
                if (map[y + dy[j]][x + dx[j]] == '1')
                {
                    map[y + dy[j]][x + dx[j]] = '0'; //visited 대신 기존 map을 0으로
                    Q[hd++] = {y + dy[j], x + dx[j]};
                }
            }
        }
    }
    ///////////
    cout << st;
    return 0;
}

/*legacy



*/
//오랜 시간 소요: 배열 크기 여유분!, M행 N열 헷갈리지 않기!!
//M행N열 for (y = 0 to M)
//          for (x = 0 to N)

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 1010

using namespace std;

/* 문제 정의
토마토 2차원배열 -> 토마토가 모두 익을 때까지 최소 날짜
M,N <= 10^3
 */

/* 해결 알고리즘 생각
방법1.
하나를 기준 bfs -> 결과 arr[i][j] = day
또다른 토마토 기준 bfs -> arr2[i][j] = day
...
원본에 토마토 X -> arr[i][j] 최솟값
arr 전체에 대한 최대 day

방법2.
동시에 bfs
한 day마다 전체 상자 훑고 visit배열에 day 기록
*/

int box[MAX][MAX], visit[MAX][MAX], current_day, max_day = 0;
int dj[4] = {0, -1, 1, 0};
int di[4] = {-1, 0, 0, 1};
typedef pair<int, int> pii;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int m, n, i, j;
    fill(&visit[0][0], &visit[MAX - 1][MAX - 1], -1);

    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> box[i][j];
        }
    }
    queue<pii> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (box[i][j] == 1)
            {
                // cout << "TEST";
                q.push({i, j});
                visit[i][j] = 0; //day 0에 익은 토마토들.
            }
        }
    }
    while (!q.empty()) //bfs(큐가 빌 때까지)
    {
        //큐에서 토마토 하나를 꺼내서
        //  cur = visit[];
        //  인접한 토마토에 대해
        //      처음 방문일 경우 visit 배열을 cur+1로 하고 큐에 넣기
        pii tomato = q.front();
        q.pop();
        current_day = visit[tomato.first][tomato.second];
        // cout << '(' << tomato.first << ',' << tomato.second << ")-" << current_day;
        for (int k = 0; k < 4; k++)
        {
            i = tomato.first + di[k];
            j = tomato.second + dj[k];
            if (i < 1 || i > n || j < 1 || j > m || box[i][j] == -1 || visit[i][j] != -1)
                continue;
            visit[i][j] = current_day + 1;
            q.push({i, j});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // cout << visit[i][j] << ' ';
            if (visit[i][j] == -1 && box[i][j] != -1)
            {
                cout << -1;
                return 0;
            }
            max_day = max(max_day, visit[i][j]);
        }
        // cout << endl;
    }
    cout << max_day;
    return 0;
}
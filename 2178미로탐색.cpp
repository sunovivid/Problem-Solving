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
arr[M+2][N+2]


def BFS():
    q = 0,0
    cnt = 0
    while (!q.empty())
        cur = q.pop 
        goal_test       
        if visited[cur]
            continue
        step_cnt = visited[cur]
        cnt++
        for i = 0 to 4
            q.push(인접노드)
            visited[인접노드] = step_cnt + 1
*/

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    char arr[MAX][MAX];
    int visited[MAX][MAX], n, m, step_cnt;

    fill(&arr[0][0], &arr[MAX - 1][MAX], '0');
    fill(&visited[0][0], &visited[MAX - 1][MAX], -1); //MAX-1행의 MAX열까지

    cin >> n >> m;
    for (int y = 1; y <= n; y++)
    {
        cin >> &arr[y][1];
    }

    ///////////

    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = 1;
    int dy[] = {-1, 0, 0, 1};
    int dx[] = {0, -1, 1, 0};
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int y = cur.first, x = cur.second;
        step_cnt = visited[y][x];
        if (y == n && x == m)
            break;
        for (int i = 0; i < 4; i++)
        {
            if (arr[y][x] == '1' && visited[y + dy[i]][x + dx[i]] == -1)
            {
                visited[y + dy[i]][x + dx[i]] = step_cnt + 1;
                q.push({y + dy[i], x + dx[i]});
            }
        }
    }

    cout << step_cnt;

    ///////////

    return 0;
}

/*legacy



*/
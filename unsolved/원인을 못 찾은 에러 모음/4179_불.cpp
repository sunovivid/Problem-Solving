/*
    memset(visited, 0, sizeof(visited));
    memset(firemap, 0, sizeof(firemap));
    fill(&map[0][0], &map[MAX - 1][MAX], 'C'); :segfault

    // memset(visited, 0, sizeof(visited));
    // memset(firemap, 0, sizeof(firemap));
    fill(&map[0][0], &map[MAX - 1][MAX], 'C'); :에러 없음

    특정 조합에서만 에러가 발생한다. fill의 문제인 듯 한데 왜일까?

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

#define MAX 1002

using namespace std;

typedef struct
{
    int y;
    int x;
} Point;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int r, c;
    char map[MAX][MAX];
    int firemap[MAX][MAX];
    int visited[MAX][MAX];
    // memset(visited, 0, sizeof(visited));
    // memset(firemap, 0, sizeof(firemap));
    fill(&map[0][0], &map[MAX - 1][MAX], 'C');
    // fill(&firemap[0][0], &firemap[MAX - 1][MAX], 0);
    // fill(&visited[0][0], &visited[MAX - 1][MAX], 0);
    // fill(&visited[0][0], &visited[MAX - 1][MAX], 0);
    Point start,
        fire;

    // cin >> r >> c;
    // for (int i = 1; i <= r; i++)
    //     cin >> map[i][1];

    // for (int i = 1; i <= r; i++)
    //     for (int j = 1; j <= c; j++)
    //         if (map[i][j] == 'J')
    //             Point start = {i, j};
    //         else if (map[i][j] == 'F')
    //         {
    //             Point fire = {i, j};
    //         }

    // queue<Point> q; //fire queue
    // q.push(fire);
    // while (!q.empty())
    // {
    //     Point cur = q.front();
    //     q.pop();
    //     int x = cur.x, y = cur.y;
    //     if (map[y][x] == '#' || map[y][x] == 'C' || firemap[y][x] > 0)
    //         continue;
    //     int day = firemap[y][x];
    //     int dx[] = {-1, 0, 0, 1};
    //     int dy[] = {0, -1, 1, 0};
    //     for (int i = 0; i < 4; i++)
    //     {
    //         if (map[y + dy[i]][x + dx[i]] == '.')
    //         {
    //             firemap[y + dy[i]][x + dx[i]] = day + 1;
    //             q.push({y + dy[i], x + dx[i]});
    //         }
    //     }
    // }
    // queue<Point> q2;
    // q2.push(start);
    // while (!q2.empty())
    // {
    //     Point cur = q2.front();
    //     q2.pop();
    //     int x = cur.x, y = cur.y;
    //     int day = visited[y][x];
    //     if (map[y][x] == 'C')
    //     {
    //         cout << day;
    //         return 0;
    //     }
    //     if (map[y][x] == '#' || day >= firemap[y][x])
    //         continue;
    //     int dx[] = {-1, 0, 0, 1};
    //     int dy[] = {0, -1, 1, 0};
    //     for (int i = 0; i < 4; i++)
    //     {
    //         if (visited[y + dy[i]][x + dx[i]] == 0)
    //         {
    //             q2.push({y + dy[i], x + dx[i]});
    //             visited[y + dy[i]][x + dx[i]] = day + 1;
    //         }
    //     }
    // }
    // cout << "IMPOSSIBLE";
    return 0;
}

/*legacy



*/
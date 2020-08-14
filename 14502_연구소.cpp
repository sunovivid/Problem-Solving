#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 11
#define WALLNUM 3

using namespace std;

/* 문제 정의
0,1,2 로 이루어진 2차원 배열 -> 안전 영역 크기의 최댓값
안전 영역: 바이러스가 퍼지지 않는 영역 */

/* 해결 알고리즘 생각
n,m<=8이고 벽 3개를 반드시 세워야 하므로, 가능한 벽을 세우는 가짓수 64C3
각 가지수당 bfs해서 안전 영역 넓이 구하는 시간 NM + 4NM = 5NM = 5*64
완탐으로 가능
*/

/* 시간복잡도

*/
typedef struct
{
    int y;
    int x;
} Vec2;

int n, m, safeZoneCnt = 0, maxSafeZoneCnt = 0;
int map[MAX][MAX];
queue<Vec2> dangerZones;

int spread(queue<Vec2> q)
{
    int visit[MAX][MAX];
    memset(visit, false, sizeof(visit));
    int safeZoneCntLocal = safeZoneCnt;
    while (!q.empty())
    {
        Vec2 cur = q.front();
        q.pop();
        // cout << "cur: " << cur.y << cur.x << endl;
        for (int i = 0; i < 4; i++)
        {
            int dy = "2101"[i] - '1', dx = "1210"[i] - '1';
            // cout << dy << dx << endl;
            if (map[cur.y + dy][cur.x + dx] != 0 || visit[cur.y + dy][cur.x + dx])
                continue;
            visit[cur.y + dy][cur.x + dx] = true;
            safeZoneCntLocal--;
            q.push({cur.y + dy, cur.x + dx});
        }
    }
    // cout << safeZoneCntLocal << '\n';
    return safeZoneCntLocal;
}

void makeWall(int index)
{
    if (index == WALLNUM)
    {
        maxSafeZoneCnt = max(maxSafeZoneCnt, spread(dangerZones));
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (map[i][j] == 0)
            {
                map[i][j] = 1;
                safeZoneCnt--;
                // for (int k = 0; k < index; k++)
                // cout << "  ";
                // cout << "makeWall at " << i << ' ' << j << endl;
                makeWall(index + 1);
                map[i][j] = 0;
                safeZoneCnt++;
            }
        }
    }
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    fill(&map[0][0], &map[MAX - 1][MAX], 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 0)
                safeZoneCnt++;
            else if (map[i][j] == 2)
                dangerZones.push({i, j});
        }
    ///////////////////solution//////////////////
    makeWall(0);
    cout << maxSafeZoneCnt;
    ////////////////////output///////////////////

    return 0;
}
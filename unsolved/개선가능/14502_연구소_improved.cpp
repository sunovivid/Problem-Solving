//왜 #1 부분이 <=여야 하는지 모르겠음
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

수정1
    inline => 10ms감소

정답 보고 개선1
    기둥 생성할 때 순서 강제 안하고 나머지 선택을 2중 for문으로 해서 중복 케이스 계속 검사함
    오른쪽 아래 y,x만 확인하면 됨
    for문 쓰지 않고 index안 높이고 makeWall 추가로 호출하는 테크닉 씀
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

inline int spread(queue<Vec2> q)
{
    // cout << "///////" << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //         cout << map[i][j] << ' ';
    //     cout << endl;
    // }

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
            int ny = cur.y + dy, nx = cur.x + dx;
            // cout << dy << dx << endl;
            if (map[ny][nx] != 0 || visit[ny][nx])
                continue;
            visit[ny][nx] = true;
            safeZoneCntLocal--;
            q.push({ny, nx});
        }
    }
    // for (int i = 0; i <= n + 1; i++)
    // {
    //     for (int j = 0; j <= m + 1; j++)
    //         cout << visit[i][j] << ' ';
    //     cout << endl;
    // }
    // cout << safeZoneCntLocal << '\n';
    return safeZoneCntLocal;
}

void makeWall(int y, int x, int index)
{
    if (index == WALLNUM)
    {
        maxSafeZoneCnt = max(maxSafeZoneCnt, spread(dangerZones));
        return;
    }

    if (y > m)
        return;

    if (map[y][x] == 0) //빈칸이면
    {
        map[y][x] = 1;
        safeZoneCnt--;
        if (x < m) //두고 다음 확인할 곳 체크 //#1
            makeWall(y, x + 1, index + 1);
        else
            makeWall(y + 1, 1, index + 1); //같은 실수 반복
        map[y][x] = 0;
        safeZoneCnt++;
    }
    /**
     * 구현 테크닉: 다음 확인할 곳 for문으로 돌리는 게 아니라 
     * '두면서 호출(index++)'과 '두지 않고 호출(index그대로)'을 사용
     * '두지 않고 호출'이 for문 대신 체크하는 역할 수행
     * */
    if (x < m) //이거 틀려서 1시간
        makeWall(y, x + 1, index);
    else
        makeWall(y + 1, 1, index); //1로 x 초기화 안하는 실수
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
    makeWall(1, 0, 0); //구현 테크닉: 바깥에서 확인 안하는법 - 함수에서 '두기' 확정이 아니라 '체크 후 두기'

    cout << maxSafeZoneCnt;
    ////////////////////output///////////////////

    return 0;
}
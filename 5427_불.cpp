#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

#define MAX 1050

using namespace std;

/* 문제 정의
시간에 따라 변하는 2차원 map -> 탈출 경로
 */

/* 해결 알고리즘 생각
BFS

불 확장 -> 지훈 BFS 번갈아가며 수행

BFS 하나만 생각할때
    문제 형식화
        상태: 플레이어 위치 + 변경된 map 보드
        초기 상태 - 주어짐
        액션 - ., C는 방문가능 (#, F는 방문 불가능)
        전이 모형 - 플레이어 위치 변경, 불 한단계 확장해서 map 변경
        골 테스트 - C에 방문

    q_p = 플레이어 상태, map
    while (!q_p.empty())
        q_p.pop()
        자식 노드 생성
            각 노드별로 goal / visit test
            확장

동시에 할때
    불과 플레이어의 방문 레벨을 기록
    goal까지 플레이어의 방문 레벨이 더 작은 경로가 존재하면 됨
    
    먼저 플레이어 bfs
    골 도달 레벨 기록
    해당 레벨까지만 불 bfs 수행
    플레이어 경로 퇴각하며 불 레벨보다 크거나 같은 레벨 있나 검사 
    있으면 불가능!

    => 상태노드 단위 반복은 굉장히 귀찮다..

동시에 할때 (레벨단위반복)
    while (true)
        불 1레벨 확장()
        진수 1레벨 확장()

진수 확장()
    확장 불가능하면 IMPOSSIBLE 출력
    골 발견하면 레벨 출력
*/

typedef struct
{
    int y;
    int x;
} Point;

char map[MAX][MAX];
bool visited_f[MAX][MAX] = {false,};
bool visited_p[MAX][MAX] = {false,};

void solve_case() {
    //init
    int r, c;
    Point start;
    vector<Point> fire;
    memset(visited_f, 0, sizeof(visited_f));
    memset(visited_p, 0, sizeof(visited_p));
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
        {
            map[i][j] = 'G';
        }

    //input
    cin >> c >> r;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> map[i][j];
            if (map[i][j] == '@')
                start = {i, j};
            else if (map[i][j] == '*')
                fire.push_back({i, j});
        }
        //map[i][r+1] = 'G'; // null character replace필요? => 필요없음
    }

    //bfs
    queue<Point> q_p, q_f; //player queue, fire queue
    q_p.push(start);
    for (auto f: fire)
        q_f.push(f);
    int level = 0;
    while (true)
    {
        //spread fire
        int q_size = q_f.size();
        while (q_size--) {
            Point cur = q_f.front();
            q_f.pop();

            //test & expand
            for (int i = 0; i < 4; i++) {
                int x = cur.x + (int)"2101"[i] - (int)'1', y = cur.y + (int)"1012"[i] - (int)'1';
                // cout << "DWAS"[i] << " " << x << " " << y << endl;
                if (!visited_f[y][x] && map[y][x] == '.') {
                    // cout << "expanded!" << endl;
                    visited_f[y][x] = true;
                    q_f.push({y,x});
                    map[y][x] = '*';
                }
            }
        }

        // //map test
        // for (int i = 0; i < 6;i++) {
        //     for (int j = 0; j < 6;j++) {
        //         cout << map[i][j];
        //     }
        //     cout << endl;
        // }

        //spread jinsu
        level++;
        q_size = q_p.size();
        while (q_size--) {
            Point cur = q_p.front();
            q_p.pop();

            //test & expand
            for (int i = 0; i < 4; i++) {
                int x = cur.x + (int)"2101"[i] - (int)'1', y = cur.y + (int)"1012"[i] - (int)'1';
                if (!visited_p[y][x] && (map[y][x] == '.' || map[y][x] == 'G')) {
                    if (map[y][x] == 'G') {
                        cout << level << '\n';
                        return;
                    }
                    visited_p[y][x] = true;
                    q_p.push({y,x});
                }
            }
        }

        if (q_p.empty()) {
            cout << "IMPOSSIBLE" << '\n';
            return;
        }
    }
}

int main()
{
    //input
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve_case();
    }
    return 0;
}

/*legacy



*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 1010

using namespace std;

/* 문제 정의
2차원 배열 (원소=. or 1~9) -> 상태 수렴까지 걸리는 시간
상태: 매 파도마다 [각 모래성의 튼튼함 <= 주변8칸 . 개수]이면 해당 모래성은 쓰러짐
 */

/* 해결 알고리즘 생각
O((HW)^2) 매 파도마다 HW개를 전부 체크해서 쓰러짐 확인하는 경우
O(HW + HW*8) 처음 파도에 HW개를 전부 체크하고, 이후부터는 쓰러진 모래성 주변의 모래성만 확인하는 경우
    (수학적 귀납법! 이전 상태와 같으면 쓰러지지 않음이 보장되므로)
*/

int map[MAX][MAX];
bool visited[MAX][MAX];

typedef struct {
    int y;
    int x;
} Point;

queue<Point> q;

void solve(int h, int w) { //argument: h, w, map(global) 
    //first search
        //속도를 위해 input에서 처리

    //bfs until converge
    int wave_count = 0;
    while (true) {
        // cout << "Wave " << wave_count << endl;
        bool is_something_deleted = false;
        memset(visited, 0, sizeof(visited));
        // 큐에서 전체 원소를 꺼내서 삭제해야 하는지 체크하고 map 변형하고 무너진 모래성 주변 체크목록에 추가
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            Point check_spot = q.front();
            q.pop();

            // cout << "    Check " << check_spot.y << check_spot.x << endl;
            int count = 0;
            for (int dy = -1; dy <= 1; dy++)
                for (int dx = -1; dx <= 1; dx++)
                    if (/*자기 자신 제외?*/map[check_spot.y + dy][check_spot.x + dx] == 0)
                        count++;
            if (count >= map[check_spot.y][check_spot.x]) {
                // cout << "        Delete " << check_spot.y << check_spot.x << endl;
                is_something_deleted = true;
                map[check_spot.y][check_spot.x] = 0;
                for (int dy = -1; dy <= 1; dy++)
                    for (int dx = -1; dx <= 1; dx++)
                        if (!visited[check_spot.y + dy][check_spot.x + dx] && !(dx == 0 && dy == 0) && map[check_spot.y + dy][check_spot.x + dx] != 0) {
                            visited[check_spot.y + dy][check_spot.x + dx] = true;
                            q.push({check_spot.y + dy, check_spot.x + dx});
                        }
            }
        }
        // 삭제할 원소가 없으면 (count로 체크) wave count 출력
        if (!is_something_deleted) {
            cout << wave_count;
            return;
        }
        wave_count++;
    }
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    char temp;
    memset(map, 0, sizeof(map));
    for (int i = 1; i <= h;i++){
        for (int j = 1; j <= w;j++) {
            cin >> temp;
            if (temp == '.')
                map[i][j] = 0;
            else {   
                map[i][j] = temp - '0';
                q.push({i, j}); //미리 처리
            }
    
        }
    }
    ///////////////////solution//////////////////
    solve(h, w);
    ////////////////////output///////////////////

    return 0;
}

/*legacy



*/
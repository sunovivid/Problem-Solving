#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 1005

using namespace std;

/* 문제 정의
MAP (살인 도구, 피해자, 용의자 5명, 구조물) -> (용의자-살인도구-피해자-용의자) 경로의 최솟값
 */

/* 해결 알고리즘 생각
흉기에서 각 용의자까지 BFS + 피해자에서 각 용의자까지 BFS
*/

/* 시간복잡도
V = 10^6
O(5(V + 2V))
*/

typedef struct {
    int y;
    int x;
} Point;

int map[MAX][MAX];
bool visited[MAX][MAX];

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, path_cost[5];
    Point corpse, knife;
    memset(path_cost, 0, sizeof(path_cost));
    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));
    cin >> n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> map[i][j];
            if (map[i][j] == 3)
                corpse = {i,j};
            else if (map[i][j] == 4)
                knife = {i,j};
        }
    }
    ///////////////////solution//////////////////
    //흉기 -> 각 용의자까지 BFS
    queue<Point> q;
    q.push(knife);
    int level = 0;
    while (true) {
        level++;
        int qsize = q.size();
        if (qsize == 0)
            break;
        while (qsize--) {
            Point cur = q.front();
            q.pop();
            for (int i=0;i<4;i++) {
                int y = cur.y + "1210"[i] - '1';
                int x = cur.x + "2101"[i] - '1';
                if (!visited[y][x] && map[y][x] != 0) {
                    visited[y][x] = true;
                    if (map[y][x] >= 5)
                        path_cost[map[y][x]-5] = level;
                    q.push({y,x});
                }
            }
        }
    }
    //피해자 -> 각 용의자까지 BFS
    assert(q.size() == 0);
    q.push(corpse);
    level = 0;
    memset(visited, 0, sizeof(visited));
    while (true) {
        level++;
        int qsize = q.size();
        if (qsize == 0)
            break;
        while (qsize--) {
            Point cur = q.front();
            q.pop();
            for (int i=0;i<4;i++) {
                int y = cur.y + "1210"[i] - '1';
                int x = cur.x + "2101"[i] - '1';
                if (!visited[y][x] && map[y][x] != 0) {
                    visited[y][x] = true;
                    if (map[y][x] >= 5)
                        path_cost[map[y][x]-5] += level;
                    q.push({y,x});
                }
            }
        }
    }
    int result, min = 987654321;
    for (int i=0;i<5;i++) {
        if (path_cost[i] < min) {
            min = path_cost[i];
            result = i;
        }
    }
    ////////////////////output///////////////////
    //두 최단거리 합의 최소가 되는 용의자 구하기
    cout << result + 5;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 110
#define ON 1
#define OFF 0
#define PADDING 1

using namespace std;

/* 문제 정의
 ->
 */

/* 해결 알고리즘 생각

*/
typedef struct {
    int x;
    int y;
    int dir;
    int level;
} State;

bool map[MAX][MAX];

bool goal_test(State s, State goal) {
    return (s.x == goal.x && s.y == goal.y && s.dir == goal.dir);
}

void solve(State start, State goal) {
    if (goal_test(start, goal)) {
        cout << 0;
        return;
    }

    //init
    bool visit[MAX][MAX][4];
    memset(visit, 0, sizeof(visit));

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    queue<State> q;
    q.push(start);

    while (!q.empty()) {
        State cur = q.front();
        // cout << cur.y + 1 - PADDING<< ' ' << cur.x + 1 - PADDING << ' ' << cur.dir + 1 << ' ' << cur.level << endl;
        q.pop();

        //generate children
        vector<State> children;
        //Go
        for (int i=1;i<=3;i++) {
            // cout << i << ' ' << map[cur.y + dy[cur.dir] * i][cur.x + dx[cur.dir] * i] << endl;
            if (map[cur.y + dy[cur.dir] * i][cur.x + dx[cur.dir] * i] == OFF)
                break;
            children.push_back({cur.x + dx[cur.dir] * i, cur.y + dy[cur.dir] * i, cur.dir, -1});
        }
        //Turn left
        children.push_back({cur.x, cur.y, (int)"4312"[cur.dir] - (int)'1', cur.level + 1});
        //Turn right
        children.push_back({cur.x, cur.y, (int)"3421"[cur.dir] - (int)'1', cur.level + 1});

        for (auto child: children) {
            child.level = cur.level + 1;
            // cout << "   " << child.y + 1 - PADDING<< ' ' << child.x + 1 - PADDING << ' ' << child.dir + 1 << endl;

            //test
            if (visit[child.x][child.y][child.dir] || map[cur.y][cur.x] == OFF)
                continue;
            if (goal_test(child, goal)) {
                cout << child.level;
                return;
            }

            //expand
            visit[child.x][child.y][child.dir] = true;
            q.push(child);
        }
    }
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int m, n;
    cin >> m >> n;
    memset(map, OFF, sizeof(map));
    int temp;
    for (int i = PADDING; i < m + PADDING; i++) {
        for (int j = PADDING; j < n + PADDING; j++) {
            cin >> temp;
            map[i][j] = temp ? OFF : ON; //입력 0 = ON, 1 = OFF
        }
    }
    int y, x, dir;
    cin >> y >> x >> dir;
    State start = {x - 1 + PADDING, y - 1 + PADDING, dir-1, 0}; //dir 0123 save
    cin >> y >> x >> dir;
    State goal = {x - 1 + PADDING, y - 1 + PADDING, dir-1, 0};

    /////////////////////solution//////////////////
    solve(start, goal);
    //////////////////////output///////////////////

    return 0;
}

/*legacy



*/
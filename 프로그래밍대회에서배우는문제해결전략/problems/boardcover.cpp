#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 22

using namespace std;

/* 문제 정의
#,.으로 이루어진 2차원 배열 -> ㄱ자 블럭으로 보드칸을 덮는 방법의 수
 */

/* 해결 알고리즘 생각
완전탐색 4^(50//3) = 4^16 = 2^32나 실제로는 훨씬 작음

맨 왼쪽 위부터 확인하도록 순서 강제했으면 그 방법으로 모든 놓는 방식이 가능해야 함
coverType블럭을 ㄱ자의 중심을 기준으로 하면 안되고, 왼쪽 위를 기준으로 구성해야 함ㅛ
*/

/* 시간복잡도

*/
const int coverType[4][3][2] = {
    {{0, 0}, {1, 0}, {0, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}}};

bool set(char map[][MAX], const int h, const int w, int firstY, int firstX, int type, int delta) //존재 여부를 확인하고 종료하는 게 아니라 +1/-1함으로써 복구 가능하게
{
    bool isPlacable = true;
    for (int i = 0; i < 3; i++)
    {
        const int ny = firstY + coverType[type][i][0];
        const int nx = firstX + coverType[type][i][1];
        if (ny < 0 || ny >= h || nx < 0 || nx >= w)
            isPlacable = false;
        if ((map[ny][nx] += delta) != '.' + delta) //범위 벗어나는거 체크 후 배열 확인
            isPlacable = false;
    }
    return isPlacable;
}

int cover(char map[][MAX], const int h, const int w)
{
    int firstY = -1, firstX = -1;
    [&] {
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (map[i][j] == '.')
                {
                    firstY = i;
                    firstX = j;
                    return;
                }
            }
        }
    }();

    if (firstY == -1)
    {
        return 1;
    }

    int ret = 0;
    for (int type = 0; type < 4; type++)
    {
        if (set(map, h, w, firstY, firstX, type, +1))
        {
            ret += cover(map, h, w);
        }
        set(map, h, w, firstY, firstX, type, -1);
    }
    return ret;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int c;
    cin >> c;
    ///////////////////solution//////////////////
    while (c--)
    {
        //input
        int h, w;
        cin >> h >> w;
        char map[MAX][MAX];
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> map[i][j];
        //solve
        int emptySpaceCount = 0;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (map[i][j] == '.')
                    emptySpaceCount++;
        if (emptySpaceCount % 3 != 0)
        {
            cout << 0 << endl;
            continue;
        }
        cout << cover(map, h, w) << endl;
    }
    ////////////////////output///////////////////

    return 0;
}
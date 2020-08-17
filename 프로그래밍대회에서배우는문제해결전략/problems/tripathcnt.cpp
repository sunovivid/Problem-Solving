#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 101

using namespace std;

/* 문제 정의
자연수 삼각수열 -> 최대합 경로의 수 
 */

/* 해결 알고리즘 생각
최대합 경로 구하기
path(y,x) = max(path(y+1,x), path(y+1,x+1)) + map[y][x]
최대합 경로의 수 구하기
count(y,x)=max(count(y+1,x),count(y+1,x+1),count(y+1,x)+count(y+1,x+1)(only if two terms are same))
*/

/* 시간복잡도

*/
vector<vector<int>> map;

int dpPath[MAX][MAX];
int dpCount[MAX][MAX];

int path(const int y, const int x)
{
    if (y == map.size())
        return 0;
    int &ret = dpPath[y][x];
    if (ret != -1)
        return ret;
    return ret = max(path(y + 1, x), path(y + 1, x + 1)) + map[y][x];
}

int count(const int y, const int x)
{
    if (y == map.size() - 1) //마지막 라인에서 출발해서 마지막 라인에 도달하는 경우의 수: 무조건 1
        return 1;
    int &ret = dpCount[y][x];
    if (ret != -1)
        return ret;
    ret = 0;
    int countOfDown = count(y + 1, x);
    int countOfDiagonal = count(y + 1, x + 1);
    if (path(y + 1, x) == path(y + 1, x + 1))
        return ret = countOfDown + countOfDiagonal;
    return ret = path(y + 1, x) > path(y + 1, x + 1) ? countOfDown : countOfDiagonal;
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
        int n;
        cin >> n;
        map.clear();
        for (int i = 0; i < n; i++)
        {
            vector<int> x;
            map.push_back(x);
            for (int j = 0; j < i + 1; j++)
            {
                int x;
                cin >> x;
                map[i].push_back(x);
            }
        }
        memset(dpPath, -1, sizeof(dpPath));
        memset(dpCount, -1, sizeof(dpCount));
        // cout << path(0, 0) << endl;
        cout << count(0, 0) << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < i + 1; j++)
        //         cout << dpCount[i][j] << ' ';
        //     cout << endl;
        // }
    }
    ////////////////////output///////////////////

    return 0;
}
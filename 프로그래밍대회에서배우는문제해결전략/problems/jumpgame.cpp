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
2차원 자연수 배열 -> 시작점-끝점 도달가능여부
 */

/* 해결 알고리즘 생각
dp[x,y] = x,y에서 목표에 도달할 수 있는지 여부
*/

/* 시간복잡도

*/
int n;
int dp[MAX][MAX], map[MAX][MAX];

int isReachableToGoal(int y, int x)
{
    //base case 처리
    if (x >= n || y >= n)
        return false;
    if (y == n - 1 && x == n - 1)
        return true;
    //메모이제이션
    int &ret = dp[y][x];
    if (ret != -1)
        return ret;
    return ret = isReachableToGoal(y + map[y][x], x) || isReachableToGoal(y, x + map[y][x]);
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
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> map[i][j];
        memset(dp, -1, sizeof(dp));
        cout << (isReachableToGoal(0, 0) ? "YES" : "NO") << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}
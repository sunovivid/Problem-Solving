#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 12

using namespace std;

/* 문제 정의
학생 수 n, 친구 정수 쌍 m개 -> 친구끼리 짝짓는 방법의 수
 */

/* 해결 알고리즘 생각
최대 10명, 최대 45쌍 검사 -> 완탐으로 가능
모든 경우 검사하면서 친구인지 확인 (2차원 배열)
*/

/* 시간복잡도

*/
int countParings(int n, bool taken[], bool areFriends[][MAX])
{
    int firstFree = -1;
    for (int i = 0; i < n; i++) 
    
    {
        if (!taken[i])
        {
            firstFree = i;
            break;
        }
    }

    //모두 taken이 true인 경우 모두 짝이 지어졌으므로 return 1
    if (firstFree == -1)
        return 1;

    //아닐 경우 짝 짓기
    int ret = 0;

    for (int j = firstFree + 1; j < n; j++)
    {
        if (!taken[firstFree] && !taken[j] && areFriends[firstFree][j])
        {
            taken[firstFree] = taken[j] = true;
            ret += countParings(n, taken, areFriends);
            taken[firstFree] = taken[j] = false;
        }
    }

    return ret;
}

void solve(int n, bool areFriends[][MAX])
{
    bool taken[MAX];
    memset(taken, false, sizeof(taken));
    cout << countParings(n, taken, areFriends) << '\n';
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
        int n, m;
        cin >> n >> m;
        bool areFriends[MAX][MAX];
        memset(areFriends, false, sizeof(areFriends));
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            areFriends[a][b] = true;
            areFriends[b][a] = true;
        }
        solve(n, areFriends);
    }
    ////////////////////output///////////////////

    return 0;
}
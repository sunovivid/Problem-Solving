#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 1003

using namespace std;

/* 문제 정의
정수 2차원 배열
-> 맨 왼쪽 위에서 오른쪽,아래,오른쪽 아래 대각선으로만 이동할 때 경로상 수열 합의 최댓값
 */

/* 해결 알고리즘 생각
dp[i][j] = (i,j까지 경로 수열 합 최대)
dp[i][j] = max(dp[i][j-1], dp[i-1][j], dp[i][j]) + arr[i][j]

개선1
    dp정보 라인 하나만 유지하면 ok
    사탕의 개수가 0 이상이므로 대각선으로 이동하는 것보다 위, 오른쪽을 경유하는 경로가 무조건 이득 (혹은 같음)
*/

/* 시간복잡도
O(nm)
*/

int dp[MAX] = {0,};

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    while (n--)
        for (int j=0;j<m;j++) {
            int temp;
            cin >> temp;
            dp[j+1] = max(dp[j+1], dp[j]) + temp;
        }
    ///////////////////solution//////////////////
    cout << dp[m];
    ////////////////////output///////////////////

    return 0;
}
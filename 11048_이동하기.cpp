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
*/

/* 시간복잡도
O(nm)
*/

int dp[MAX][MAX] = {0,};

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) {
            cin >> dp[i+1][j+1];
            dp[i+1][j+1] += max({dp[i][j+1], dp[i+1][j], dp[i][j]});
        }
    ///////////////////solution//////////////////
    cout << dp[n][m];
    ////////////////////output///////////////////

    return 0;
}
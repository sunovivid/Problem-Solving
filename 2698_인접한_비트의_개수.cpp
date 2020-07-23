#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX

using namespace std;

/* 문제 정의
쿼리 t개
    자연수 n, k -> 길이 n, 인접한 비트 수 k인 0, 1로 이루어진 수열의 개수
    인접한 비트 수: 인접한 11쌍의 개수
        ex) 011101101: 3
 */

/* 해결 알고리즘 생각
    dp[i][j][k] = (길이 i이고 인접한 비트가 j개, 마지막 비트가 k인 수열의 개수)
    dp[1][0][0] = 1
    dp[1][0][1] = 1
    for i = 1 to n
        for j = 0 to i-1
            dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1]
            dp[i][j][1] = dp[i-1][j][0] + dp[i-1][j-1][1]
*/

/* 시간복잡도
O(n^2)
*/

int dp[105][104][2];

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    ///////////////////solution//////////////////
    dp[1][0][0] = dp[1][0][1] = 1;
    for (int i=2;i<=100;i++) {
        for (int j=0;j<i;j++) {
            dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
            dp[i][j][1] = dp[i-1][j][0] + (j >= 1 ? dp[i-1][j-1][1] : 0);
        }
    }
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << dp[n][k][0] + dp[n][k][1] << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}
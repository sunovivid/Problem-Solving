#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 302

using namespace std;

/* 문제 정의
정수 배열, 쿼리(직사각형)-> 부분합
 */

/* 해결 알고리즘 생각
for i = 1 to n 
    for j = 1 to m
        dp[i][j] = d[[i-1][j] + dp[i][j-1] - dp[i-1][j-1]
*/

/* 시간복잡도
O(NM)
*/

int dp[MAX][MAX] = {0, };

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> dp[i+1][j+1];
            dp[i+1][j+1] += dp[i][j+1] + dp[i+1][j] - dp[i][j];
        }
    }
    ///////////////////solution//////////////////
    //query
    int k;
    cin >> k;
    while (k--) {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        cout << dp[i2][j2] - dp[i2][j1-1] - dp[i1-1][j2] + dp[i1-1][j1-1] << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}
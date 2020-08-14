#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 1010

using namespace std;

/* 문제 정의
집 N개, 각 색의 비용 -> 인접한 집 색을 다르게 칠하는 최소 비용
 */

/* 해결 알고리즘 생각
dp[i][j] = (i번째 집을 j로 색칠했을 때의 최소 비용)
dp[0][j] = cost_of_color[j];
for j=0 to 2
    dp[n][j] = min(dp[n-1][(j+1)%3], dp[n-1][(j+2)%3]) + cost_of_color[j];
*/

int main() {
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, cost_of_color[3], min_cost, dp[MAX][3];
    cin >> n;
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    ///////////////////solution//////////////////
    for (int k = 1; k <= n; k++) {
        cin >> cost_of_color[0] >> cost_of_color[1] >> cost_of_color[2];
        for (int c=0;c<3;c++) {
            dp[k][c] = min(dp[k-1][(c+1)%3], dp[k-1][(c+2)%3]) + cost_of_color[c];
        }
    }
    ////////////////////output///////////////////
    // cout << min(dp[n][0], dp[n][1], dp[n][2]);
    cout << min({dp[n][0], dp[n][1], dp[n][2]});
    return 0;
}

/*legacy



*/
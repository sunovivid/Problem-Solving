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

개선
가장 최근 인덱스만 보므로 dp table을 유지할 필요가 없다.
(최근 1개만 유지하면 됨)
dp[j] = (가장 최근 집을 j로 색칠했을 때의 최소 비용)
*/

int main() {
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, cost_of_color[3], min_cost, dp[3], dp_temp[3];
    cin >> n;
    dp[0] = dp[1] = dp[2] = 0;
    ///////////////////solution//////////////////
    for (int k = 1; k <= n; k++) {
        cin >> cost_of_color[0] >> cost_of_color[1] >> cost_of_color[2];
        for (int c=0;c<3;c++)
            dp_temp[c] = dp[c];
        for (int c=0;c<3;c++) 
            dp[c] = min(dp_temp[(c+1)%3], dp_temp[(c+2)%3]) + cost_of_color[c];
    }
    ////////////////////output///////////////////
    cout << min({dp[0], dp[1], dp[2]});
    return 0;
}

/*legacy



*/
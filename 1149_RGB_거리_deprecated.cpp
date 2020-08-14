//색칠 비용이 모두 달라야 하는 버전

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
dp[i] = (i번째 집까지 색칠할 때의 최소 비용)
dp[0] = min(x,y,z)
if dp[n] = dp[n-1] + min(color1, color2) //color1, color2 != color[n-1]
*/

int main() {
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, cost_of_color[3], min_cost;
    int dp[MAX];
    cin >> n;
    int prev_color = -1;
    dp[0] = 0;
    ///////////////////solution//////////////////
    for (int k = 1; k <= n; k++) {
        cin >> cost_of_color[0] >> cost_of_color[1] >> cost_of_color[2];
        min_cost = 987654321;
        for (int c=0;c<3;c++) {
            if (c == prev_color)
                continue;
            if (cost_of_color[c] < min_cost) {
                min_cost = cost_of_color[c];
                prev_color = c;
            }
        }
        dp[k] = dp[k-1] + min_cost;
    }
    ////////////////////output///////////////////
    cout << dp[n];
    return 0;
}

/*legacy



*/
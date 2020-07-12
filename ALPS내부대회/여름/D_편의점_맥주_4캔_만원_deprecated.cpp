#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX_N 105
#define MAX_M 100005
#define MAX_P 10005

using namespace std;

/* 문제 정의
가진 돈 M, 크기 N 행복도 배열, 크기 N 가격 배열 -> 최대 행복도
 */

/* 해결 알고리즘 생각
knapsack problem
DP[i][m] = (m원으로 0~i 맥주에서 얻을 수 있는 최대 행복도)
DP[i][m] =  if m < cost(i) DP[i-1][m] 
            else max(DP[i-1][m-cost(i)] + reward(i), DP[i-1][m] )
*/

/* 시간복잡도
O(nm)
*/
int p[MAX_N], h[MAX_N], dp[MAX_N][MAX_M];

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    
    
    
     {
        cin >> p[i] >> h[i];
    }
    ///////////////////solution//////////////////
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        cout << "DP " << i << " : ";
        for (int j = 1; j <= m; j++) {
            if (j < p[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - p[i]] + h[i]);
        
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    ////////////////////output///////////////////
    cout << dp[n][m];
    return 0;
}
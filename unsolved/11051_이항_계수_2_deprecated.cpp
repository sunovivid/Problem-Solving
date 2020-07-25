//대칭이라 절반만 구했는데 안되는 이유?

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 1005

using namespace std;

/* 문제 정의
자연수 n, 정수 k -> combination(n,k) % 10007
 */

/* 해결 알고리즘 생각
dp[i][j] = iCj
dp[1][0] = 1, dp[1][1] = 1
for i = 2 to n
    for j = 0 to i
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
*/

/* 시간복잡도

*/
long long dp[MAX][MAX] = {0, };

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    ///////////////////solution//////////////////
    dp[1][0 + 1] = dp[1][1 + 1] = 1;
    for (int i=2;i<=n;i++) {
        for (int j=0 + 1; j<=i/2 + 2; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
        }
    }
    ////////////////////output///////////////////
    cout << dp[n][(k + 1 <= n/2 + 1) ? (k + 1) : (n - k + 1)];
    return 0;
}
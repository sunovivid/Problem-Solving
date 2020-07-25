#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 200010
using namespace std;

/* 문제 정의
쿼리의 개수 Q, 각 쿼리마다 N -> N을 2, 3, 4의 자연수 분할로 경우의 수 (순서O)
 */

/* 해결 알고리즘 생각
DP[i] = (i개를 나누어 먹는 모든 방법의 수를 R로 나눈 나머지)
DP[i] = (DP[i-2] + DP[i-3] + DP[i-4]) % R
DP[0] = 0, DP[1] = 0, DP[2] = 1, DP[3] = 1
*/

/* 시간복잡도
O(q + n)
*/
long long dp[MAX];
const long long R = 1e9 + 7;

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int q, n;
    cin >> q;
    ///////////////////solution//////////////////
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = dp[3] = 1;
    for (int i = 4; i < MAX; i++) {
        dp[i] = (dp[i - 2] + dp[i - 3] + dp[i - 4]) % R;
        // cout << "DP " << i << " : " << dp[i] << endl;
    }
    ////////////////////output///////////////////
    while (q--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}
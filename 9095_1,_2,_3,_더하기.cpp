#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

using namespace std;

/* 문제 정의
정수 n -> n을 1,2,3의 합으로 나타내는 방법의 수
 */

/* 해결 알고리즘 생각
dp[n] = (n을 1,2,3의 합으로 나타내는 방법의 수)
dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
dp[0] = 1, dp[1] = 1, dp[2] = 2

dp배열 4칸만 유지하며 하나씩 교체하는 테크닉 사용 (%연산 활용)
*/

/* 시간복잡도
O(n)
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n, dp[4] = {1,1,2,}, cur = 3;
        cin >> n;
        if (n < 3) {
            cout << dp[n] << '\n';
            continue;
        }
        ///////////////////solution//////////////////
        for (int i=3;i<=n;i++) {
            dp[cur] = dp[(cur+3)%4] + dp[(cur+2)%4] + dp[(cur+1)%4];
            cur = (cur + 1)%4;
        }
        ////////////////////output///////////////////
        cout << dp[(cur+3)%4] << '\n';
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 10010
#define max(a, b) (a > b ? a : b)
#define max3(a, b, c) (max(max(a, b), c))
using namespace std;

/* 문제 정의
N, 길이 N 수열 -> 3개 이상 연속하지 않는 부분수열의 합
 */

/* 해결 알고리즘 생각
DP[i]: 0~i번째 포도주 중에서 i번째 포도주를 마셨을 때 마실 수 있는 포도주 양의 최댓값
DP[i] = max(
        DP[i-3] + input[i-1] + input[i],
        DP[i-2] + input[i],
        )

수정1
    2579 계단 오르기 문제와 달리 오를 수 있는 계단 제한이 없음
    한번에 0,1,2,3,..계단 건너뛸 수 있음
    단, 3계단 이상부터는 건너뛰면 손해 (그 사이에 한 계단 방문하는 것이 무조건 유리)
    DP[i] = max(DP[i-4] + input[i-1] + input[i], 
            DP[i-3] + input[i-1] + input[i],
            DP[i-2] + input[i],
            )

*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long n, arr[MAX], dp[MAX];
    cin >> n;
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    ///////////////////solution//////////////////
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = max3(dp[max(i - 4, 0)] + arr[i - 1] + arr[i], dp[max(i - 3, 0)] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
    }
    ////////////////////output///////////////////
    cout << max(dp[n], dp[max(n - 1, 0)]);
    return 0;
}

/*legacy



*/
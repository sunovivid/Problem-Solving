#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 510

using namespace std;

/* 문제 정의
정수 수열 -> 경로 부분수열 합의 최댓값
경로: 정수 수열 삼각형 맨 위부터 아래까지 
 */

/* 해결 알고리즘 생각
DP[i] = (i번째 수를 방문했을 때 경로 부분수열 합의 최댓값)
DP[자식] = DP[부모] + now (맨 왼쪽, 오른쪽)
           max(DP[왼쪽부모], DP[오른쪽부모]) + now (중간)
정답: max(마지막 레벨 DP[])
*/

/* 시간복잡도
O(n)
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, dp[MAX], dp_prev[MAX], input;
    cin >> n;
    ///////////////////solution//////////////////
    dp[0] = dp_prev[0] = 0;
    for (int line = 0; line < n; line++) { //라인별로 dp
        //dp_prev 갱신
        for (int i = 0; i < line; i++) {
            dp_prev[i] = dp[i];
        }
        //라인별로 점화식
        for (int i = 0; i <= line; i++)
        {
            cin >> input;
            if (i == 0) //맨 왼쪽
                dp[i] = dp_prev[i] + input;
            else if (i == line) //맨 오른쪽
                dp[i] = dp_prev[i-1] + input; 
            else //가운데
                dp[i] = max(dp_prev[i - 1], dp_prev[i]) + input;
            // cout << dp[i] << ' ';
        }
        // cout << endl;
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, dp[i]);
    }
    ////////////////////output///////////////////
    cout << result;
    return 0;
}
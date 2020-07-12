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

개선
    오른쪽부터 갱신하면 dp_prev를 저장할 필요 없음
    dp가 자기 자신과 왼쪽만 보기 때문!
    (dp갱신 순서가 뒤섞이면 (화살표가 교점이 생기면) dp갱신에 이미 갱신된 dp 사용됨
    => 이전 dp 저장 필요)
*/

/* 시간복잡도
O(n)
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, dp[MAX], input;
    cin >> n;
    ///////////////////solution//////////////////
    cin >> dp[0]; //line 0
    for (int line = 1; line < n; line++) { //라인별로 dp
        for (int i = line; i >= 0; i--)
        {
            cin >> input;
            if (i == line) //맨 오른쪽
                dp[i] = dp[i - 1] + input; 
            else if (i > 0) //가운데
                dp[i] = max(dp[i - 1], dp[i]) + input;
            else //맨 왼쪽
                dp[i] = dp[i] + input;
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, dp[i]);
    }
    ////////////////////output///////////////////
    cout << result;
    return 0;
}
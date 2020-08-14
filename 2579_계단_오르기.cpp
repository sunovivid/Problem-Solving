/*1차원 DP로도 가능!
'연속 j번' 정보를 제외하고, 좀 더 이전까지 보는 방식으로
DP[i] : i번째 계단을 밟았을 때 최대 점수
DP[i] = max(DP[i-3] + arr[i-1] + arr[i], DP[i-2] + arr[i]);

i번째 계단으로 오는 모든 경우의 수 커버하면 OK
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 310

using namespace std;

/* 문제 정의
계단 개수, 각 계단의 점수 -> 점수합의 최댓값
제약:
    계단을 1 or 2칸 오를 수 있음
    연속 3계단을 모두 밟을 수 없음
    마지막 계단은 반드시 밟아야 함
 */

/* 해결 알고리즘 생각
처음 생각
    점수가 자연수이므로 2번 제약이 없으면 모두 밟으면 최댓값?

    dp?
        dp[i][j]: j번 계단을 연속으로 밟았을 때 i번째 계단에서의 최대 점수합
        초기
        dp[0][0] = 0
        dp[0][1] = 0
        dp[0][2] = 0
        점화식
        dp[i][1] = dp[i-1][0] + now
        dp[i][2] = dp[i-1][1] + now
        dp[i][0] = dp[i-1][2]
        정답 = max(dp[n][1], dp[n][2]) //0번 연속 밟은 것은 끝 발판은 밟지 않은 것이므로..

    오류 -> 999, 1, 999, 1, 999로 나와도 무조건 2칸 밟고 1칸 뛰는 식으로 감 (연속으로 2칸 뛰어야 하는 경우도 있음)

수정1
    dp[i][1] = (dp[i-2][2], dp[i-2][1]) + now
    dp[i][2] = dp[i-1][1] + now
    dp[i][0] = dp[i-1][2]
    정보의 중복?? 이상하게 작동할듯

수정2: 계단 i에서 '연속 0번' 정보를 저장할 필요 없음
    dp[i][j]: "마지막으로 i번 계단을 밟았을 때" 최대 점수합 (마지막 계단 포함 j번 연속)
    dp[i][2] = dp[i-1][1] + now
    dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + now
    정보 중복이 없어 논리가 명확하고 정답도 명료함 
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, step_score, dp[2], dp_prev[2], dp_prev_prev[2];
    cin >> n;
    ///////////////////solution//////////////////
    dp[0] = dp[1] = 0;
    dp_prev[0] = dp_prev[1] = 0;
    while (n--) {
        cin >> step_score;
        for (int i = 0; i < 2; i++) {
            dp_prev_prev[i] = dp_prev[i];
            dp_prev[i] = dp[i];
        }
        dp[1] = dp_prev[0] + step_score;
        dp[0] = max(dp_prev_prev[0], dp_prev_prev[1]) + step_score;
    }
    ////////////////////output///////////////////
    cout << max(dp[0], dp[1]);
    return 0;
}

/*legacy



*/
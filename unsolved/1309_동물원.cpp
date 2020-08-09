#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX

using namespace std;

/* 문제 정의
자연수 N -> 2xn 우리에 가로, 세로 붙어있지 않게 사자를 배치하는 경우의 수 (를 9901로 나눈 나머지)
 */

/* 해결 알고리즘 생각
dp[i][0] = (2xi 우리에 가로, 세로 붙어있지 않게 사자를 배치하는 경우의 수 (i행 0열에 반드시 배치) (를 9901로 나눈 나머지))
dp[i][1] = (2xi 우리에 가로, 세로 붙어있지 않게 사자를 배치하는 경우의 수 (i행 1열에 반드시 배치) (를 9901로 나눈 나머지))
for j = 0 and 1
    dp[i][j] = dp[i-1][!j] + dp[i-2][!j] + 1 (빈 경우)
정답: sum({i = 0 to n} dp[i][0] + dp[i][1])
=> 틀림. 스티커 문제처럼 최대합 구하는 게 아니라 경우의 수 구하는 문제라 dp[i]구하려면 전 두개뿐만 아니라 dp[0] .. dp[i-1] 전부 봐야 함 => O(n^2) 못푼다
=> 포도주 시식 문제 아이디어 활용

수정1
    dp[i] = (2xi 우리에 가로, 세로 붙어있지 않게 사자를 배치하는 경우의 수)
    dp[i] = dp[i-2] * 3 + dp[i-3] * 4
=> 틀림

인터넷의 풀이: https://sihyungyou.github.io/baekjoon-1309/
    첫 번째 풀이에 'n번째 줄에 사자가 없는 경우'를 따로 추가하면 이전 dp 전부 확인할 필요 없이 O(n)에 가능!
        ("풀이를 간결하게 하려면 정보를 더 추가" 아이디어, '빈 상태'도 정보로 추가할 생각을 해야)
        dp[i][0] = dp[i-1][1] + dp[i-1][2] //i번째 줄의 왼쪽에 사자
        dp[i][1] = dp[i-1][0] + dp[i-1][2] //오른쪽에 사자
        dp[i][2] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2] //i번째 줄이 빈 경우
    or
    그냥 써놓고 규칙 찾기
*/

/* 시간복잡도
O(n)
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    ///////////////////solution//////////////////
    long long dp[2][3] = {1, 1, 1}, cur = 1; // 아무 사자도 배치하지 않는 경우 제외
    while (--n)
    {
        for (int i = 0; i < 3; i++)
        {
            dp[cur][i] = (i == 0 ? 0 : dp[!cur][0]) + (i == 1 ? 0 : dp[!cur][1]) + dp[!cur][2];
            dp[cur][i] %= 9901;
            // cout << dp[cur][i] << ' ';
        }
        cur = !cur;
        // cout << '\n';
    }
    ////////////////////output///////////////////
    cout << (dp[!cur][0] + dp[!cur][1] + dp[!cur][2]) % 9901; //나머지한것 합도 나머지 해줘야함
    return 0;
}
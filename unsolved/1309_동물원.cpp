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
    int dp[4] = {3, 7, 17, }, cur = 3; // 아무 사자도 배치하지 않는 경우 제외
    for (int i=4;i<=n;i++) {
        dp[cur] = (dp[(cur+2)%4] * 3 + dp[(cur+1)%4] * 4) % 9901;
        cout << "ways (" << i << " row): " << dp[cur]  << endl;
        cur = (cur + 1) % 4;
    }
    ////////////////////output///////////////////
    cout << dp[cur];
    return 0;
}
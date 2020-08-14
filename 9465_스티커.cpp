#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 100005

using namespace std;

/* 문제 정의
2xn 정수 배열 -> 스티커 점수의 최댓값
스티커 제약:
    스티커를 선택하면 인접한 스티커는 선택할 수 없음
 */

/* 해결 알고리즘 생각
DP[n] = (i번째 열까지 고려했을 때 얻을 수 있는 점수의 최댓값)
점화식 어렵네..

1차원이라면?
    DP[n] = (i번째 스티커를 선택했을 때 얻을 수 있는 점수의 최댓값)
    DP[i] = max(DP[i-2], DP[i-3]) + arr[i]

2차원으로 확장
    DP[i][j] = (i번째 열의 j번째 스티커를 선택했을 때 얻을 수 있는 점수의 최댓값)
    DP[i][0] = max(DP[i-1][1], DP[i-2][0], DP[i-2][1]) + arr[i][0]
    DP[i][1] = max(DP[i-1][0], DP[i-2][0], DP[i-2][1]) + arr[i][0]

    DP[0][0] = arr[0][0]
    DP[0][1] = arr[0][1]
    DP[1][0] = arr[1][0] + arr[0][1]
    DP[1][1] = arr[1][1] + arr[0][0]

개선1
    DP[i][0] = max(DP[i-1][1], DP[i-2][1]) + arr[i][0]
    DP[i-2][0]의 케이스는 DP[i-1][1]에 포함됨.
    DP[i][1] = max(DP[i-1][0], DP[i-2][1]) + arr[i][0]]
    마찬가지
*/

/* 시간복잡도
    O(2n)
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t, n, arr[MAX][2], dp[2], dp_prev[2], dp_prev_prev[2];
    cin >> t;
    ///////////////////solution//////////////////
    while (t--) {
        //입력
        cin >> n;
        for (int i=0;i<n;i++)
            cin >> arr[i][0];
        for (int i=0;i<n;i++)
            cin >> arr[i][1];

        //n=1케이스
        if (n == 1) {
            cout << max(arr[0][0], arr[0][1]) << '\n';
            continue;
        }

        //dp 초깃값
        dp_prev[0] = arr[0][0];
        dp_prev[1] = arr[0][1];
        dp[0] = arr[1][0] + arr[0][1];
        dp[1] = arr[1][1] + arr[0][0];
        
        for (int i=2;i<n;i++) {
            //dp 갱신
            for (int j=0;j<2;j++) {
                dp_prev_prev[j] = dp_prev[j];
                dp_prev[j] = dp[j];
            }
            //점화식
            for (int j=0;j<2;j++) {
                dp[j] = max({dp_prev[1-j], dp_prev_prev[1-j]}) + arr[i][j];
            }
        }
        cout << max({dp[0], dp[1], dp_prev[0], dp_prev[1]}) << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}
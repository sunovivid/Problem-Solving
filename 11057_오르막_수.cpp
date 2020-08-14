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
자연수 n -> 길이 n인 '오르막 수'의 개수 (를 10007로 나눈 나머지)
오르막 수: 수의 자리가 오름차순을 이루는 수 (같아도 ok)
 */

/* 해결 알고리즘 생각
    dp[i][j] = (i자리고 일의 자리가 j인 오르막 수의 개수)
    for i = 0 to n-1
        for j = 0 to 9
            for k = 0 to j
                dp[i][j] += dp[i-1][k]

개선1: 부분합
    dp[i][j] = (i자리고 일의 자리가 0~j까지인 오르막 수 개수의 부분합 % 10007)
    dp[0][for k = 0 to 9] = k + 1
        for i = 0 to n-1
            for j = 0 to 9
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 10007
    답: dp[n-1][9]

    이슈: 나머지의 부분합 vs 부분합의 나머지
        같다?
*/

/* 시간복잡도

*/

int dp[11] = {0,};

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    ///////////////////solution//////////////////
    //base case
    for (int i=1;i<=10;i++)
        dp[i] = i;
    //dp
    while (--n) {
        for (int j=1;j<=10;j++)
            dp[j] = (dp[j] + dp[j-1]) % 10007;
    }
    ////////////////////output///////////////////
    cout << dp[10];
    return 0;
}
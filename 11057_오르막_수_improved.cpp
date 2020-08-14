//문제 답이 combination(n+9,9)라 모듈러 역원 이용한 O(1) 풀이 존재

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

코드 보고 개선 1: base case 부분을 시작값 하나 1넣고 반복을 한 번 더 해서 따로 처리할 필요 없이 가능
    1111111111 -> 123456789 (base case) -> 반복..
*/

/* 시간복잡도

*/

int dp[11] = {0, 1, };

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    ///////////////////solution//////////////////
    //dp
    while (n-- + 1) {
        for (int j=1;j<=10;j++)
            dp[j] = (dp[j] + dp[j-1]) % 10007;
    }
    ////////////////////output///////////////////
    cout << dp[10];
    return 0;
}
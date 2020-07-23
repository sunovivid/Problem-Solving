#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 67

using namespace std;

/* 문제 정의
t번의 쿼리
    자연수 n -> 길이 n 감소하지 않는 0~9로 이루어진 수열 개수
 */

/* 해결 알고리즘 생각
11057 오르막 수와 똑같이, 단 dp 배열 유지
dp[i][j] = (끝이 j로 끝나는 줄어들지 않는 i자리 수 개수의 부분합)
*/

/* 시간복잡도

*/
long long dp[MAX][11] = {0,1,};

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    ///////////////////solution//////////////////
    for (int i=1;i<=MAX-1;i++) {
        for (int j=1;j<=10;j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n+1][10] << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}
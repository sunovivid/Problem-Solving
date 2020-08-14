#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 1005

using namespace std;

/* 문제 정의
자연수 n, 정수 k -> combination(n,k) % 10007
 */

/* 해결 알고리즘 생각
dp[i][j] = iCj
dp[1][0] = 1, dp[1][1] = 1
for i = 2 to n
    for j = 0 to i
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j]

풀이 보고 개선1
    dp 라인 하나만 유지하면 됨
    이전 인덱스를 참고하므로 라인 갱신은 뒤에서부터
    
*/

/* 시간복잡도
    O(n^2)
*/
int dp[MAX] = {0, 1, };

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    ///////////////////solution//////////////////
    for (int i=1;i<=n;i++) {
        for (int j=i+1; j>0; j--) {
            dp[j] = (dp[j-1] + dp[j]) % 10007;
        }
    }
    ////////////////////output///////////////////
    cout << dp[k + 1];
    return 0;
}
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
자연수 N -> 1, 00으로 만들 수 있는 길이 N 2진 수열 개수
 */

/* 해결 알고리즘 생각
dp[i] = (1, 00으로 만들 수 있는 길이 i 2진 수열 개수)
dp[i] = dp[i-1] + dp[i-2]
dp[1] = 1
dp[2] = 2
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
    int dp[3] = {0, 1, 2}, cur = n < 3 ? n + 1 : 0;
    for (int i=3;i<=n;i++) {
        dp[cur] = (dp[(cur+1)%3] + dp[(cur+2)%3]) % 15746;
        cur = (cur + 1)%3;
    }
    ////////////////////output///////////////////
    cout << dp[(cur+2)%3];
    return 0;
}
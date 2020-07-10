#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX

using namespace std;

/* 문제 정의
n -> 2*n 직사각형을 1*2, 2*1, 2*2 타일로 채우는 방법의 수를 10007로 나눈 나머지
 */

/* 해결 알고리즘 생각
    DP[i] : 2*i 직사각형을 채우는 방법의 수
    DP[i] = DP[i-1] + DP[i-2] * 2
    DP[0] = 0 DP[1] = 1
    피보나치??

숫자가 크므로 나머지 저장해야 하나? 대충 마지막 수 O(2^1000)?
    DP[i] : 2*i 직사각형을 채우는 방법의 수를 10007로 나눈 나머지
    DP[i] = (DP[i-1] + DP[i-2] * 2) % 10007
*/

/* 시간복잡도
    O(n)
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, dp, dp_prev, dp_prev_prev;
    cin >> n;
    ///////////////////solution//////////////////
    dp = 1;
    dp_prev = 1;
    while (--n) {
        dp_prev_prev = dp_prev;
        dp_prev = dp;
        dp = (dp_prev + 2 * dp_prev_prev) % 10007;
    }
    ////////////////////output///////////////////
    cout << dp;
    return 0;
}
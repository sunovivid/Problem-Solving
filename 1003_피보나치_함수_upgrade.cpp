/*https://www.acmicpc.net/source/16174056
작동 원리?*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 43

using namespace std;

/* 문제 정의
n -> 0, 1 출력되는 횟수
 */

/* 해결 알고리즘 생각
문제에선 피보나치 함수를 점화식 정의에 따라 정의함
F0 = 0, F1 = 1, Fn+2 = Fn+1 + Fn
1이 출력되는 횟수: 계산된 점화식 값은 사실상 1들의 합 = 호출된 fibo(1)횟수.
    따라서 피보나치 수열 그 자체
0이 출력되는 횟수: fibo(0) 호출은 fibo(0)직접 호출 혹은 fibo(2)에서만 일어남
    fibo(2) = fibo(1) + fibo(0)이므로 
*/

int main()
{
    ////////////////////input////////////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t, n, dp[MAX];
    cin >> t;
    dp[0] = 1, dp[1] = 0; //, dp[2] = 1;
    for (int i = 2; i <= MAX; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    ///////////////////solution//////////////////
    while (t--)
    {
        cin >> n;
        cout << dp[n] << ' ' << dp[n + 1] << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}

/*legacy



*/
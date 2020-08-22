/**
 * 나머지끼리 빼면 음수가 될 수 있으므로 +MOD한 후 % MOD하는 테크닉
 * 두 번 빼므로 +2*MOD 했더니 overflow 발생함.
 *     long long으로 바꾸는 방법과
 *     한 번 빼고 +MOD)%MOD, 다시 한 번 빼고 +MOD)%MOD하는 방법 있음

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 105
#define R 1000000007

using namespace std;

/* 문제 정의
n -> 비대칭 타일링 경우의 수
 */

/* 해결 알고리즘 생각

*/

/* 시간복잡도

*/
long long dp[MAX];

long long tiling(int n)
{
    if (n == 1 || n == 0)
        return 1;
    long long &ret = dp[n];
    if (ret != -1)
        return ret;
    return ret = (tiling(n - 1) + tiling(n - 2)) % R;
}

long long asymtiling(int n)
{
    return (tiling(n) - ((n % 2 == 0 ? tiling(n / 2) + tiling(n / 2 - 1) : tiling((n - 1) / 2))) + 2 * R) % R;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int c;
    cin >> c;
    ///////////////////solution//////////////////
    while (c--)
    {
        int n;
        cin >> n;
        memset(dp, -1, sizeof(dp));
        cout << asymtiling(n) << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>
#include <numeric>

#define MAX
#define R 1'000'000'000

using namespace std;

/* 문제 정의
자연수 n -> 길이가 n인 계단 수 개수
 */

/* 해결 알고리즘 생각
f(n,k) = (길이가 n이고 k로 시작하는 계단수)
완탐 -> dp
*/

/* 시간복잡도
*/

long long dp[101][11];

long long f(int n, int begin)
{
    if (n == 1)
        return 1;
    long long &ret = dp[n][begin];
    if (ret != -1)
        return ret;
    ret = 0;
    if (begin > 0)
        ret += f(n - 1, begin - 1);
    if (begin < 9)
        ret += f(n - 1, begin + 1);
    ret %= R;
    return ret;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    ///////////////////solution//////////////////
    vector<long long> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<long long> tNums;
    transform(nums.begin(), nums.end(), back_inserter(tNums), [n](const auto &x) { return f(n, x); });
    // for (auto x : tNums)
    //     cout << x << ' ';
    // cout << '\n';
    cout << (accumulate(tNums.begin(), tNums.end(), 0, [](const auto &x, const auto &y) { return (x + y) % R; }));
    ////////////////////output///////////////////

    return 0;
}
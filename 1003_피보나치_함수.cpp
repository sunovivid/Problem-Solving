#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 41

using namespace std;

/* 문제 정의
n -> 0, 1 출력되는 횟수
 */

/* 해결 알고리즘 생각
DP (memoization)
0,1일때 count++
*/

typedef pair<int, int> pii;
int cnt0, cnt1;
pii dp[MAX] = {
    {0, 0},
};
pii fibonacci(int n)
{
    // cout << "fibo " << n << " called " << '\n';
    if (dp[n].first != 0)
    {
        assert(dp[n].second != 0);
        return dp[n];
    }
    if (n == 0)
        return {1, 0};
    else if (n == 1)
        return {0, 1};
    else
    {
        pii f1 = fibonacci(n - 1), f2 = fibonacci(n - 2);
        return dp[n] = {f1.first + f2.first, f1.second + f2.second};
    }
}

int main()
{
    ////////////////////input////////////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t, n;
    cin >> t;
    ///////////////////solution//////////////////
    while (t--)
    {
        cin >> n;
        cnt0 = 0, cnt1 = 0;
        pii result = fibonacci(n);
        cout << result.first << ' ' << result.second << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}

/*legacy



*/
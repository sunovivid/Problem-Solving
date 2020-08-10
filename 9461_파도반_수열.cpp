#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 105

using namespace std;

/* 문제 정의
 ->
 */

/* 해결 알고리즘 생각

*/

/* 시간복잡도

*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ///////////////////solution//////////////////
    long long dp[MAX] = {1, 1, 1, 2, 2};
    for (int i = 5; i <= 100; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 5];
    }
    ////////////////////output///////////////////
    int t;
    cin >> t;
    while (t--)
    {
        int in;
        cin >> in;
        cout << dp[in - 1] << '\n';
    }
    return 0;
}
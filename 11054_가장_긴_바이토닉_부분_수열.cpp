//첫번째 수부터 시작하는 수열만 고려해서 틀렸음

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
자연수 수열 -> 가장 긴 바이토닉 부분 수열
 */

/* 해결 알고리즘 생각
bitonic(beginIdx, beginNum, isDecreasing)
*/

/* 시간복잡도
O(n^2)
*/
int n;
vector<int> s;
int dp[1001][2];

int bitonic(int beginIdx, bool isDecreasing)
{
    if (beginIdx == n)
    {
        return 1;
    }
    int &ret = dp[beginIdx][isDecreasing];
    if (ret != -1)
        return ret;
    ret = 1;
    for (int nextBeginIdx = beginIdx + 1; nextBeginIdx <= n; nextBeginIdx++)
    {
        if (!isDecreasing && s[nextBeginIdx] > s[beginIdx])
        {
            ret = max(ret, 1 + bitonic(nextBeginIdx, true));
            ret = max(ret, 1 + bitonic(nextBeginIdx, false));
        }
        else if (s[nextBeginIdx] < s[beginIdx])
        {
            ret = max(ret, 1 + bitonic(nextBeginIdx, true));
        }
    }
    return ret;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    int x;
    s.push_back(-1);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.push_back(x);
    }
    ///////////////////solution//////////////////
    memset(dp, -1, sizeof(dp));
    cout << max(bitonic(0, false), bitonic(0, true)) - 1;
    ////////////////////output///////////////////

    return 0;
}
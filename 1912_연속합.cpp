#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 100'002
#define INF 987654321
using namespace std;

/* 문제 정의
길이 n 정수 수열 -> 연속부분수열의 최대합
 */

/* 해결 알고리즘 생각
maxsum(A,isAccumalating) = {
    if (isAccumalating)
        if (A[0] >= 0)
            A[0] + maxsum(A[1:], true)
        else
            maxsum(A[1:], false)
    else
        max(A[0] + maxsum(A[1:], true), maxsum(A[1:], false))
}
*/

/* 시간복잡도
O(2n)
*/
int dp[MAX][3];
vector<int> a;

int sum(int begin, short isAccumalating) //isAccumalating 0 -> before sum, 1 -> while sum, 2 -> after sum
{
    if (begin == a.size())
        return (isAccumalating == 0 ? -INF : 0); //아무 것도 안 더하면 안됨
    int &ret = dp[begin][isAccumalating];
    if (ret != -INF)
        return ret;
    ret = 0;
    if (isAccumalating == 0)
    {
        ret = max(sum(begin + 1, 0), a[begin] + sum(begin + 1, 1));
    }
    else if (isAccumalating == 1)
    {
        ret = max(a[begin] + sum(begin + 1, 1), sum(begin + 1, 2));
    }
    return ret;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    ///////////////////solution//////////////////
    fill(&dp[0][0], &dp[0][0] + MAX * 3, -INF);
    cout << sum(0, 0);
    ////////////////////output///////////////////

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 1002

using namespace std;

/* 문제 정의
수열 2개 -> 최장 공통 부분 수열 구하기
 */

/* 해결 알고리즘 생각
lcs(a,b) = (a, b에서 시작하는 lcs 길이)
lcs(a,b) = max{for arr[a+i] = arr[b+j] 만족하는 처음i,j}lcs(a+i, b+j)
*/

/* 시간복잡도
O(n^2*m^2)
부분문제 nm개
각 문제당 O(nm)
*/
string s1, s2;
int dp[MAX][MAX];

int lcs(int a, int b)
{
    int &ret = dp[a][b];
    if (ret != -1)
        return ret;
    ret = 1;
    for (int i = a + 1; i < s1.length(); i++)
    {
        for (int j = b + 1; j < s2.length(); j++)
        {
            if (s1[i] == s2[j])
            {
                ret = max(ret, 1 + lcs(i, j));
                break;
            }
        }
    }
    return ret;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s1 >> s2;
    s1 = '*' + s1;
    s2 = '*' + s2;
    ///////////////////solution//////////////////
    memset(dp, -1, sizeof(dp));
    cout << lcs(0, 0) - 1;
    ////////////////////output///////////////////

    return 0;
}
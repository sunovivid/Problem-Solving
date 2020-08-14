#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 1005

using namespace std;

/* 문제 정의
길이 n 자연수 수열 -> 최대 길이 증가하는 부분 수열의 길이
 */

/* 해결 알고리즘 생각
dp[i] = (i번째 수열을 마지막으로 하는 최대 길이 부분 증가 수열의 길이)
dp[i] = max(dp[i-1], dp[i-2], ...) + 1 (dp[k]가 arr[i]보다 작을 때만)
*/

/* 시간복잡도
O(n^2)
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    ///////////////////solution//////////////////
    int dp[MAX], arr[MAX], max_num = 1;
    for (int i=0;i<n;i++) {
        cin >> arr[i];
        dp[i] = 1;
        for (int j=0;j<i;j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[j] + 1, dp[i]);
                max_num = max(dp[i], max_num);
            }
        }
    }
    ////////////////////output///////////////////
    cout << max_num;
    return 0;
}
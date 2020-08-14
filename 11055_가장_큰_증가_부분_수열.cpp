#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 1005

using namespace std;

/* 문제 정의
수열 -> 증가 부분 수열 중 합의 최댓값
 */

/* 해결 알고리즘 생각
모든 증가 부분 수열 탐색

dp[i] = (i번째 원소로 끝나는 합이 가장 큰 증가 부분 수열의 합)
for i = 0 to n
    for j = 1 to i
        if arr[i] > arr[j]
            dp[i] = max(dp[j] + arr[i], dp[i])
답: dp[0..i] 중 최댓값
*/

/* 시간복잡도
O(n^2)
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, arr[MAX], dp[MAX], max_sum = 1;
    cin >> n;
    ///////////////////solution//////////////////
    cin >> arr[0];
    dp[0] = arr[0];
    max_sum = arr[0];
    for (int i=1;i<n;i++) {
        cin >> arr[i];
        dp[i] = arr[i];
        for (int j=0;j<i;j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[j] + arr[i], dp[i]);
                max_sum = max(dp[i], max_sum);
            }
        }
    }
    ////////////////////output///////////////////
    cout << max_sum;
    return 0;
}
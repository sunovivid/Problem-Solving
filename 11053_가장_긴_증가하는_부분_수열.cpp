#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 1005

using namespace std;

/* 문제 정의
수열 -> 가장 긴 증가하는 부분 수열
 */

/* 해결 알고리즘 생각
모든 케이스 고려: O(nC1+nC2+..+nCn) = O(2nCn)

dp[i][j] = (i번째 원소까지 마지막 원소가 j이상의 가장 긴 증가하는 부분 수열의 길이)
dp[i][j] = max(dp[i-1][0], dp[i-1][1], ... ,dp[i-1][j-1]) + 1
=> dp[i][j] = max(dp[i-1][0])

for i = 0 to n
    for j = 0 to input - 1
        dp[i][j] = dp[i-1][j]
    for j = input to inputmax
        dp[i][j] = max(dp[i-1][j-1]+1, dp[i][j-1])

이상?이하? 2차원 배열의 col 채울때 밑에서부터? 위에서부터?

정해
    dp[i] = (i번째 원소로 끝나는 가장 긴 증가하는 부분 수열의 길이)
    for i = 0 to n
        for j = 0 to i
            if arr[j] < arr[i]
                dp[i] = max(dp[j] + 1, dp[i])
    
    1차원 dp + O(n^2)으로 해결
    dp라고 다 O(n)인 것은 아니다.. 그 전 것 전부 봐야하면 보는 걸 꺼리지 말자

=> 2차원으로 '마지막 원소' 정보를 추가해야 하나 싶었는데 그냥 O(n^2)으로 푸는 게 깔끔했음
마지막 원소를 추가하면 이상으로 해야할지 이하로 해야할지 애매하고 수열의 값 범위 모두 순회해야 하기 때문에..
*/

/* 시간복잡도
O(n^2)
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, arr[MAX], dp[MAX], max_length = 1;
    cin >> n;
    ///////////////////solution//////////////////
    cin >> arr[0];
    dp[0] = 1;
    for (int i=1;i<n;i++) {
        cin >> arr[i];
        dp[i] = 1; //초기값
        for (int j=0;j<i;j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[j] + 1, dp[i]);
                max_length = max(dp[i], max_length);
            }
        }
    }
    ////////////////////output///////////////////
    cout << max_length;
    return 0;
}
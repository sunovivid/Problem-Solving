#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 10005
#define INF 987654321
using namespace std;

/* 문제 정의
동전 가치를 나타내는 길이 n 수열, k -> 동전 가치 합이 k가 되도록 하는 동전 수의 최솟값 
 */

/* 해결 알고리즘 생각
    dp[i] = (0~i번째 동전을 사용할 동전 가치 합이 k가 되도록 하는 동전 개수 최솟값)
    dp[i] = dp[i-1]
=> 관계x

수정1
    dp[i] = (i원을 만들기 위해 필요한 동전 개수 최솟값)
    dp[i] = min(dp[i-v[0]], dp[i-v[1]], ...) + 1
    memoization
    
*/

/* 시간복잡도
O(k*n)
*/
int n, dp[MAX] = {0, }, coin[105];

int dp_memoize(int k) {
    // cout << "call dp " << k << endl;
    if (k <= 0)
        return INF;

    if (dp[k] != 0)
        return dp[k];
    
    int min_num_coin = INF;
    for (int i=0;i<n;i++) {
        min_num_coin = min(dp_memoize(k - coin[i]) + 1, min_num_coin); //+1 밖에서 하는 실수
        // cout << "   calculating min_num_coin " << k << " : " << min_num_coin << endl;
    }
    // cout << "   calculated dp " << k << " : " << min_num_coin << endl;
    return dp[k] = min_num_coin;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int k;
    cin >> n >> k;
    int in;
    for (int i=0;i<n;i++) {
        cin >> in;
        if (in >= MAX)
            continue;
        coin[i] = in;
        dp[coin[i]] = 1;
    }
    ///////////////////solution//////////////////
    int result = dp_memoize(k);
    if (result == INF) //= 비교 실수
        cout << -1;
    else
        cout << result;
    ////////////////////output///////////////////
    
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX_N 105
#define MAX_M 100005
#define MAX_P 10005

using namespace std;

/* 문제 정의
가진 돈 M, 크기 N 행복도 배열, 크기 N 가격 배열 -> 최대 행복도
 */

/* 해결 알고리즘 생각
knapsack problem
DP[i][m] = (m원으로 0~i 맥주에서 얻을 수 있는 최대 행복도)
DP[i][m] =  if m < cost(i) DP[i-1][m] 
            else max(DP[i-1][m-cost(i)] + reward(i), DP[i-1][m] )

수정1
4캔 만원 조건을 못봄..
DP[i][m] = (m원으로 0~i 맥주에서 얻을 수 있는 최대 행복도)
DP[i][m] =  if m < cost(i) DP[i-1][m] 
            else max(DP[i-1][m-cost(i)] + reward(i), DP[i-1][m] )
모든 맥주가 2500 이상이므로 가능하면 4캔 만원으로 바꾸는 것이 무조건 더 저렴함
    제일 행복도가 높은 순으로 네캔 만원 가능한 만큼 고르기
    만원 미만의 남은 돈으로 DP
*/

/* 시간복잡도
O(nm)
*/
int p[MAX_N], h[MAX_N], dp[MAX_N][MAX_M];

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    vector<pair<int,int>> input;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> h[i];
        input.push_back({h[i], p[i]});
    }
    ///////////////////solution//////////////////
    //4캔 만원 고르기
    int result = 0;
    sort(input.begin(), input.end());
    while (m >= 10000 || input.size() >= 4) {
        m -= 10000;
        cout << "pop: ";
        for (int j = 0; j < 4; j++)
        {
            result += input.back().first;
            cout << input.back().first << ' ';
            input.pop_back();
        }
        cout << "result: " << result << endl;
    }
    cout << "m: " << m << endl;
    // assert(false);
    //남은 돈으로 DP
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= input.size(); i++) {
        cout << "DP " << i << " : ";
        for (int j = 1; j <= m; j++) {
            if (j < input[i-1].second)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - input[i-1].second] + input[i-1].first);
            // cout << dp[i][j] << ' ';
        }
        cout << dp[i][m] << endl;
    }
    result += dp[input.size()][m];
    ////////////////////output///////////////////
    cout << result;
    return 0;
}
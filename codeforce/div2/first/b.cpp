#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXHP 10001
#define INF 987654321
/* 문제 정의
HP, n, m -> 잡을 수 있는가? YES/NO
HP <= 10^5, n, m <= 30
HP
n : hp = hp / 2;
m : hp -= 10;
 */

/* 해결 알고리즘 생각
DP: 남은 HP, N, M
dp(n, m) = min(dp(n-1, m)/2,dp(n, m-1)-10) : n번, m번 캐스트할수있을때 남은 최소 hp
dp(n, m)<0이면 true 아니면 false

dp base case: n <= 0 or m <= 0
hp <= 0 이면 그냥 return -INF
*/

/* 의사코드: 하향식 dp
while 
dp[n][m] = dp[n-1][m]/2 < dp[n][m-1]-10 ? dp[n-1][m]/2 : dp[n][m-1]-10
if 
*/
int dp[31][31] = {
    0,
};

bool is_possible_defeat(int hp, int n, int m)
{
    //init memo
    int size = max(n, m);
    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= size; j++)
        {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = hp;
    int k, l = 0;
    for (int i = 0; i <= size * 2; i++)
    {
        for (int j = 0; j <= size; j++)
        {
            k = i - j;
            if (k < 0)
                continue;
            if (k > size)
                continue;
            if (j == 0 && k == 0)
                continue;
            else if (j == 0)
            {
                dp[j][k] = min(dp[j][k - 1] - 10, INF);
                if (dp[j][k] <= 0 && j <= n && k <= m)
                    return true;
            }
            else if (k == 0)
            {
                dp[j][k] = min(dp[j - 1][k] / 2 + 10, INF);
                if (dp[j][k] <= 0 && j <= n && k <= m)
                    return true;
            }
            else
            {
                dp[j][k] = min(dp[j - 1][k] / 2 + 10, dp[j][k - 1] - 10);
                if (dp[j][k] <= 0 && j <= n && k <= m)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // cout << (is_possible_defeat(63, 2, 3) ? "YES" : "NO") << '\n';

    int t;
    cin >> t;
    while (t--)
    {
        int hp, n, m;
        cin >> hp;
        cin >> n;
        cin >> m;
        //dp initialize!!
        cout << (is_possible_defeat(hp, n, m) ? "YES" : "NO") << '\n';
    }
    return 0;
}

/* 해결 알고리즘 생각 옛날거
DP: 남은 HP, N, M
dp(n, m) = min(dp(n-1, m)/2,dp(n, m-1)-10) : n번, m번 캐스트할수있을때 남은 최소 hp
dp(n, m)<0이면 true 아니면 false

dp base case: n <= 0 or m <= 0
hp <= 0 이면 그냥 return -INF
*/

/* 의사코드: 하향식 dp
while 
dp[n][m] = dp[n-1][m]/2 < dp[n][m-1]-10 ? dp[n-1][m]/2 : dp[n][m-1]-10
if 
*/
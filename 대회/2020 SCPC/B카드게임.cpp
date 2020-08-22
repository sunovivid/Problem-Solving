#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 3002

using namespace std;

vector<int> x, y;
int winCnt = 0, k;
typedef pair<int, int> pii;
int dp[MAX][MAX];

bool takeCard(int xTop, int yTop) //해당 상태에서 최적으로 플레이할 때 해당 턴의 사람이 무조건 승리하면 true, 아니면 false
{
    int &ret = dp[xTop + 1][yTop + 1];
    if (ret != -1)
        return ret;
    if (xTop == -1 && yTop == -1)
    {
        // cout << "return default" << endl;
        winCnt++;
        return ret = true;
    }
    //합이 k 이하가 될 때까지 가져가기
    //만약 자신이 이기는 경우가 하나라도 있으면 winCnt++하고 return true
    bool isWinWayExist = false;
    [&] {
        for (int curSum = 0, i = 0; xTop - i >= -1 && curSum <= k; curSum += x[xTop - i], i++)
        {
            int tempCurSum = curSum;
            for (int j = 0; yTop - j >= -1 && curSum <= k; curSum += y[yTop - j], j++)
            {
                if (i == 0 && j == 0) //각 더미에서 0장, 0장 가져가는 경우 제외
                    continue;
                bool isOpponentWin = takeCard(xTop - i, yTop - j);
                if (!isOpponentWin)
                {
                    isWinWayExist = true;
                    return;
                }
            }
            curSum = tempCurSum;
        }
    }();
    // cout << "return" << endl;
    if (isWinWayExist)
    {
        winCnt++;
        return ret = true;
    }
    else
    {
        return ret = false;
    }
}

int main(int argc, char **argv)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T, test_case;
    // freopen("input.txt", "r", stdin);

    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {
        /////////////////////////////////////////////////////////////////////////////////////////////
        int n;
        cin >> n >> k;
        int input;
        x.clear();
        y.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> input;
            x.push_back(input);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> input;
            y.push_back(input);
        }
        memset(dp, -1, sizeof(dp));
        winCnt = 0;
        takeCard(n - 1, n - 1);
        /////////////////////////////////////////////////////////////////////////////////////////////
        // Print the answer to standard output(screen).
        cout << "Case #" << test_case + 1 << endl;
        cout << winCnt << ' ' << (n + 1) * (n + 1) - winCnt << endl;
    }

    return 0; //Your program should return 0 on normal termination.
}
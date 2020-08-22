#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 105
/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

using namespace std;

vector<int> x, y;
int winCnt = 0, loseCnt = 0, k;
typedef pair<int, int> pii;
pii dp[MAX][MAX][2];

//https://stackoverflow.com/questions/21956119/add-stdpair-with-operator pair 더하기 연산 구현 참조
template <typename T, typename U>
pair<T, U> operator+(const std::pair<T, U> &l, const std::pair<T, U> &r)
{
    return {l.first + r.first, l.second + r.second};
}

pii takeCard(int xTop, int yTop, bool isMyTurn)
{
    cout << "call takeCard(" << xTop << ", " << yTop << ", " << isMyTurn << ")" << endl;
    if (xTop == -1 && yTop == -1)
    {
        cout << "return" << endl;
        return (isMyTurn ? make_pair(0, 1) : make_pair(1, 0));
    }
    pii &ret = dp[xTop + 1][yTop + 1][isMyTurn];
    if (!(ret.first == -1 && ret.second == -1))
    {
        cout << "return by memoization" << endl;
        return ret;
    }
    //합이 k 이하가 될 때까지 가져가기
    //만약 모든 자식이 0,c 꼴이면 0,sum(c)+1 리턴
    ret = {0, 0};
    for (int curSum = 0, i = 0; xTop - i >= -1 && curSum <= k; curSum += x[xTop - i], i++)
    {
        int tempCurSum = curSum;
        for (int j = 0; yTop - j >= -1 && curSum <= k; curSum += y[yTop - j], j++)
        {
            if (i == 0 && j == 0) //각 더미에서 0장, 0장 가져가는 경우 제외
                continue;
            ret = ret + takeCard(xTop - i, yTop - j, !isMyTurn);
        }
        curSum = tempCurSum;
    }
    cout << "result takeCard(" << xTop << ", " << yTop << "): " << ret.first << ", " << ret.second << endl;
    assert(!(ret.first == 0 && ret.second == 0));
    if (ret.first == 0)
        ret = ret + make_pair(0, 1);
    else if (ret.second == 0)
        ret = ret + make_pair(1, 0);
    return ret;
}

int main(int argc, char **argv)
{
    //cintie;

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
        const pii initVal = {-1, -1};
        fill(&dp[0][0][0], &dp[0][0][0] + MAX * MAX * 2, initVal); //초기화 범위 맞나?
        pii res = takeCard(n - 1, n - 1, true);
        /////////////////////////////////////////////////////////////////////////////////////////////
        // Print the answer to standard output(screen).
        cout << "Case #" << test_case + 1 << endl;
        cout << res.first << ' ' << res.second << endl;
    }

    return 0; //Your program should return 0 on normal termination.
}
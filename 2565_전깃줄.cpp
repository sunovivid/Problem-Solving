/**
 * lds면 전깃줄이 교차함. 오직 lis일때만 교차하지 않음 -> 내 코드의 해답이 문제 조건을 만족시키나 다시 한번 생각해 보자
 * a[0] = -inf추가했으면 그에 맞게 base case, for문 n에 +1해주고 답에서는 1빼줘야
 **/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define INF 987654321

using namespace std;

/* 문제 정의
자연수 순서쌍 n개 -> 전깃줄이 겹치지 않도록 하기 위해 지워야 하는 최소 전깃줄 개수
 */

/* 해결 알고리즘 생각
함수의 대응 관계 그림으로 생각
함수가 증가/감소면 교차 없음
답 = 전체 전깃줄 개수 - max(lis길이,lds길이) 
*/

/* 시간복잡도

*/

int n, dp[102];
vector<int> a;

int lis(int begin)
{
    if (begin == n)
        return 1;
    int &ret = dp[begin];
    if (ret != -1)
        return ret;
    ret = 1;
    for (int i = begin + 1; i <= n; i++)
    {
        if (a[i] > a[begin])
            ret = max(ret, 1 + lis(i));
    }
    return ret;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    int x, y;
    vector<pair<int, int>> input;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        input.push_back({x, y});
    }
    sort(input.begin(), input.end());
    a.push_back(-INF);
    for (auto x : input)
    {
        a.push_back(x.second);
    }
    ///////////////////solution//////////////////
    memset(dp, -1, sizeof(dp));
    cout << n - lis(0) + 1;
    ////////////////////output///////////////////

    return 0;
}
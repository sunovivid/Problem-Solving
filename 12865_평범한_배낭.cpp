/**
 * 5% 틀렸습니다: dp 함수에서 base condition체크가 &ret 확인보다 먼저 (아니면 배열 이상한 인덱스 참조하는데 에러 안띄워서 우연히 맞을수도)
 * 18% 틀렸습니다: 아무것도 해당되지 않는 경우 v 전부 다 더하고 -999한 것으로 리턴함
 *  방지법: inf를 애매한 숫자 말고 매우 작게(-987654321은 모든 최대 v값 전부 더해도 음수가 돼서 리턴값 음수 = 아무것도 해당되지 않는 경우로 판단 가능하다)
 *          아무것도 해당되지 않는 경우 동작 예상하기
 **/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX

using namespace std;

/* 문제 정의
 ->
 */

/* 해결 알고리즘 생각

*/

/* 시간복잡도

*/
int dp[102][100'002], n;
vector<int> w, v;

int knapsack(int item, int k) //0~item번째 물건을 고려할 때 총 넣을 수 있는 물건의 가치의 최댓값
{
    if (k < 0) //엣지 케이스에선 dp 범위를 벗어나므로 엣지 케이스 처리가 먼저 (글로벌배열값이라 에러 없이 실행되니 주의)
        return -987654321;
    if (item == n)
        return 0;
    int &ret = dp[item][k];
    if (ret != -1)
        return ret;
    return ret = max(v[item] + knapsack(item + 1, k - w[item]), knapsack(item + 1, k));
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int k;
    cin >> n >> k;
    w.clear();
    v.clear();
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        w.push_back(x);
        v.push_back(y);
    }
    ///////////////////solution//////////////////
    memset(dp, -1, sizeof(dp));
    cout << max(0, knapsack(0, k));
    ////////////////////output///////////////////

    return 0;
}
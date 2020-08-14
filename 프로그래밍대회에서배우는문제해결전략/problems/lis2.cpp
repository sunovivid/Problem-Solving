#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 501

using namespace std;

/* 문제 정의
수열 -> 최대 순증가 부분 수열
 */

/* 해결 알고리즘 생각
dp
*/

/* 시간복잡도

*/
int dp[MAX];
vector<int> v;

int lis2(const int start)
{
    int &ret = dp[start + 1];
    if (ret != -1)
        return ret;
    ret = 1;
    for (int i = start + 1; i < v.size(); i++)
    {
        if (start == -1 || v[i] > v[start])
            ret = max(ret, 1 + lis2(i));
    }
    return ret;
}

int lis(const vector<int> v)
{
    /**
     * 주어진 수열의 0..n번째에서 시작 원소 하나 선택
     * 선택한 원소 뒤의 원소들 중 더 큰 원소들 선택해서 수열 만들기
     *  만든 수열로 다시 lis 호출
     * */
    if (v.size() == 0)
        return 0;

    int ret = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int selected = v[i];
        vector<int> next;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] > v[i])
                next.push_back(v[j]);
        }
        ret = max(ret, 1 + lis(next));
    }
    return ret;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int c;
    cin >> c;
    ///////////////////solution//////////////////
    while (c--)
    {
        int n;
        cin >> n;
        v = vector<int>();
        v.clear();
        memset(dp, -1, sizeof(dp));
        while (n--)
        {
            int in;
            cin >> in;
            v.push_back(in);
        }
        cout << lis2(-1) - 1 << '\n'; //v[-1] = -INF 로 생각하는 테크닉 => main에서 lis2 호출할 때 for문 돌려야 할 필요 없어짐 (가상으로 -INF부터 시작하는 수열을 만들음)
    }
    ////////////////////output///////////////////

    return 0;
}
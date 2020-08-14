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
vector<int> a;
vector<int> b;

const long long NEGINF = numeric_limits<long long>::min(); //64비트 signed 정수형 사용해 입력에 등장하지 않는 최솟값 사용

int dp[101][101];

int jlis(int aStart, int bStart)
{
    int &ret = dp[aStart + 1][bStart + 1];
    if (ret != -1)
        return ret;
    ret = 2;
    long long aElem = (aStart == -1 ? NEGINF : a[aStart]); //-1부터 시작하는 테크닉으로 한 배열만 사용하는 경우도 ok (그런 경우는 없겠지만)
    long long bElem = (bStart == -1 ? NEGINF : b[bStart]);
    long long maxElem = max(aElem, bElem); //둘 중 큰 원소가 뒤에 온다고 생각
    for (int i = aStart + 1; i < a.size(); i++)
    {
        if (a[i] > maxElem)
            ret = max(ret, 1 + jlis(i, bStart));
    }
    for (int i = bStart + 1; i < b.size(); i++)
    {
        if (b[i] > maxElem)
            ret = max(ret, 1 + jlis(aStart, i));
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
        int n, m;
        cin >> n >> m;
        a.clear();
        b.clear();
        memset(dp, -1, sizeof(dp));
        int in;
        while (n--)
        {
            cin >> in;
            a.push_back(in);
        }
        while (m--)
        {
            cin >> in;
            b.push_back(in);
        }
        cout << jlis(-1, -1) - 2 << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}
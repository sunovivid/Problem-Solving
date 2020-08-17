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
정수 수열, 자연수 s -> 수열을 s개 수로 양자화할 때 오차 제곱의 합의 최소 
 */

/* 해결 알고리즘 생각
완전탐색
    재귀 quantize(A): A에 속한 수를 양자화해서 얻는 오차제곱합최소
        사용 가능한 숫자 정보가 없으면 재귀적으로 작성 불가능
    재귀 quantize(A, U) : A에 속한 수를 양자화해서 얻는 오차제곱합최소 (U: 지금까지 한 번 이상 사용한 숫자들)
        경우의 수가 너무 많음
            답의 형태 강제하자
    a<b에 대해 a->x,b->y로 양자화할 때 x>y이면 답이 될 수 없음(바꾼 게 더 작으므로)
        일반화: 입력을 정렬하면 같은 수로 양자화되는 수들은 항상 인접해 있음 
            정렬 후 s개 묶음으로 나누는 문제로 치환가능
                
*/

/* 시간복잡도

*/
vector<int> a;
vector<int> pSum;
vector<int> pSqSum;

int dp[101][11];

inline int minError(const int from, const int until)
{
    int sum = pSum[until - 1] - (from == 0 ? 0 : pSum[from - 1]);
    int sqSum = pSqSum[until - 1] - (from == 0 ? 0 : pSqSum[from - 1]);
    int mean = int(0.5 + (double)sum / (until - from));
    int ret = sqSum - 2 * mean * sum + mean * mean * (until - from); //반올림한 mean이라 항을 합할 수 없음
    // cout << '\t' << sum << ' ' << sqSum << ' ' << mean << endl;
    // cout << "\tMINERROR (from, until) = " << from << ' ' << until << " = " << ret << endl;
    return ret;
    // //평균 구하기
    // int mean = (int)((pSum[until - 1] - ((from == 0) ? 0 : pSum[from - 1])) / (double)(until - from) + 0.5);
    // //오차제곱의 합 구하기
    // int err = pSqSum[until - 1] - ((from == 0) ? 0 : pSqSum[from - 1]) - (until - from) * mean * mean;
    // cout << "\tMINERROR (from, until) = " << from << ' ' << until << " = " << err << endl;
    // return err;
}

int quantize(const int from, const int s)
{
    // cout << "QUANTIZE from, s = " << from << ' ' << s << endl;
    if (from == a.size())
        return 0;
    if (s == 0)
        return INF;
    int &ret = dp[from][s];
    if (ret != -1)
        return ret;
    ret = INF;
    for (int nextFrom = from + 1; nextFrom <= a.size(); nextFrom++)
    {
        ret = min(ret, minError(from, nextFrom) + quantize(nextFrom, s - 1));
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
        //입력
        int n, s;
        cin >> n >> s;
        int in;
        a.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> in;
            a.push_back(in); //*************이걸 i로 써서 두시간 헤맸음
        }
        sort(a.begin(), a.end());
        //부분합 구하기
        pSum.clear();
        pSqSum.clear();
        pSum.push_back(a[0]);
        pSqSum.push_back(a[0] * a[0]);
        for (int i = 1; i < n; i++)
        {
            pSum.push_back(pSum[i - 1] + a[i]);
            pSqSum.push_back(pSqSum[i - 1] + a[i] * a[i]);
        }

        // for (auto x : a)
        //     cout << x << ' ';
        // cout << endl;
        // for (auto x : pSqSum)
        //     cout << x << ' ';
        // cout << endl;
        // for (auto x : pSqSum)
        //     cout << x << ' ';
        // cout << endl;

        memset(dp, -1, sizeof(dp));
        cout << quantize(0, s) << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}
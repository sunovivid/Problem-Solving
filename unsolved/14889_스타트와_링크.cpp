#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 22
#define INF 987654321

using namespace std;

/* 문제 정의
nxn 행렬 -> Sij합 차이의 최솟값
n<=20
 */

/* 해결 알고리즘 생각
모든 조합 확인 nCn/2 = O(n^5)?으로 해결 가능

전처리
Tij = Sij + Sji
i  1 2 3 4  sum
---------------
1  0 5 9 6  20
2  5 0 6 10 21
3  9 6 0 7  22
4  6 107 0  23

0, 1, 2, 3으로 썼어야..
*/

int s[MAX][MAX] = {
    0,
};
int sum[MAX] = {
    0,
};
int permu_team1[MAX];
int n, diff = 0;

int findMinDiff(int index, int lower_bound)
{
    if (diff < 0)
        return INF;

    if (index == n / 2)
    {
        return abs(diff);
    }
    assert(index < n / 2);

    int minDiff = INF;
    for (int i = lower_bound; i < n; i++)
    {
        diff -= sum[i];
        minDiff = min(minDiff, findMinDiff(index + 1, i + 1));
        diff += sum[i];
    }
    return minDiff;
}

int main()
{
    ////////////////////input////////////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            s[i][j] += temp;
            s[j][i] += temp;
            diff += temp;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sum[i] += s[i][j];

    ///////////////////solution//////////////////
    int result = findMinDiff(0, 0);

    ////////////////////output///////////////////
    cout << result;

    return 0;
}

/*legacy



*/
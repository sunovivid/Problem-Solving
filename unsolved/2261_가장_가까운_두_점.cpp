#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX
#define INDEXBUF 10000

using namespace std;

/* 문제 정의
n개 2차원 좌표 -> 거리가 가장 가까운 두 점 
 */

/* 해결 알고리즘 생각
분할 정복 O(nlgn)
공간을 4분할해서 두 점을 이은 선이 분할선을 지나는 경우를 O(n)만에 찾으면 됨
    x좌표 -> y좌표 벡터, y좌표 -> x좌표 벡터를 따로 만들어서 구하기
*/

/* 시간복잡도
O(nlgn)
*/

vector<vector<int>> xArray;
vector<vector<int>> yArray;

long long findMinDist(int left, int right, int bot, int top)
{
    if (left + 1 == right)
    {
        assert(bot + 1 == top);
        if (xArray[])
    }
    int center = (left + right) / 2, mid = (top + bot) / 2;
    long long ret = 987654321;
    ret = min(ret, findMinDist(left, center, bot, mid));
    ret = min(ret, findMinDist(center + 1, right, bot, mid));
    ret = min(ret, findMinDist(left, center, mid + 1, top));
    ret = min(ret, findMinDist(center + 1, right, mid + 1, top));
    int lo = center, hi = center + 1;
    while ()
    {
        if (!yArray[lo].empty())
    }
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    xArray = vector<vector<int>>(10001 + INDEXBUF); //범위 overflow확인
    yArray = vector<vector<int>>(10001 + INDEXBUF);
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        xArray[x + INDEXBUF].push_back(y);
        yArray[y + INDEXBUF].push_back(x);
    }
    ///////////////////solution//////////////////
    findMinDist(-10000, -10000, 10000, 10000);
    ////////////////////output///////////////////

    return 0;
}
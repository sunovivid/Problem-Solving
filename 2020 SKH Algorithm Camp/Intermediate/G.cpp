/*
정해: 2차원 DP[i][j] (i층, 마지막으로 올라온 층 개수가 2^j층) + **세그먼트 트리** (많은 최댓값 쿼리)
*/

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
쿼리 n개 - 각 쿼리: 입주 가능한 층의 범위 -> 입주 가능한 층 중 도달 최솟값
 */

/* 해결 알고리즘 생각
    각 층수별 도달하기 위한 버튼 수 구해놓고, 쿼리 들어오면 최솟값
        => 시간초과?
    dp[i][j] = (쿼리 i,j의 결과)
    dp[i][j] = min(dp[i-1][j-1], arr[i])
        => O(N^2) 시간초과?

    쿼리 들어오면 그리디하게 처리

*/

/* 시간복잡도

*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ///////////////////solution//////////////////

    ////////////////////output///////////////////

    return 0;
}
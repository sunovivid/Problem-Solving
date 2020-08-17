/**
 * 중요한 아이디어: 
 * 각 부분문제에서 한 칸씩만 떼주고 넘기면 모든 케이스 확인 가능
 * 
 * case1: 문자 같으면 무조건 lcs에 포함 (그렇지 않으면 최장 길이가 아님을 귀류법으로 보일 수 있다)
 * case2: 문자 다르면 lcs(a+1,b),lcs(a,b+1) 비교 (매번 양쪽의 문자 중 하나를 택하므로 모든 케이스 커버 가능)
 * for문 돌려서 조건 만족하는 것만 찾아서 재귀할 게 아니라,
 * 현재 상황에서 조건 만족하면 편하게 가고, 아니면 다음 스텝으로 천천히 넘어가자
 * 
 * 여기서는 반복 덩어리 기준이 '같은 문자로 시작하는' 두 부분 문자열 인덱스가 아니라
 * 그냥 두 부분 문자열 인덱스
 **/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 1002

using namespace std;

/* 문제 정의
수열 2개 -> 최장 공통 부분 수열 구하기
 */

/* 해결 알고리즘 생각
lcs(a,b) = (a, b에서 시작하는 lcs 길이)
lcs(a,b) = 
    if (s1[a+1] == s2[b+1]) lcs(a+1,b+1) //같으면 남은 문자열 재귀적으로 비교하기
    else max(lcs(a+1,b), lcs(a,b+1)) //다르면 s1을 한칸 뒤로 넘긴것과, s2를 한칸 뒤로 넘긴 것 비교하기
한칸씩 뒤로 전진하므로 이것으로 모든 케이스 확인을 문제당 O(1)만에 가능

*/

/* 시간복잡도
O(nm)
부분문제 nm개
각 문제당 O(1)
*/
string s1, s2;
int dp[MAX][MAX];

int lcs(int a, int b)
{
    int &ret = dp[a][b];
    if (a == s1.length() || b == s2.length())
        return 0;
    if (ret != -1)
        return ret;
    ret = 0;
    if (s1[a] == s2[b])
        ret = 1 + lcs(a + 1, b + 1); //추가
    else
        ret = max(ret, max(lcs(a + 1, b), lcs(a, b + 1))); //탐색
    return ret;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s1 >> s2;
    ///////////////////solution//////////////////
    memset(dp, -1, sizeof(dp));
    cout << lcs(0, 0);
    ////////////////////output///////////////////

    return 0;
}
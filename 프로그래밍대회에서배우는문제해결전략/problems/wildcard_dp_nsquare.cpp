#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 101

using namespace std;

/* 문제 정의
문자열, 문자열 n개 -> n개 중 매칭되는 문자열
매칭: 와일드카드 ?,*
 */

/* 해결 알고리즘 생각
와일드카드 *에 몇 개의 문자도 대응될 수 있는 점이 문제를 어렵게 만든다
*에 문자를 0,1,2...n개 모두 대응시켜봐서 하나라도 되면 된다
    => i개 대응시키고 뒤에 문제는 같은 구조의 부분 문제이므로 재귀적으로 구현하자

개선1: DP

개선2: O(n^3) -> O(n^2)
match마다 O(1)이 걸리도록 수정
*/

/* 시간복잡도
O(n^3) : n-문자열의 길이
부분 문제 n^2개, match마다 O(n) 시간소요
*/

int dp[MAX][MAX];
string pattern, str;

bool match(int pi, int si)
{
    int &ret = dp[pi][si];
    if (ret != -1)
        return ret;
    //한 글자씩 비교 검사
    if (pi < pattern.length() && si < str.length() && (pattern[pi] == '?' || pattern[pi] == str[si]))
    {
        return ret = match(pi + 1, si + 1);
    }
    /* while 문이 끝나는 경우:
     * 1. w 문자열의 끝
     * 2. s 문자열만 끝
     * 3. w가 *를 만남
     * 4. w[pos] != s[pos]
     */
    //case 1
    if (pi == pattern.length())
    {
        return ret = (si == str.length());
    }
    // if (pos == str.length()) case2는 나중에 한번에 처리
    //     return false;
    // case 3
    if (pattern[pi] == '*')
    {
        if (match(pi + 1, si) || (si < str.length() && match(pi, si + 1)))
            return ret = 1;
        // for (int skip = 0; si + skip <= str.length(); skip++) // <=으로 비교해야 *에 남은 문자열 전부 대응시키는 것까지 커버
        // {
        //     if (match(pi + 1, si + skip))
        //         return ret = 1;
        // }
    }
    //case 2,4
    return ret = 0;
    //설계 테크닉: true되는 경우만 체크하고 나머지를 모두 false로
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
        cin >> pattern;
        int n;
        cin >> n;
        vector<string> answer;
        while (n--)
        {
            cin >> str;
            memset(dp, -1, sizeof(dp));
            if (match(0, 0))
                answer.push_back(str);
        }
        sort(answer.begin(), answer.end());
        for (auto str : answer)
            cout << str << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}
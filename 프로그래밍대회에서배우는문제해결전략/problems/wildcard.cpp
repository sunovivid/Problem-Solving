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
문자열, 문자열 n개 -> n개 중 매칭되는 문자열
매칭: 와일드카드 ?,*
 */

/* 해결 알고리즘 생각
와일드카드 *에 몇 개의 문자도 대응될 수 있는 점이 문제를 어렵게 만든다
*에 문자를 0,1,2...n개 모두 대응시켜봐서 하나라도 되면 된다
    => i개 대응시키고 뒤에 문제는 같은 구조의 부분 문제이므로 재귀적으로 구현하자
*/

/* 시간복잡도

*/

bool match(string pattern, string str)
{
    int pos = 0;
    //한 글자씩 비교 검사
    while (pos < pattern.length() && pos < str.length() && (pattern[pos] == '?' || pattern[pos] == str[pos]))
    {
        pos++;
    }
    /* while 문이 끝나는 경우:
     * 1. w 문자열의 끝
     * 2. s 문자열만 끝
     * 3. w가 *를 만남
     * 4. w[pos] != s[pos]
     */
    //case 1
    if (pos == pattern.length())
    {
        return pos == str.length();
    }
    // if (pos == str.length()) case2는 나중에 한번에 처리
    //     return false;
    // case 3
    if (pattern[pos] == '*')
    {
        for (int skip = 0; pos + skip <= str.length(); skip++) // <=으로 비교해야 *에 남은 문자열 전부 대응시키는 것까지 커버
        {
            if (match(pattern.substr(pos + 1), str.substr(pos + skip)))
                return true;
        }
    }
    //case 2,4
    return false;
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
        string pattern;
        cin >> pattern;
        int n;
        cin >> n;
        while (n--)
        {
            string filename;
            cin >> filename;
            cout << (match(pattern, filename) ? (filename + '\n') : "");
        }
    }
    ////////////////////output///////////////////

    return 0;
}
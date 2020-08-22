/**
 * 에러1: 3%, '마이너스가 없는 경우' - 아무것도 없는 경우 체크 안헀다
 * 에러2: cout 수정 x
 * 문자열 부분부분 처리하는 건 재귀함수 인자로 string 넘겨서 간결하게 작성하기
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
0~9, +, -로 이루어진 문자열 (수식) -> 식의 값의 최솟값
 */

/* 해결 알고리즘 생각
()를 이용해 모든 +를 최대한 많이 -로 바꾸어야.
-가 등장하면 다음 -가 등장할 때까지 전부 괄호로 묶기
구현: 수를 차례대로 담고, (최초로 등장하는 - 전 수를 모두 더한 것) - (최초로 등장하는 - 다음 수를 모두 더한 것) 이 답
(최초 -등장하면 뒤에 - 몇 개가 등장하든 모두 묶어서 음수로 만들 수 있으므로)
*/

/* 시간복잡도
O(n)
*/

int getNumberSum(const string s)
{
    // cout << "getNumberSum " + s << endl;
    if (s == "")
        return 0;
    size_t nextOpPos = min(s.find('-'), s.find('+'));
    if (nextOpPos == string::npos)
        return stoi(s.substr(0, nextOpPos));
    return stoi(s.substr(0, nextOpPos)) + getNumberSum(s.substr(nextOpPos + 1, string::npos));
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int sum = 0;
    size_t pos = 0, nextPos = 0, firstMinusPos = s.find("-");
    if (firstMinusPos == string::npos)
    {
        cout << getNumberSum(s);
        return 0;
    }
    cout << getNumberSum(s.substr(0, firstMinusPos)) - getNumberSum(s.substr(firstMinusPos + 1, s.length() - firstMinusPos - 1));
    ///////////////////solution//////////////////

    ////////////////////output///////////////////

    return 0;
}
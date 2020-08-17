#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>
#include <tuple>

#define MAX

using namespace std;

/* 문제 정의
 ->
 */

/* 해결 알고리즘 생각

*/

/* 시간복잡도

*/
string s;

int classify(int begin, int end)
{
    //모든 숫자가 같을 때
    bool isCaseMatch = true;
    for (int i = begin + 1; i < end; i++)
        if (s[begin] != s[i])
        {
            isCaseMatch = false;
            break;
        }
    if (isCaseMatch)
        return 1;
    //숫자가 1씩 단조증가/단조감소
    isCaseMatch = true;
    for (int i = begin + 2; i < end; i++)
        if (s[i] - s[i - 1] != 1)
        {
            isCaseMatch = false;
            break;
        }
    if (isCaseMatch)
        return 2;
    //두 개 숫자 번갈아 출현
    isCaseMatch = true;
    int a = s[begin];
    int b = s[begin + 1];
    for (auto [i, isATurn] = tuple{begin + 2, true}; i < end; i++, isATurn = !isATurn)
    {
        if (isATurn && s[i] == a || !isATurn && s[i] == b)
        {
            isCaseMatch = false;
            break;
        }
    }
    if (isCaseMatch)
        return 4;
    //등차 수열
    isCaseMatch = true;
    int diff = s[begin + 1] - s[begin];
    for (int i = begin + 2; i < end; i++)
        if (s[i] - s[i - 1] != diff)
        {
            isCaseMatch = false;
            break;
        }
    if (isCaseMatch)
        return 5;
    return -1;
}

int memorize(int begin)
{
    if (begin == s.length())
        return 0;
    int ret = 0;
    for (int i = 3; i <= 5; i++)
    {
        ret = max(ret, classify(begin, begin + i) + memorize(begin + i));
    }
    return ret;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ///////////////////solution//////////////////
    int c;
    cin >> c;
    while (c--)
    {
        cin >> s;
        cout << memorize(0) << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}
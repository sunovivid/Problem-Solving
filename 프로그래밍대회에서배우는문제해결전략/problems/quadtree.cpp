/*
* iterator를 참조형으로 전달해 전역변수처럼 사용할 수 있다. (리턴 따로 안해도 영향 줌)
* 문제를 분할해 재귀적으로 해결하고, 베이스 케이스와 병합 방법만 정의하면 생각보다 쉽게 문제가 풀린다
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
쿼드트리 문자열 -> 원본 이미지를 뒤집은 쿼드트리 문자열
 */

/* 해결 알고리즘 생각

*/

/* 시간복잡도

*/
string reverse(string::iterator &it)
{
    char head = *it;
    it++;
    if (head == 'b' || head == 'w')
        return string(1, head);
    string upLeft = reverse(it);
    string upRight = reverse(it);
    string downLeft = reverse(it);
    string downRight = reverse(it);
    return string(1, 'x') + downLeft + downRight + upLeft + upRight;
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
        string qtree;
        cin >> qtree;
        string::iterator it = qtree.begin();
        cout << reverse(it) << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}
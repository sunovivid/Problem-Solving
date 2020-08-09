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
5x5 문자 배열 -> 연결 단어 찾기
 */

/* 해결 알고리즘 생각

*/

/* 시간복잡도

*/
char map[5][5];

const int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[] = {-1, 0, 1, -1, 0, 1, -1, 1};

bool hasWord(int y, int x, const string &word)
{
    //base case
    if (y < 0 || y >= 5 || x < 0 || x >= 5) //tip: 범위에서 벗어난 경우도 재귀함수 안에서 처리
        return false;
    if (map[y][x] != word[0]) //일치 안하면 false
        return false;
    if (word.size() == 1) //길이 1이고 일치하는 경우 true
        return true;
    //재귀
    for (int dir = 0; dir < 8; dir++)
        if (hasWord(y + dy[dir], x + dx[dir], word.substr(1)))
            return true;
    return false;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ///////////////////solution//////////////////
    int t;
    cin >> t;
    while (t--)
    {
        //input
        for (int i = 0; i < 5; i++)
            cin >> map[i];
        int n;
        cin >> n;

        //solve
        string word;
        while (n--)
        {
            cin >> word;
            bool isExist = false;
            for (int i = 0; !isExist && i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (hasWord(i, j, word))
                    {
                        isExist = true;
                        break;
                    }
                }
            }
            cout << (isExist ? "YES" : "NO") << '\n';
        }
    }
    ////////////////////output///////////////////

    return 0;
}
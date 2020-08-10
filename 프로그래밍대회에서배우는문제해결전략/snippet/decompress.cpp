#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 99999999

using namespace std;

/* 문제 정의
 ->
 */

/* 해결 알고리즘 생각

*/

/* 시간복잡도

*/
char decompressed[MAX][MAX];
char decompress(string::iterator &it, int y, int x, int size)
{
    char head = *(it++);
    if (head == 'b' || head == 'w')
    {
        for (int dy = 0; dy < size; dy++)
        {
            for (int dx = 0; dx < size; dx++)
            {
                decompressed[y + dy][x + dx] = head;
            }
        }
    }
    else
    {
        int half = size / 2;
        decompress(it, y, x, half);
        decompress(it, y, x + half, half);
        decompress(it, y + half, x, half);
        decompress(it, y + half, x + half, half);
    }
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ///////////////////solution//////////////////

    ////////////////////output///////////////////

    return 0;
}
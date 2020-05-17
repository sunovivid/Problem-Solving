#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>

#define MAX 11

using namespace std;

/* 문제 정의
수 -> 자리수 내림차순 정렬
 */

/* 해결 알고리즘 생각
문자열로 입력받아 sort
*/

bool desc(int a, int b)
{
    return a > b;
}

int main()
{
    ////////////////////input////////////////////
    // cin.tie(NULL);
    // ios_base::sync_with_stdio(false);

    char input[MAX], c;
    int index = 0;
    while (1)
    {
        char c;
        scanf("%c", &c);
        if (c == '\0' || c == '\n')
            break;
        input[index++] = c;
    }

    ///////////////////solution//////////////////
    sort(input, input + index, desc);

    ////////////////////output///////////////////
    for (int i = 0; i < index; i++)
        printf("%c", input[i]);

    return 0;
}

/*legacy



*/
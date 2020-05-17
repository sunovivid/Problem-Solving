#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

#define MAX 10001

using namespace std;

/* 문제 정의
수 정렬하기 (개수는 많고 숫자 범위는 좁을 때)
N <= 10^8, 메모리 제한 8MB = 8*10^6 byte
 */

/* 해결 알고리즘 생각
signed/unsigned int = 4byte, 2*10^6개 int
signed/unsigned short = 2byte, 4*10^6개 short 
*/

int main()
{
    ////////////////////input////////////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, num, input[MAX];
    memset(input, 0, sizeof(input));

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        input[num]++;
    }
    ///////////////////solution//////////////////
    for (int i = 1; i < MAX; i++)
    {
        num = input[i];
        while (num--)
        {
            cout << i << '\n';
        }
    }

    ////////////////////output///////////////////

    return 0;
}

/*legacy



*/
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
 ->
 */

/* 해결 알고리즘 생각

*/

/* 시간복잡도

*/
void printIfIsMagicNumber(int n)
{
    int digitSum[3] = {0, 0, 0};
    int digitNum[3] = {10, 12, 16};
    for (int index = 0; index < 3; index++)
    {
        for (int i = n; i > 0; i /= digitNum[index])
        {
            digitSum[index] += (i % digitNum[index]);
        }
    }
    if (digitSum[0] == digitSum[1] && digitSum[1] == digitSum[2])
        cout << n << '\n';
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ///////////////////solution//////////////////
    for (int n = 2992; n <= 9999; n++)
        printIfIsMagicNumber(n);
    ////////////////////output///////////////////

    return 0;
}
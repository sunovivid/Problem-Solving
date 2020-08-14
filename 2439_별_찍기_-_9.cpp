#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX
#define abs(a) ((a >= 0) ? (a) : -(a))

using namespace std;

/* 문제 정의
 ->
 */

/* 해결 알고리즘 생각

*/

/* 시간복잡도

*/
void printLine(int n, int i)
{
    // cout << i << '\n';
    for (int j = 1; j <= i - 1; j++)
        cout << ' ';
    for (int j = 1; j <= 2 * (n - i) + 1; j++)
        cout << '*';
    cout << '\n';
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    ///////////////////solution//////////////////
    for (int i = 1; i <= 2 * n - 1; i++)
        printLine(n, n - abs(n - i));
    ////////////////////output///////////////////

    return 0;
}
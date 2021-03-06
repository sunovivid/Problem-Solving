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

void printStar(int k)
{
    if (k == 0)
    {
        cout << '\n';
        return;
    }
    cout << '*';
    printStar(k - 1);
}

void printStarLine(int n, int k)
{
    if (k <= 0)
        return;
    printStar(n + 1 - k);
    printStarLine(n, k - 1);
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    ///////////////////solution//////////////////
    printStarLine(n, n);

    ////////////////////output///////////////////

    return 0;
}
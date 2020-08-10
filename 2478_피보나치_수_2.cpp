#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 95

using namespace std;

/* 문제 정의
 ->
 */

/* 해결 알고리즘 생각

*/

/* 시간복잡도

*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long fibo[MAX] = {0, 1};
    ///////////////////solution//////////////////
    for (int i = 2; i <= 90; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    ////////////////////output///////////////////
    long long n;
    cin >> n;
    cout << fibo[n];
    return 0;
}
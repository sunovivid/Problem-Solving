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
정수 a,b,c,d,e,f -> 정수 x,y
ax + by = c
dx + ey = f 만족
 */

/* 해결 알고리즘 생각
가우스 소거법
*/

/* 시간복잡도
O(1)
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    ///////////////////solution//////////////////
    long long int x, y;
    if (a == 0)
    {
        assert(b != 0);
        y = c / b;
        assert(d != 0);
        x = (f - e * y) / d;
    }
    else
    {
        assert(e != d);
        y = (f - d) / (e - d);
        x = (c - b * y) / a;
    }
    ////////////////////output///////////////////
    cout << x << ' ' << y;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX

using namespace std;

/* 문제 정의
좌표 x,y -> 0,0으로 만드는 데 필요한 액션 수 p, q
액션:
상하좌우 +-1
대각선 이동 (/)
 */

/* 해결 알고리즘 생각

*/

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int testcase;
    long long x, y, a, b;
    long long sum;
    cin >> testcase;
    while (testcase--)
    {
        sum = 0;
        cin >> x >> y >> a >> b;
        if (b < 2 * a)
        {
            long long temp = min(x, y);
            sum += temp * b;
            // cout << sum << endl;
            x -= temp;
            y -= temp;
            // cout << x << y << endl;
            sum += (x + y) * a;
            // cout << sum << endl;
        }
        else
        {
            sum += (x + y) * a;
        }
        cout << sum << '\n';
    }
    return 0;
}

/*legacy



*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* 문제 정의
a,b,c,d -> x,y,z 아무거나
xyz는 abcd사이
삼각형이 만들어져야함
즉 x + y > z, x + z > y, y + z > x
x < y < z이므로 x + y > z 만 만족하면 다 만족할듯
 */

/* 해결 알고리즘 생각
x = b, y = c, z = c
나중에 시간나면 반례 있는지 생각해보자.
*/

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    int a, b, c, d;
    cin >> T;
    while (T--)
    {
        cin >> a;
        cin >> b;
        cin >> c;
        cin >> d;
        cout << b << ' ' << c << ' ' << c << '\n';
    }

    return 0;
}
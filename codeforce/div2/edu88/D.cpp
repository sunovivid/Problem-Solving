#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX

using namespace std;

/* 문제 정의
h, c, t -> h * x + c * y / (x + y) (산술평균)이 
t에 가장 가깝도록 하는 x+y구하기
 */

/* 해결 알고리즘 생각
greedy
목표에 점점 가까워지도록 뜨거운물, 찬물 타서 오차가 더 커지기 직전 그만두기
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T, h, c, t, last_absdiff, x, y;
    cin >> T;
    ///////////////////solution//////////////////
    while (T--)
    {
        cin >> h >> c >> t;
        if (h == t || c == t)
        {
            cout << 1 << '\n';
            continue;
        }
        x = y = 1;
        char last_dir = 'a';
        while (1)
        {
            int target = t * (x + y);
            int current = h * x + c * y;
            int absdiff = abs(target - current);
            // cout << "target: " << target << ", current: " << current << " absdiff: " << absdiff << endl;
            if (current < target)
            {
                if (absdiff * (x + y - 1) < abs(h * (x - 1) + c * y - t * (x + y - 1)) * (x + y))
                {
                    cout << x + y - 1 << '\n';
                    break;
                }

                x++;
                last_dir = 'x';
            }
            else if (current > target)
            {

                if (absdiff * (x + y - 1) < abs(h * x + c * (y - 1) - t * (x + y - 1)) * (x + y))
                {
                    cout << x + y - 1 << '\n';
                    break;
                }
                y++;
                last_dir = 'y';
            }
            else
            {
                cout << x + y << '\n';
                break;
            }
        }
    }
    ////////////////////output///////////////////

    return 0;
}

/*legacy



*/
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
    int T, h, c, t, x, y;
    cin >> T;
    ///////////////////solution//////////////////
    while (T--)
    {
        cin >> h >> c >> t;
        if (h == t)
        {
            cout << 1 << '\n';
            continue;
        }
        x = 1, y = 0;
        char turn = 'y';
        double last_absdiff = 987654321;
        while (1)
        {
            int target = t * (x + y);
            int current = h * x + c * y;
            double absdiff = abs(t - current / (x + y));
            // cout << "target: " << target << ", current: " << current << endl;
            if (turn == 'x') //뜨거운물차례
            {
                if (absdiff >= last_absdiff)
                {
                    cout << x + y - 1 << '\n';
                    break;
                }
                x++;
                turn = 'y';
            }
            else
            { //찬물차례
                if (last_absdiff >= last_absdiff)
                {
                    cout << x + y - 1 << '\n';
                    break;
                }
                y++;
                turn = 'x';
            }
            last_absdiff = absdiff;
        }
    }
    ////////////////////output///////////////////

    return 0;
}

/*legacy



*/
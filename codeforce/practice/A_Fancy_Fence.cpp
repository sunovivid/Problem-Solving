#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX

using namespace std;

/* 문제 정의
각도 -> 정다각형 만들수 있는지 여부
 */

/* 해결 알고리즘 생각
60이상, 360 % n == 0
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t, n;
    cin >> t;
    ///////////////////solution//////////////////
    while (t--) {
        cin >> n;
        cout << ((n >= 60 && 360 % (180 - n) == 0) ? "YES" : "NO") << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}

/*legacy



*/
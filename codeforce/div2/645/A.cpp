#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX

using namespace std;

/* 문제 정의
n,m -> 모든 사각형을 밝히는 데 필요한 램프 수 
 */

/* 해결 알고리즘 생각

*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t, n, m;
    cin >> t;
    ///////////////////solution//////////////////
    while (t--)
    {
        cin >> n >> m;
        if (n * m % 2 == 0)
            cout << (n * m) / 2;
        else
            cout << (n * m) / 2 + 1;
        cout << endl;
    }
    ////////////////////output///////////////////
    return 0;
}

/*legacy



*/
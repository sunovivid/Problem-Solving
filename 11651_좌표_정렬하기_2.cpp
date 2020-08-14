#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>

#define MAX 100001

using namespace std;

/* 문제 정의
(x,y) N개 -> x좌표, y좌표 순으로 정렬
 */

/* 해결 알고리즘 생각

*/

int main()
{
    ////////////////////input////////////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, x, y;
    cin >> n;
    pair<int, int> coord[MAX];
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        coord[i] = {y, x};
    }
    ///////////////////solution//////////////////

    sort(coord, coord + n);

    ////////////////////output///////////////////
    for (int i = 0; i < n; i++)
    {
        cout << coord[i].second << ' ' << coord[i].first << '\n';
    }
    return 0;
}

/*legacy



*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX

using namespace std;

/* 문제 정의
stable sort
 */

/* 해결 알고리즘 생각

*/
typedef pair<int, string> pis;

int main()
{
    ////////////////////input////////////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pis> v(n);
    for (auto &elem : v)
    {
        cin >> elem.first >> elem.second;
    }
    ///////////////////solution//////////////////
    stable_sort(v.begin(), v.end(), [](pis a, pis b) { return a.first < b.first; });
    ////////////////////output///////////////////
    for (auto elem : v)
    {
        cout << elem.first << ' ' << elem.second << '\n';
    }
    return 0;
}

/*legacy



*/
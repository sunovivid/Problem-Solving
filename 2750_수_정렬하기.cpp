#include <iostream>
#include <algorithm>
#include <vector>

#define MAX

using namespace std;

/* 문제 정의
N -> 정렬
 */

/* 해결 알고리즘 생각

*/

int main()
{
    ////////////////////input////////////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<int> arr;
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    ///////////////////solution//////////////////
    sort(arr.begin(), arr.end());

    ////////////////////output///////////////////
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << '\n';
    }
    return 0;
}

/*legacy



*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 55

using namespace std;

/* 문제 정의
수열 -> 복원된 수열
 */

/* 해결 알고리즘 생각
각 숫자는 unique
맨 처음 나오는 것들로만 수열 구성하면 됨
*/

/* 시간복잡도

*/
bool is_visited[55];

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    ///////////////////solution//////////////////
    while (t--) {
        int n, k;
        cin >> n;
        // cout << "TEST " << t << endl;
        memset(is_visited, 0, sizeof(is_visited));
        vector<int> result;
        for (int i=0;i<n*2;i++) {
            cin >> k;
            // cout << "input " << k << endl;
            if (!is_visited[k]) {
                is_visited[k] = true;
                result.push_back(k);
            }
        }
        for (auto x: result) {
            cout << x << ' ';
        }      
        cout << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}
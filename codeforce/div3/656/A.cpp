#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX

using namespace std;

/* 문제 정의
x, y, z -> a, b, c
x = max(a,b) y = max(a,c) z = max(b,c)
 */

/* 해결 알고리즘 생각
정렬
a = x, b = y, c = y미만수
같은 수 두개 이상이 존재하고 가장 큰 수여야
*/

/* 시간복잡도

*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    
    ///////////////////solution//////////////////
    while (t--) {
        int input[3];
        cin >> input[0] >> input[1] >> input[2];
        sort(input, input + 3);
        if (input[0] == input[1] && input[1] == input[2]) {
            cout << "YES" << '\n';
            cout << input[0] << ' ' << input[1] << ' ' << input[2] << '\n';
        }
        else if (input[1] == input[2]) {
            cout << "YES" << '\n';
            cout << input[2] << ' ' << input[0] << ' ' << max(1,input[0]-1) << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
        
    }

    ////////////////////output///////////////////

    return 0;
}
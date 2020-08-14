#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 200005

using namespace std;

/* 문제 정의
수열 -> 증가(감소하지 않음) + 감소(증가하지 않음) 수열로 만들기 위해 제거해야 하는 최소 prefix 길이
 */

/* 해결 알고리즘 생각
쭉 입력받고 뒤에서부터 보면서 증가, 감소, 다시 증가하는 순간의 인덱스가 정답
*/

/* 시간복잡도
O(n)
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
        int n;
        cin >> n;
        int arr[MAX];
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        bool is_increasing = true;
        bool is_found = false;
        // cout << "TESTCASE " << t << endl;
        for (int i=n-1;i>0;i--) {
            if (is_increasing && arr[i-1] < arr[i]) {
                is_increasing = false;
            }
            else if (!is_increasing && arr[i-1] > arr[i]) {
                cout << i << '\n';
                is_found = true;
                break;
            }
        }
        if (!is_found)
            cout << 0 << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}
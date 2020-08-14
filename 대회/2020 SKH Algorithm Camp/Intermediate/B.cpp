#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 2020

using namespace std;

/* 문제 정의
수열 -> '균형잡힌 수열' 되는지 여부, 되면 그 수열까지
 */

/* 해결 알고리즘 생각
'균형잡힌 수열' = 등차수열
정렬 후 공차가 d로 일정한지 확인
일정하면 등차수열 출력
*/

/* 시간복잡도
O(nlogn)
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    ///////////////////solution//////////////////
    int arr[MAX];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int prev_d;
    prev_d = arr[1] - arr[0];
    bool is_balanced = true;
    for (int i=2;i<n;i++) {
        if (arr[i] - arr[i-1] != prev_d) {
            cout << "No" << '\n';
            is_balanced = false;
            break;
        }
        prev_d = arr[i] - arr[i-1];
    }
    if (is_balanced) {
        cout << "Yes" << '\n';
        for (int i=0;i<n;i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}
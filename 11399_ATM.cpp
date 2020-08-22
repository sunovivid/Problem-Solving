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
자연수 수열 -> 누적합 배열의 합의 최솟값
 */

/* 해결 알고리즘 생각
시간이 짧게 걸리는 사람 먼저 (만약 길게 걸리는 사람이 먼저 하는 최적해가 존재하면, 그 사람과 그 사람 뒤의 더 짧게 걸리는 사람의 순서를 바꾼 것이 더 대기시간이 짧으므로 모순)
*/

/* 시간복잡도
O(nlgn)
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ///////////////////solution//////////////////
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (n - i) * arr[i];
    }
    ////////////////////output///////////////////
    cout << sum;
    return 0;
}
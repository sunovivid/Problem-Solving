#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 20005

using namespace std;

/* 문제 정의
펜스 높이의 자연수 수열 -> 최대 직사각형 넓이
 */

/* 해결 알고리즘 생각

*/

/* 시간복잡도

*/
int solve_brute_force(const int n, const int arr[])
{
    int maxArea = 0;
    for (int left = 0; left < n; left++)
    {
        int minHeight = arr[left];
        for (int right = left; right < n; right++)
        {
            minHeight = min(minHeight, arr[right]); //minHeight를 left 마다 따로 쓰면 minHeight(l..r)을 O(k)만에 구할 수 있다.
            maxArea = max(maxArea, (right - left + 1) * minHeight);
        }
    }
    return maxArea;
}

int solve_dnq(const int arr[], const int left, const int right)
{
    if (left == right)
        return arr[left];
    int mid = (left + right) / 2;
    int ret = max(solve_dnq(arr, left, mid), solve_dnq(arr, mid + 1, right));
    int lo = mid, hi = mid + 1;
    int height = min(arr[lo], arr[hi]);
    ret = max(ret, 2 * height);
    while (left < lo || hi < right)
    {
        if (hi < right && (lo == left || arr[lo - 1] < arr[hi + 1]))
        {
            hi++;
            height = min(height, arr[hi]);
        }
        else
        {
            lo--;
            height = min(height, arr[lo]);
        }
        ret = max(ret, (hi - lo + 1) * height);
    }
    return ret;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int c;
    cin >> c;
    ///////////////////solution//////////////////
    while (c--)
    {
        int n;
        cin >> n;
        int arr[MAX];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << solve_brute_force(n, arr) << '\n';
        // cout << solve_dnq(arr, 0, n - 1) << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}
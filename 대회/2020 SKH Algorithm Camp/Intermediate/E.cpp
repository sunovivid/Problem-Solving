/*정해: FFT (실수 계산 유의)
prefix sum 구해서 2ps^3(a)[x] - ps^2(a)[x] = sum{i=0 to x-1} (x-i)^2 * a[i]
*/

// long long int 안써서 overflow로 감점

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 100009

using namespace std;

/* 문제 정의
길이 n 수열 -> k=1부터 n까지 제곱 가중치(sum i = 0 to k - 1 (k-i)^2 * a[i+1])
 */

/* 해결 알고리즘 생각
계차수열 활용
    a[i]의 부분합 구해두기 -> a_psum
    d[i] - d[i-1] = a[i+1] + 2 * a_psum[i] 이용해 d 배열 구하기
    d 배열 이용해 s 배열 구하기
*/

/* 시간복잡도
O(n)
*/

long long int arr[MAX], arr_psum[MAX] = {0, }, d[MAX], s[MAX];

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> arr[i];
        arr_psum[i] = arr_psum[i-1] + arr[i];
    }
    ///////////////////solution//////////////////
    //base case
    if (n == 1) {
        cout << arr[1];
        return 0;
    }
    // else if (n == 2) {
    //     cout << arr[1] << ' ' << 4*arr[1] + arr[2];
    //     return 0;
    // }
    
    d[1] = arr[2] + 3*arr[1]; //arr 1개, 2개일 때
    for (int i=2;i<=n-1;i++) {
        d[i] = d[i-1] + 2 * arr_psum[i] + arr[i+1];
    }
    s[1] = arr[1];
    cout << s[1] << ' ';
    for (int i=2;i<=n;i++) {
        s[i] = s[i-1] + d[i-1];
        cout << s[i] << ' ';
    }
    ////////////////////output///////////////////

    return 0;
}
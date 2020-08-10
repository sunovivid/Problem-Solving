#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 100005

using namespace std;

/* 문제 정의
자연수 M <= 10^5, 길이 N <= 10^5 자연수 수열 -> 인출 횟수 M번을 맞추기 위한 최소 인출 금액 K
 */

/* 해결 알고리즘 생각
무식하게 풀기
    -인출 금액을 모든 금액 합부터 m번 인출하면 돈이 부족할 때까지 내리기

인터넷 참고
    가능한 인출 범위(최소 이용금액~모든 금액의 합)에서 파라메트릭 서치

수정1
    파라메트릭 서치 범위를 (최대 이용금액, 모든 금액의 합)으로 변경
    최대 이용 금액보다 k가 작으면, 지문에 따르면 남은 돈을 넣고 다시 k를 꺼내는 일을 무한히 반복하게 된다.

정답 보고 개선
    return true기본값으로 두고 cnt가 m보다 커지는 순간 더 볼 필요 없으므로 return false
*/

/* 시간복잡도
O(N * lg10000N)
*/
int arr[MAX], n, m;

bool isAcceptable(int k) //k원씩 꺼내면 총 n번 인출해도 되는가?
{
    int cnt = 0;
    int remain = 0;
    for (int i = 0; i < n; i++)
    {
        if (remain < arr[i])
        {
            cnt++;
            if (cnt > m) //정답 보고 개선
                return false;
            remain = k;
            // if (remain < arr[i]) 수정1
            //     return false;
        }
        remain -= arr[i];
    }
    // cout << "isAcceptable " << k << "  cnt: " << cnt << " " << m << endl;

    //수정1
    // if (cnt <= m) //m번 인출 or m번 미만 인출 => m 번 인출 가능
    //     return true;
    // return false;
    return true;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    int maxValue = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxValue = max(maxValue, arr[i]);
        sum += arr[i];
    }
    ///////////////////solution//////////////////
    int lo = maxValue, hi = sum;
    while (lo < hi)
    {
        // cout << lo << ' ' << hi << endl;
        int mid = (lo + hi) / 2;
        if (isAcceptable(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
        // cout << endl;
    }
    assert(lo == hi);
    cout << lo;
    ////////////////////output///////////////////

    return 0;
}
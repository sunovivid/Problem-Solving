#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 100'002
#define INF 987654321
using namespace std;

/* 문제 정의
길이 n 정수 수열 -> 연속부분수열의 최대합
 */

/* 해결 알고리즘 생각
isAccumulating정보가 필요없다
기존까지의 연속합 + 현재 수 < 현재 수 이면 연속합 새로 시작
sum(end) = end로 끝나는 연속합 중 최댓값
sum(end) = sum(end-1) > 0 ? sum(end-1) + a[end] : a[end] 
*/

/* 시간복잡도
O(n)
*/
int sum[MAX], maxSum;
vector<int> a;

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    ///////////////////solution//////////////////
    maxSum = sum[0] = a[0];
    for (int end = 1; end < a.size(); end++)
    {
        sum[end] = sum[end - 1] >= 0 ? sum[end - 1] + a[end] : a[end];
        maxSum = max(maxSum, sum[end]);
    }
    cout << maxSum;
    ////////////////////output///////////////////

    return 0;
}
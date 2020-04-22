#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1000000

using namespace std;

/* 문제 정의
k, 순열 -> (양쪽 대칭 원소 합이 일정) 만족하도록 변환 최소 횟수
 */

/* 해결 알고리즘 생각
a b 받아서 a + b, a, b 순으로 정렬
a + b = 
*/

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int testcase_num, n, k, arr[MAX];
    pair<int, pair<int, int>> pp[MAX];
    cin >> testcase_num;
    while (testcase_num--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n / 2; i++)
        {
            pp[i] = {arr[i] + arr[n - i - 1], {arr[i], arr[n - i - 1]}};
        }
        pp.
    }
    return 0;
}

/*legacy



*/
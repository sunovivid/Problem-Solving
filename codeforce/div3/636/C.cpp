#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <limits>

#define MAX

using namespace std;

/* 문제 정의
순열 -> 최대 길이 교대수열(+-+/-+-)의 최대 원소합
 */

/* 해결 알고리즘 생각
greedy하게 선택. 최장 길이 수열이므로 +- 바뀌면 무조건 선택
부호 바뀔 때까지 최댓값 갱신하면서 바뀌면 최댓값 더하기
sum = 0
prev = num[0]
maxval = prev
while (i = 1 to n)
    now = num[i]
    if (prev * now < 0)
        sum += maxval
        maxval = -INF
    maxval = max(maxval, now)
    prev = now
*/

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int testcase_num, n;
    long long sum, prev, now, maxval;
    cin >> testcase_num;
    while (testcase_num--)
    {
        sum = 0;
        cin >> n;
        cin >> prev;
        maxval = prev;
        n -= 1;
        while (n--)
        {
            cin >> now;
            if (prev * now < 0)
            {
                sum += maxval;
                maxval = LLONG_MIN;
            }
            maxval = max(now, maxval);
            prev = now;
        }
        sum += maxval;
        cout << sum << '\n';
    }
    return 0;
}

/*legacy



*/
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX

using namespace std;

/* 문제 정의
n -> 절반은 홀수, 절반은 짝수, 양쪽 원소합이 같은 배열
없으면 NO
 */

/* 해결 알고리즘 생각
2로 나눴을 때 홀수면 NO
아니면 YES
    2 4 6 .. n-2 n 순서대로 n/2개 출력
    1 3 5 .. n-3 순서대로 n-1개 출력, 마지막은 n-1 + n/2
*/

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int testcase_num, n;
    cin >> testcase_num;
    while (testcase_num--)
    {
        cin >> n;
        if ((n / 2) % 2 == 1)
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
            for (int i = 1; i <= n / 2; i++)
            {
                cout << i * 2 << ' ';
            }
            for (int i = 1; i <= n / 2 - 1; i++)
            {
                cout << i * 2 - 1 << ' ';
            }
            cout << n - 1 + n / 2 << '\n';
        }
    }

    return 0;
}

/*legacy



*/
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX

using namespace std;

/* 문제 정의
n -> x
x(1 + 2 + 4 + ...) =  n인 임의의 양수 x
n <= 10^9
 */

/* 해결 알고리즘 생각
x(2^a - 1) = n
x = n / (2^a - 1)

2중 for문
for (int i=2;;i<<2)
    for (int j=1;;j++)
        if ((i-1) * j == n)
            print j
            return
        elif ((i-1) * j > n)
            break;

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
        int x = 1;
        for (int i = 4;; i *= 2)
        {
            if (n % (i - 1) == 0)
            {
                cout << n / (i - 1) << '\n';
                break;
            }
        }
    }

    return 0;
}

/*legacy



*/
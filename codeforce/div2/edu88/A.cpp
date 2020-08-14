#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX

using namespace std;

/* 문제 정의
n, m, k ->  많은 조커 수가장
 */

/* 해결 알고리즘 생각
1등이 자기 몫을 그리디하게 가져감
나머지는 고르게 분배 (1장씩 번갈아 가져가기)
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t, m, n, k, remain;
    cin >> t;
    ///////////////////solution//////////////////
    while (t--)
    {
        cin >> n >> m >> k;
        if (m > n / k)
        {                       //조커 수가 플레이어 한명이 가질 수 있는 카드 수보다 많으면
            remain = m - n / k; //3
            if (remain % (k - 1) == 0)
                cout << n / k - remain / (k - 1);
            else
            {
                if (n / k == remain / (k - 1) + 1)
                    cout << 0;
                else
                    cout << n / k - remain / (k - 1) - 1;
            }
        }
        else
        { //적거나 같으면
            cout << m;
        }
        cout << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}

/*legacy



*/
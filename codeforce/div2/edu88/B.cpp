#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 1010

using namespace std;

/* 문제 정의
2차원 배열, 1x1블럭 가격, 1x2블럭 가격 -> 2칸씩 최소로 채우기
 */

/* 해결 알고리즘 생각

*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t, n, m, x, y, sum;
    char arr[MAX][MAX];
    cin >> t;
    ///////////////////solution//////////////////
    while (t--)
    {
        sum = 0;
        cin >> n >> m >> x >> y;
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++)
            cin >> &arr[i][0];
        if (x * 2 <= y)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (arr[i][j] == '.')
                        sum += x;
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (arr[i][j] == '*')
                    {
                        continue;
                    }
                    else if (arr[i][j] == '.' && arr[i][j + 1] == '.')
                    {
                        sum += y;
                        j++;
                    }
                    else
                    {
                        sum += x;
                    }
                }
            }
        }
        cout << sum << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}

/*legacy



*/